#include "stdafx.h"
#include "IUIRenderer.h"
#include "AllSettings.h"

/// <summary>
/// コンストラクタ
/// </summary>
IUIRenderer::IUIRenderer()
	: IRenderer()
	, _anchor(Anchor::TopLeft)
	, _uiX(0.0f)
	, _uiY(0.0f)
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
/// UI位置座標を設定
/// </summary>
/// <param name="x">X位置</param>
/// <param name="y">Y位置</param>
/// <returns>メソッドチェーン用</returns>
IUIRenderer* IUIRenderer::setUIPosition(float x, float y) {

	_uiX = x;
	_uiY = y;
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
/// UIの基準点を中央にするか設定
/// </summary>
/// <param name="center">trueで中央基準</param>
/// <returns>メソッドチェーン用</returns>
IUIRenderer* IUIRenderer::setCenter(bool center) {

	_isCenter = center;
	return this;
}

/// <summary>
/// 実際の画面座標を取得
/// </summary>
/// <param name="x">X位置</param>
/// <param name="y">Y位置</param>
void IUIRenderer::_GetScreenPosition(float& x, float& y) const {

	// アンカー基準点を取得
	float anchorX, anchorY;
	_GetAnchorPoint(anchorX, anchorY);

	// UI座標を加算
	x = anchorX + _uiX;
	y = anchorY + _uiY;
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
void IUIRenderer::_GetAnchorPoint(float& x, float& y) const {

	switch (_anchor) {

	case Anchor::TopLeft:
		x = 0.0f;
		y = 0.0f;
		break;

	case Anchor::TopCenter:
		x = WINDOW_WIDTH * 0.5f;
		y = 0.0f;
		break;

	case Anchor::TopRight:
		x = static_cast<float>(WINDOW_WIDTH);
		y = 0.0f;
		break;

	case Anchor::MiddleLeft:
		x = 0.0f;
		y = WINDOW_HEIGHT * 0.5f;
		break;

	case Anchor::Center:
		x = WINDOW_WIDTH * 0.5f;
		y = WINDOW_HEIGHT * 0.5f;
		break;

	case Anchor::MiddleRight:
		x = static_cast<float>(WINDOW_WIDTH);
		y = WINDOW_HEIGHT * 0.5f;
		break;

	case Anchor::BottomLeft:
		x = 0.0f;
		y = static_cast<float>(WINDOW_HEIGHT);
		break;

	case Anchor::BottomCenter:
		x = WINDOW_WIDTH * 0.5f;
		y = static_cast<float>(WINDOW_HEIGHT);
		break;

	case Anchor::BottomRight:
		x = static_cast<float>(WINDOW_WIDTH);
		y = static_cast<float>(WINDOW_HEIGHT);
		break;
	}
}