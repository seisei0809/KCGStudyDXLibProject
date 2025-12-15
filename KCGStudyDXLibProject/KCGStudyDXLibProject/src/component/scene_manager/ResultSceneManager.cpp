#include "stdafx.h"
#include "ResultSceneManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"

/// <summary>
/// 初期化時実行
/// </summary>
void ResultSceneManager::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void ResultSceneManager::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void ResultSceneManager::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void ResultSceneManager::destroy() {

}

/// <summary>
/// リトライする
/// </summary>
/// <param name="isRetry">リトライするか</param>
void ResultSceneManager::retry(bool isRetry) {

	if (isRetry) {

		SceneManager::getInstance().changeScene<GameScene>();
	}
}

/// <summary>
/// タイトルに戻る
/// </summary>
/// <param name="isTitle">タイトルに戻るか</param>
void ResultSceneManager::tilteBack(bool isTitle) {

	if (isTitle) {

		SceneManager::getInstance().changeScene<TitleScene>();
	}
}