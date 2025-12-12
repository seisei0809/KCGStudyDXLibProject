#include "stdafx.h"
#include "ModelCacheManager.h"

using namespace Utility;

/// <summary>
/// コンストラクタ
/// </summary>
ModelCacheManager::ModelCacheManager()
	:_modelCache() {

}

/// <summary>
/// デストラクタ
/// </summary>
ModelCacheManager::~ModelCacheManager() {

	clearCache();
}

/// <summary>
/// モデルを取得または読み込む
/// </summary>
/// <param name="filePath">モデルファイルパス</param>
/// <returns>複製されたモデルハンドル（-1は失敗）</returns>
int ModelCacheManager::getModel(const std::wstring& filePath) {

	for (auto it = _modelCache.begin(); it != _modelCache.end(); it++) {

		// ファイルパスが一致するか確認
		if ((*it).filePath == filePath) {

			// キャッシュに存在する場合は複製を作成
			(*it).refCount++;
			int duplicateHandle = MV1DuplicateModel((*it).originalHandle);
			return duplicateHandle;
		}
	}

	// 新規読み込み
	int originalHandle = MV1LoadModel(filePath.c_str());

	if (originalHandle == -1) return -1;

	// キャッシュに追加
	CacheEntry entry;
	entry.filePath = filePath;
	entry.originalHandle = originalHandle;
	entry.refCount = 1;
	_modelCache.emplace_back(entry);

	// 複製を返す
	int duplicateHandle = MV1DuplicateModel(originalHandle);
	return duplicateHandle;
}

/// <summary>
/// モデルを解放する
/// </summary>
/// <param name="filePath">モデルファイルパス</param>
/// <param name="modelHandle">解放するモデルハンドル</param>
void ModelCacheManager::releaseModel(const std::wstring& filePath, int modelHandle) {

	if (modelHandle == -1) return;

	// 複製ハンドルを削除
	MV1DeleteModel(modelHandle);

	for (auto it = _modelCache.begin(); it != _modelCache.end(); it++) {

		// ファイルパスが一致するか確認
		if ((*it).filePath != filePath) continue;

		// 参照カウントを減らす
		(*it).refCount--;
		// 参照カウントが0になったらキャッシュから削除
		if ((*it).refCount <= 0) {

			MV1DeleteModel((*it).originalHandle);
			_modelCache.erase(it);
		}
		return;
	}
}

/// <summary>
/// 全キャッシュをクリア
/// </summary>
void ModelCacheManager::clearCache() {

	for (auto& cache : _modelCache) {

		if (cache.originalHandle != -1) {

			MV1DeleteModel(cache.originalHandle);
		}
	}
	_modelCache.clear();
}