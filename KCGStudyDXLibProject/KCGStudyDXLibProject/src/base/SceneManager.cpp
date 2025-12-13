#include "stdafx.h"
#include "SceneManager.h"
#include "GameObjectManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
SceneManager::SceneManager()
	:_nowScene(),
	_GetChangeSceneInstance(),
	_isChange(false){

}

/// <summary>
/// シーン更新
/// </summary>
void SceneManager::updateScene() {

	// シーン変更がある場合
	if (_isChange && _GetChangeSceneInstance) {
		
		// 全てのゲームオブジェクトを破棄
		GameObjectManager::getInstance().destroyAllGameObject();

		// 現在のシーンを終了
		endScene();

		// 新しいシーンの開始
		_nowScene = _GetChangeSceneInstance();
		_nowScene->SetGameObject();
		_isChange = false;
	}
}

/// <summary>
/// 現在のシーンを取得する
/// </summary>
/// <returns></returns>
IScene* SceneManager::getNowScene() {

	return _nowScene;
}

/// <summary>
/// シーンを終わらせる
/// </summary>
void SceneManager::endScene() {

	if (_nowScene) {

		delete _nowScene;
	}
}