#include "stdafx.h"
#include "EnemyBullet.h"
#include "player/PlayerLifeManager.h"
#include "GameObjectManager.h"
#include "TimeManager.h"
#include "collider/AABBCollider.h"

using namespace Utility;
using namespace AllEnumSpace;

/// <summary>
/// コンストラクタ
/// </summary>
EnemyBullet::EnemyBullet()
	:_speed(0.0f),
	_direction(VGet(0.0f, 0.0f, 0.0f)),
	_lifeTime(0.0f),
	_elapsedTime(0.0f),
	_collider(nullptr) {

}

/// <summary>
/// 初期化時実行
/// </summary>
void EnemyBullet::start() {

	_collider = _gameObject->getComponent<AABBCollider>()
		->setOnCollisionEnterEvent(this, &EnemyBullet::Attack);
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void EnemyBullet::update() {

	_elapsedTime += static_cast<float>(TimeManager::deltaTime());

	// 時間になったら消す
	if (_elapsedTime >= _lifeTime) {

		GameObjectManager::getInstance().destroyGameObject(this->getGameObject());
		return;
	}
}

/// <summary>
/// 固定間隔で実行
/// </summary>
void EnemyBullet::fixedUpdate() {

	// 位置更新
	auto position = _gameObject->getTransform().position;
	position = VAdd(position, VScale(_direction, _speed * static_cast<float>(TimeManager::fixedDeltaTime())));
	_gameObject->getTransform().position = position;
}

/// <summary>
/// 破棄時実行
/// </summary>
void EnemyBullet::destroy() {

	_collider->destroyOnCollisionEnterEvent(this, &EnemyBullet::Attack);
}

/// <summary>
/// スピードをセットする
/// </summary>
/// <param name="speed">スピード</param>
/// <returns></returns>
EnemyBullet* EnemyBullet::setSpeed(float speed) {

	_speed = speed;
	return this;
}

/// <summary>
/// 方向をセットする
/// </summary>
/// <param name="dir"></param>
/// <returns></returns>
EnemyBullet* EnemyBullet::setDirection(VECTOR dir) {

	_direction = dir;
	return this;
}

/// <summary>
/// 生存時間のセット
/// </summary>
/// <param name="time">時間</param>
/// <returns>メソッドチェーン用</returns>
EnemyBullet* EnemyBullet::setLifeTime(float time) {

	_lifeTime = time;
	return this;
}

/// <summary>
/// 呼ばれたら攻撃処理
/// </summary>
/// <param name="collider"></param>
void EnemyBullet::Attack(ICollider* collider) {

	// プレイヤーなら攻撃処理
	if (collider->getGameObject()->getTag() == Tag::Player) {

		// ライフを減らす
		collider->getGameObject()->getComponent<PlayerLifeManager>()->minusLife();
	}
	if (collider->getGameObject()->getTag() == Tag::Bullet)return;
	// 弾以外に当たったら自分を消す
	GameObjectManager::getInstance().destroyGameObject(this->getGameObject());
}