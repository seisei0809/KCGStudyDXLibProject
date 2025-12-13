#pragma once
#include "Singleton.h"

/// <summary>
/// ゲーム全体管理
/// </summary>
class GameManager : public Utility::Singleton<GameManager>{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameManager();

	/// <summary>
	/// ゲームが終了したか
	/// </summary>
	/// <returns>終了していたらtrue</returns>
	bool isGameEnd();

	/// <summary>
	/// ゲームを終了する
	/// </summary>
	void endGame();

private:

	// ゲームの状態
	bool _isGameEnd;
};

