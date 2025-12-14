#pragma once
#include "IComponent.h"
#include "renderer/ui/UIText.h"

/// <summary>
/// ゲームシーンのタイマー
/// </summary>
class GameTimer : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameTimer();

	/// <summary>
	/// 初期化時実行
	/// </summary>
	void start() override;

	/// <summary>
	/// 毎フレーム実行
	/// </summary>
	void update() override;

	/// <summary>
	/// 固定間隔で実行
	/// </summary>
	void fixedUpdate() override;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	void destroy() override;

private:

	// 表示用UIテキスト
	UIText* _uiText;
};

