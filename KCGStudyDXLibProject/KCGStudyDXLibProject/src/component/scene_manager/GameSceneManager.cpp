#include "stdafx.h"
#include "GameSceneManager.h"
#include "SceneManager.h"
#include "ResultScene.h"
#include "result/ResultParameter.h"

/// <summary>
/// 初期化時実行
/// </summary>
void GameSceneManager::start() {

	// ゲーム開始時にリザルトパラメータをリセット
	ResultParameter::reset();
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void GameSceneManager::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void GameSceneManager::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void GameSceneManager::destroy() {

}

/// <summary>
/// ゲームシーンを終わらせる
/// </summary>
void GameSceneManager::endGameScene() {

	// リザルトに移る
	SceneManager::getInstance().changeScene<ResultScene>();
}