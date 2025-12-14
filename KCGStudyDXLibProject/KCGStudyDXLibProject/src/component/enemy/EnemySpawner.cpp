#include "stdafx.h"
#include "EnemySpawner.h"
#include "AllSettings.h"
#include "TimeManager.h"
#include "renderer/Model3D.h"
#include "EnemyManager.h"
#include "GameObjectManager.h"
#include "player/PlayerManager.h"
#include "GameObject.h"

using namespace Utility;

/// <summary>
/// コンストラクタ
/// </summary>
EnemySpawner::EnemySpawner()
	:_spawnDuration(1.0f),
	_elapsedTime(0.0f) {

}

/// <summary>
/// 初期化時実行
/// </summary>
void EnemySpawner::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void EnemySpawner::update() {

	_elapsedTime += static_cast<float>(TimeManager::deltaTime());

	if (_elapsedTime >= _spawnDuration) {

		_elapsedTime = 0.0f;

		// 型で探す
		GameObject* _playerObj = GameObjectManager::getInstance().getGameObjectByType<PlayerManager>();
		// 範囲からランダムに位置決定
		float x = ENEMY_SPAWN_RANGE_MIN.x +
			(ENEMY_SPAWN_RANGE_MAX.x - ENEMY_SPAWN_RANGE_MIN.x)
			* (GetRand(10000) / 10000.0f);

		float y = ENEMY_SPAWN_RANGE_MIN.y +
			(ENEMY_SPAWN_RANGE_MAX.y - ENEMY_SPAWN_RANGE_MIN.y)
			* (GetRand(10000) / 10000.0f);

		float z = ENEMY_SPAWN_RANGE_MIN.z +
			(ENEMY_SPAWN_RANGE_MAX.z - ENEMY_SPAWN_RANGE_MIN.z)
			* (GetRand(10000) / 10000.0f);

		// スポーン処理
		GameObject::Builder()
			.build()
			->setPosition(VGet(x,y,z))
			->setScale(ENEMY_DEFAULT_SCALE)->addComponent<Model3D>()
			->loadModel(ENEMY_MODEL_PATH)
			->getGameObject()->addComponent<EnemyManager>()
			->setShotDuration(ENEMY_SHOT_DURATION)
			->setPlayerTransform(_playerObj->getTransform());
	}
}

/// <summary>
/// 固定間隔で実行
/// </summary>
void EnemySpawner::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void EnemySpawner::destroy() {

}

/// <summary>
/// スポーン間隔のセット
/// </summary>
/// <param name="duration">間隔</param>
/// <returns>メソッドチェーン用</returns>
EnemySpawner* EnemySpawner::setSpawnDuration(float duration) {

	_spawnDuration = duration;
	return this;
}