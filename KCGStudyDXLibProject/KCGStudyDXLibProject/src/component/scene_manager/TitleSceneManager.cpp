#include "stdafx.h"
#include "TitleSceneManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "ResultScene.h"

/// <summary>
/// 初期化時実行
/// </summary>
void TitleSceneManager::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void TitleSceneManager::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void TitleSceneManager::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void TitleSceneManager::destroy() {

}

/// <summary>
/// ゲームを終了させる
/// </summary>
/// <param name="isEnd">終了させるか</param>
void TitleSceneManager::endGame(bool isEnd) {

	if (isEnd) {

		// ゲーム終了処理
		GameManager::getInstance().endGame();
	}
}

/// <summary>
/// ゲームを開始させる
/// </summary>
/// <param name="isStart">開始させるか</param>
void TitleSceneManager::startGame(bool isStart) {

	if (isStart) {

		// ゲーム開始処理
		SceneManager::getInstance().changeScene<ResultScene>();
	}
}