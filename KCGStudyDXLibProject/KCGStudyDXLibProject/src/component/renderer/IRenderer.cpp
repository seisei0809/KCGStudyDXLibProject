#include "stdafx.h"
#include "IRenderer.h"
#include "RendererManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
IRenderer::IRenderer()
	:_layer(0){

	// RendererManagerに登録
	RendererManager::getInstance().addRenderer(this);
}

/// <summary>
/// デストラクタ
/// </summary>
IRenderer::~IRenderer() {

	// RendererManagerから破棄
	RendererManager::getInstance().destroyRenderer(this);
}

/// <summary>
/// レイヤーをセットする
/// </summary>
/// <param name="layer">レイヤー</param>
/// <returns>メソッドチェーン用</returns>
IRenderer* IRenderer::setLayer(int layer) {

	_layer = layer;
	return this;
}

/// <summary>
/// レイヤーを取得する
/// </summary>
int IRenderer::getLayer() const {

	return _layer;
}