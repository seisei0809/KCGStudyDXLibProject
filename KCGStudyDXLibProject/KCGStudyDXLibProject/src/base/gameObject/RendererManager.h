#pragma once
#include "Singleton.h"
#include "renderer/IRenderer.h"

/// <summary>
/// 描画管理
/// </summary>
class RendererManager : public Utility::Singleton<RendererManager>{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	RendererManager();

	/// <summary>
	/// 全て描画
	/// </summary>
	const void allRender()const;
	
	/// <summary>
	/// レンダラーを追加する
	/// </summary>
	/// <param name="renderer">レンダラー</param>
	void addRenderer(IRenderer* renderer);

	/// <summary>
	/// レンダラーを破棄する
	/// </summary>
	/// <param name="renderer">レンダラー</param>
	void destroyRenderer(IRenderer* renderer);

private:

	// レンダラー配列
	std::vector<IRenderer*> _renders;

};

