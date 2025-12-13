#pragma once
#include "renderer/IRenderer.h"
#include "AllEnum.h"

/// <summary>
/// UI描画基底（画面比率対応・回転対応）
/// </summary>
class IUIRenderer : public IRenderer {
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	IUIRenderer();

	/// <summary>
	/// アンカー設定
	/// </summary>
	/// <param name="anchor">アンカー列挙</param>
	/// <returns>メソッドチェーン用</returns>
	IUIRenderer* setAnchor(AllEnumSpace::Anchor anchor);

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

protected:

	/// <summary>
	/// 実際の画面座標を取得
	/// </summary>
	/// <param name="x">X位置</param>
	/// <param name="y">Y位置</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	void _GetScreenPosition(float& x, float& y, float width, float height) const;

	/// <summary>
	/// 回転角度をラジアンで取得
	/// </summary>
	float _GetRotationRadian() const;

	/// <summary>
	/// アンカー基準点を取得
	/// </summary>
	/// <param name="x">X位置</param>
	/// <param name="y">Y位置</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	void _GetAnchorPoint(float& x, float& y, float width, float height) const;

	// アンカー位置
	AllEnumSpace::Anchor _anchor;
	// UIスケール
	float _uiScale;
	// 回転角度(度数法)
	float _rotation;
};