#include "stdafx.h"
#include "GameManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameManager::GameManager()
	:_isGameEnd() {

}

/// <summary>
/// ゲームが終了したか
/// </summary>
/// <returns>終了していたらtrue</returns>
bool GameManager::isGameEnd() {

	return _isGameEnd;
}

/// <summary>
/// ゲームを終了する
/// </summary>
void GameManager::endGame() {

	_isGameEnd = true;
}
