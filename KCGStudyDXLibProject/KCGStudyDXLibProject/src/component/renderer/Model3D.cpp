#include "stdafx.h"
#include "Model3D.h"
#include "ModelCacheManager.h"

using namespace Utility;

/// <summary>
/// コンストラクタ
/// </summary>
Model3D::Model3D()
	:_modelHandle(-1),
	_modelFilePath(L"") {

}

/// <summary>
/// モデルファイルを読み込む
/// </summary>
/// <param name="filePath">モデルファイルパス</param>
	/// <returns>メソッドチェーン用</returns>
Model3D* Model3D::loadModel(const std::wstring& filePath) {

	auto& manager = ModelCacheManager::getInstance();

	// 既に読み込まれている場合は削除
	if (_modelHandle != -1) {

		manager.releaseModel(filePath, _modelHandle);
		_modelHandle = -1;
	}

	// モデルを読み込む
	_modelHandle = manager.getModel(filePath);
	_modelFilePath = filePath;
	return this;
}

/// <summary>
/// モデルハンドルを取得する
/// </summary>
int Model3D::getModelHandle() const {

	return _modelHandle;
}

/// <summary>
/// 初期化時実行
/// </summary>
void Model3D::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void Model3D::update() {

	if (_modelHandle == -1)return;

	// GameObjectのTransform情報を取得
	Transform& transform = getGameObject()->getTransform();

	// モデルの位置を設定
	MV1SetPosition(_modelHandle, transform.position);

	// モデルの回転を設定
	MV1SetRotationXYZ(_modelHandle, transform.rotation);

	// モデルのスケールを設定
	MV1SetScale(_modelHandle, transform.scale);
}

/// <summary>
/// 固定間隔で実行
/// </summary>
void Model3D::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void Model3D::destroy() {

	// モデルを削除
	if (_modelHandle != -1) {

		ModelCacheManager::getInstance().releaseModel(_modelFilePath,_modelHandle);
		_modelHandle = -1;
	}
}

/// <summary>
/// 描画実行
/// </summary>
void Model3D::render() {

	if (_modelHandle != -1) {

		// モデルを描画
		MV1DrawModel(_modelHandle);
	}
}