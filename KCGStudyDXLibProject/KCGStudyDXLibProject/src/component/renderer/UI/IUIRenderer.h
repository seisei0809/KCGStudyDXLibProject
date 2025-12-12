#pragma once
#include "renderer/IRenderer.h"

/// <summary>
/// UI描画基底（画面比率対応・回転対応）
/// </summary>
class IUIRenderer : public IRenderer {
public:

	/// <summary>
	/// アンカー位置
	/// </summary>
	enum class Anchor {
		TopLeft,       // 左上
		TopCenter,     // 上中央
		TopRight,      // 右上
		MiddleLeft,    // 左中央
		Center,        // 中央
		MiddleRight,   // 右中央
		BottomLeft,    // 左下
		BottomCenter,  // 下中央
		BottomRight    // 右下
	};

	/// <summary>
	/// コンストラクタ
	/// </summary>
	IUIRenderer();

	/// <summary>
	/// アンカー設定
	/// </summary>
	/// <param name="anchor">アンカー列挙</param>
	/// <returns>メソッドチェーン用</returns>
	IUIRenderer* setAnchor(Anchor anchor);

	/// <summary>
	/// UI位置座標を設定
	/// </summary>
	/// <param name="x">X位置</param>
	/// <param name="y">Y位置</param>
	/// <returns>メソッドチェーン用</returns>
	IUIRenderer* setUIPosition(float x, float y);

	/// <summary>
	/// UIスケールを設定
	/// </summary>
	/// <param name="scale">スケール</param>
	/// <returns>メソッドチェーン用</returns>
	IUIRenderer* setUIScale(float scale);

	/// <summary>
	/// 回転角度を設定(度数法)
	/// </summary>
	/// <param name="degrees">度数</param>
	/// <returns>メソッドチェーン用</returns>
	IUIRenderer* setRotation(float degrees);

	/// <summary>
	/// UIの基準点を中央にするか設定
	/// </summary>
	/// <param name="center">trueで中央基準</param>
	/// <returns>メソッドチェーン用</returns>
	IUIRenderer* setCenter(bool center);

protected:

	/// <summary>
	/// 実際の画面座標を取得
	/// </summary>
	/// <param name="x">X位置</param>
	/// <param name="y">Y位置</param>
	void _GetScreenPosition(float& x, float& y) const;

	/// <summary>
	/// 回転角度をラジアンで取得
	/// </summary>
	float _GetRotationRadian() const;

	// アンカー位置
	Anchor _anchor;
	// UIのX位置
	float _uiX;
	// UIのY位置
	float _uiY;
	// UIスケール
	float _uiScale;
	// 回転角度(度数法)
	float _rotation;	
	// 中央基準にするかどうか
	bool _isCenter = false;


private:

	/// <summary>
	/// アンカー基準点を取得
	/// </summary>
	/// <param name="x">X位置</param>
	/// <param name="y">Y位置</param>
	void _GetAnchorPoint(float& x, float& y) const;
};