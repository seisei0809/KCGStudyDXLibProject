#include "stdafx.h"
#include "GameObjectManager.h"
#include "TimeManager.h"
#include "ColliderManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameObjectManager::GameObjectManager()
	:_gameObjects(),
	_addGameObjects(),
	_destroyGameObjects(),
	_fixedUpdateCumulativeTime(0.0f) {

}

/// <summary>
/// 全てのゲームオブジェクトの更新
/// </summary>
void GameObjectManager::allUpdate() {

	_UpdateGameObjectArray();

	for (auto& gameObject : _gameObjects) {

		gameObject->update();
	}

	_UpdateGameObjectArray();
}

/// <summary>
/// 全てのゲームオブジェクトの固定更新
/// </summary>
void GameObjectManager::allFixedUpdate() {

	using namespace Utility;

	// 経過時間を累積
	_fixedUpdateCumulativeTime += TimeManager::deltaTime();;

	double fixedDeltaTime = TimeManager::fixedDeltaTime();

	// fixedDeltaTime間隔で実行
	while (_fixedUpdateCumulativeTime >= fixedDeltaTime) {

		_UpdateGameObjectArray();

		// 全GameObjectのfixedUpdateを呼ぶ
		for (auto& gameObject : _gameObjects) {

			gameObject->fixedUpdate();
		}

		// コライダー更新
		ColliderManager::getInstance().updateCollider();

		_UpdateGameObjectArray();

		// 累積時間を減らす
		_fixedUpdateCumulativeTime -= fixedDeltaTime;
	}
}

/// <summary>
/// ゲームオブジェクトを追加する
/// </summary>
/// <param name="gameObject">ゲームオブジェクト</param>
void GameObjectManager::addGameObject(GameObject* gameObject) {

	_addGameObjects.emplace_back(gameObject);
}

/// <summary>
/// ゲームオブジェトを破棄する
/// </summary>
/// <param name="gameObject">ゲームオブジェクト</param>
void GameObjectManager::destroyGameObject(GameObject* gameObject) {

	_destroyGameObjects.emplace_back(gameObject);
}

/// <summary>
/// 全てのゲームオブジェクトを破棄する
/// </summary>
void GameObjectManager::destroyAllGameObject() {

	for (auto& gameObject : _gameObjects) {

		// destroy呼び出してから破棄して削除
		gameObject->destroy();
		delete gameObject;
	}
	_gameObjects.clear();

	for (auto& gameObject : _addGameObjects) {

		// destroy呼び出してから破棄して削除
		gameObject->destroy();
		delete gameObject;
	}
	_addGameObjects.clear();

	_destroyGameObjects.clear();
}

/// <summary>
/// ゲームオブジェクト配列の更新
/// </summary>
void GameObjectManager::_UpdateGameObjectArray() {

	// 追加処理
	for (auto& obj : _addGameObjects) {

		_gameObjects.emplace_back(obj);

		// 追加したらstart呼び出し
		obj->start();
	}
	_addGameObjects.clear();

	// 破棄処理
	for (auto& obj : _destroyGameObjects) {

		for (auto it = _gameObjects.begin(); it != _gameObjects.end(); it++) {

			if (*it != obj)continue;

			// destroy呼んで破棄して削除
			obj->destroy();
			delete* it;
			_gameObjects.erase(it);
			break;
		}
	}
	_destroyGameObjects.clear();
}