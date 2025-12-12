#pragma once
#include "IComponent.h"

/// <summary>
/// 描画基底
/// </summary>
class IRenderer : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	IRenderer();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~IRenderer();

	/// <summary>
	/// 描画実行
	/// </summary>
	virtual void render() = 0;

	/// <summary>
	/// レイヤーをセットする
	/// </summary>
	/// <param name="layer">レイヤー</param>
	/// <returns>メソッドチェーン用</returns>
	IRenderer* setLayer(int layer);

	/// <summary>
	/// レイヤーを取得する
	/// </summary>
	int getLayer() const;

private:

	// レイヤー
	int _layer;
};

