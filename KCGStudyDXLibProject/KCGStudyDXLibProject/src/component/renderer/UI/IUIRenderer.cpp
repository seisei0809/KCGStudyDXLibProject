#include "stdafx.h"
#include "IUIRenderer.h"
#include "AllSettings.h"

using namespace AllEnumSpace;

/// <summary>
/// コンストラクタ
/// </summary>
IUIRenderer::IUIRenderer()
	: IRenderer()
	, _anchor(Anchor::TopLeft)
	, _uiScale(1.0f)
	, _rotation(0.0f){

}

/// <summary>
/// アンカー設定
/// </summary>
/// <param name="anchor">アンカー列挙</param>
/// <returns>メソッドチェーン用</returns>
IUIRenderer* IUIRenderer::setAnchor(Anchor anchor) {

	_anchor = anchor;
	return this;
}

/// <summary>
/// UIスケールを設定
/// </summary>
/// <param name="scale">スケール</param>
/// <returns>メソッドチェーン用</returns>
IUIRenderer* IUIRenderer::setUIScale(float scale) {

	_uiScale = scale;
	return this;
}

/// <summary>
/// 回転角度を設定(度数法)
/// </summary>
/// <param name="degrees">度数</param>
/// <returns>メソッドチェーン用</returns>
IUIRenderer* IUIRenderer::setRotation(float degrees) {

	_rotation = degrees;
	return this;
}

/// <summary>
/// 実際の画面座標を取得
/// </summary>
/// <param name="x">X位置</param>
/// <param name="y">Y位置</param>
/// <param name="width">幅</param>
/// <param name="height">高さ</param>
void IUIRenderer::_GetScreenPosition(float& x, float& y,float width,float height) const {

	// アンカー基準点を取得
	float anchorX, anchorY;
	_GetAnchorPoint(anchorX, anchorY,width,height);

	// UI座標を加算
	x = anchorX + _gameObject->getTransform().position.x;
	y = anchorY + _gameObject->getTransform().position.y;
}

/// <summary>
/// 回転角度をラジアンで取得
/// </summary>
float IUIRenderer::_GetRotationRadian() const {

	// 度数法からラジアンに変換
	return _rotation * DX_PI_F / 180.0f;
}

/// <summary>
/// アンカー基準点を取得
/// </summary>
/// <param name="x">X位置</param>
/// <param name="y">Y位置</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
void IUIRenderer::_GetAnchorPoint(float& x, float& y, float width, float height) const {

	// 現在のウィンドウサイズを取得
	int windowWidth, windowHeight;
	GetWindowSize(&windowWidth, &windowHeight);

	switch (_anchor) {

	case Anchor::TopLeft:
		x = width * 0.5f;
		y = height * 0.5f;
		break;

	case Anchor::TopCenter:
		x = windowWidth * 0.5f;
		y = 0.0f;
		break;

	case Anchor::TopRight:
		x = windowWidth - width * 0.5f;
		y = height * 0.5f;
		break;

	case Anchor::MiddleLeft:
		x = width * 0.5f;
		y = windowHeight * 0.5f - height * 0.5f;
		break;

	case Anchor::MiddleCenter:
		x = windowWidth * 0.5f;
		y = windowHeight * 0.5f - height * 0.5f;
		break;

	case Anchor::MiddleRight:
		x = windowWidth - width * 0.5f;
		y = windowHeight * 0.5f - height * 0.5f;
		break;

	case Anchor::BottomLeft:
		x = width * 0.5f;
		y = windowHeight - height * 0.5f;
		break;

	case Anchor::BottomCenter:
		x = windowWidth * 0.5f;
		y = windowHeight - height * 0.5f;
		break;

	case Anchor::BottomRight:
		x = windowWidth - width * 0.5f;
		y = windowHeight - height * 0.5f;
		break;
	}
}