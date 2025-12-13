#pragma once
#include "IComponent.h"

/// <summary>
/// タイトルシーン管理
/// </summary>
class TitleSceneManager:public IComponent{
public:

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

	/// <summary>
	/// ゲームを終了させる
	/// </summary>
	/// <param name="isEnd">終了させるか</param>
	void endGame(bool isEnd);

	/// <summary>
	/// ゲームを開始させる
	/// </summary>
	/// <param name="isStart">開始させるか</param>
	void startGame(bool isStart);
};

