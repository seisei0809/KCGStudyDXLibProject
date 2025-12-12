#pragma once
#include "Singleton.h"

namespace Utility {

	/// <summary>
	/// モデルキャッシュ管理
	/// </summary>
	class ModelCacheManager : public Singleton<ModelCacheManager> {
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		ModelCacheManager();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ModelCacheManager();

		/// <summary>
		/// モデルを取得または読み込む
		/// </summary>
		/// <param name="filePath">モデルファイルパス</param>
		/// <returns>複製されたモデルハンドル（-1は失敗）</returns>
		int getModel(const std::wstring& filePath);

		/// <summary>
		/// モデルを解放する
		/// </summary>
		/// <param name="filePath">モデルファイルパス</param>
		/// <param name="modelHandle">解放するモデルハンドル</param>
		void releaseModel(const std::wstring& filePath, int modelHandle);

		/// <summary>
		/// 全キャッシュをクリア
		/// </summary>
		void clearCache();

	private:

		/// <summary>
		/// キャッシュ情報
		/// </summary>
		struct CacheEntry {

			// ファイルパス
			std::wstring filePath;
			// オリジナルハンドル
			int originalHandle = -1; 
			// 参照カウント
			int refCount = 0;
		};

		// モデルキャッシュ
		std::vector<CacheEntry> _modelCache;
	};
}