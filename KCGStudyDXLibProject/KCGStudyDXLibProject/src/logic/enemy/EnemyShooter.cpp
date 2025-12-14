#include "stdafx.h"
#include "EnemyShooter.h"
#include "AllSettings.h"
#include "TimeManager.h"
#include "GameObject.h"
#include "renderer/Model3D.h"
#include "enemy/EnemyBullet.h"
#include "collider/AABBCollider.h"

using namespace Utility;
using namespace AllEnumSpace;

/// <summary>
/// コンストラクタ
/// </summary>
EnemyShooter::EnemyShooter()
	:_duration(1.0f),
	_shotPos(VGet(0.0f, 0.0f, 0.0f)),
	_shotBulletPath(L""),
	_elapsedTime(0.0f),
	_playerTransform(){
}


/// <summary>
/// 発射間隔のセット
/// </summary>
/// <param name="duration">間隔</param>
/// <returns>メソッドチェーン用</returns>
EnemyShooter* EnemyShooter::setDuration(float duration) {

	_duration = duration;
	return this;
}

/// <summary>
/// 発射する位置をセットする
/// </summary>
/// <param name="pos">位置</param>
/// <returns>メソッドチェーン用</returns>
EnemyShooter* EnemyShooter::setShotPos(const VECTOR& pos) {

	_shotPos = pos;
	return this;
}

/// <summary>
/// 発射する弾のパスをセットする
/// </summary>
/// <param name="path">パス</param>
/// <returns>メソッドチェーン用</returns>
EnemyShooter* EnemyShooter::setShotBulletPath(const wchar_t* path) {

	_shotBulletPath = path;
	return this;
}

/// <summary>
/// プレイヤーのTransformをセットする
/// </summary>
/// <param name="transform">transform</param>
/// <returns>メソッドチェーン用</returns>
EnemyShooter* EnemyShooter::setPlayerTransform(Transform* transform) {

	_playerTransform = transform;
	return this;
}

/// <summary>
/// ループでこの関数を呼ぶ
/// </summary>
void EnemyShooter::shotLoop() {

	_elapsedTime += static_cast<float>(TimeManager::deltaTime());

	if(_elapsedTime >= _duration) {

		// 発射方向を計算
		VECTOR dir = VSub(_playerTransform->position, _shotPos);
		float len = VSize(dir);
		if (len > 0.0f) {

			dir = VScale(dir, 1.0f / len);
		}

		_elapsedTime = 0.0f;

		// 弾の生成
		auto* bullet = GameObject::Builder()
			.setTag(Tag::Bullet)
			.build()
			->setPosition(_shotPos)
			->setScale({ 75.0f, 75.0f, 75.0f })->addComponent<Model3D>()
			->loadModel(_shotBulletPath)
			->getGameObject();
		auto bulletHalfScale = VScale(bullet->getTransform().scale, 0.5f);
		bullet->addComponent<AABBCollider>()->setAABB(
			VGet(-bulletHalfScale.x, -bulletHalfScale.y, -bulletHalfScale.z),
			bulletHalfScale
		);
		bullet->addComponent<EnemyBullet>()
			->setSpeed(ENEMY_BULLET_SPEED)
			->setDirection(dir)
			->setLifeTime(ENEMY_BULLET_LIFE_TIME)
			->getGameObject();
	}
}