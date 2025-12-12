#include "stdafx.h"
#include "UIImage.h"

/// <summary>
/// コンストラクタ
/// </summary>
UIImage::UIImage()
	: IUIRenderer()
	, _imageHandle(-1)
	, _isOwnImage()
	, _imageWidth()
	, _imageHeight() {

}

/// <summary>
/// 画像を読み込む
/// </summary>
/// <returns>メソッドチェーン用</returns>
UIImage* UIImage::loadImage(const std::wstring& filePath) {

	// 既存の画像を削除
	if (_isOwnImage && _imageHandle != -1) {

		DeleteGraph(_imageHandle);
		_imageHandle = -1;
	}

	// 画像を読み込む
	_imageHandle = LoadGraph(filePath.c_str());
	if (_imageHandle != -1) {

		// 自分で読み込んだことにする
		_isOwnImage = true;

		// 画像の元サイズを取得
		GetGraphSize(_imageHandle, &_imageWidth, &_imageHeight);
	}

	return this;
}

/// <summary>
/// 画像ハンドルを設定
/// </summary>
/// <returns>メソッドチェーン用</returns>
UIImage* UIImage::setImageHandle(int handle) {

	// 既存の画像を削除
	if (_isOwnImage && _imageHandle != -1) {
		DeleteGraph(_imageHandle);
	}
	_imageHandle = handle;
	_isOwnImage = false;

	if (handle != -1) {

		GetGraphSize(_imageHandle, &_imageWidth, &_imageHeight);
	}
	return this;
}

/// <summary>
/// 初期化時実行
/// </summary>
void UIImage::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void UIImage::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void UIImage::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void UIImage::destroy() {

	if (_isOwnImage && _imageHandle != -1) {
		DeleteGraph(_imageHandle);
		_imageHandle = -1;
		_isOwnImage = false;
	}
}

/// <summary>
/// 描画実行
/// </summary>
void UIImage::render() {

	if (_imageHandle == -1) return;

	// 画面座標を取得
	float screenX, screenY;
	_GetScreenPosition(screenX, screenY);

	// 回転角度を取得
	float rotationRad = _GetRotationRadian();

	float offsetX = 0.0f;
	float offsetY = 0.0f;
	// 中心なら中心にオフセット
	if (_isCenter) {

		offsetX = _imageWidth / 2.0f;
		offsetY = _imageHeight / 2.0f;
	}

	// 回転ありで拡大描画
	DrawRotaGraph3(
		static_cast<int>(screenX),
		static_cast<int>(screenY),
		offsetX, offsetY,
		_uiScale,
		_uiScale,
		rotationRad,
		_imageHandle,
		TRUE
	);
}