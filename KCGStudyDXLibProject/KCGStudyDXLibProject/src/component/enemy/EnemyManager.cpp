#include "stdafx.h"
#include "EnemyManager.h"
#include "AllSettings.h"

/// <summary>
/// コンストラクタ
/// </summary>
EnemyManager::EnemyManager()
	:_duration(1.0f),
	_playerTransform(),
	_shooter(){

}

/// <summary>
/// 初期化時実行
/// </summary>
void EnemyManager::start() {

	_shooter = new EnemyShooter();
	_shooter->setDuration(_duration)
		->setShotPos(_gameObject->getTransform().position)
		->setShotBulletPath(BULLET_MODEL_PATH)
		->setPlayerTransform(_playerTransform);
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void EnemyManager::update() {

	_shooter->shotLoop();
}

/// <summary>
/// 固定間隔で実行
/// </summary>
void EnemyManager::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void EnemyManager::destroy() {

	delete _shooter;
}

/// <summary>
/// 発射間隔を設定する
/// </summary>
/// <param name="duration">間隔</param>
/// <returns>メソッドチェーン用</returns>
EnemyManager* EnemyManager::setShotDuration(float duration) {

	_duration = duration;
	return this;
}

/// <summary>
/// プレイヤーのTransformをセットする
/// </summary>
/// <param name="tr">transform</param>
/// <returns>メソッドチェーン用</returns>
EnemyManager* EnemyManager::setPlayerTransform(Transform& tr) {

	_playerTransform = &tr;
	return this;
}