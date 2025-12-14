#include "stdafx.h"
#include "NormalPhysics.h"
#include "TimeManager.h"

using namespace Utility;

/// <summary>
/// コンストラクタ
/// </summary>
NormalPhysics::NormalPhysics()
	:_gravity(-9.8f),
	_nowVector(VGet(0.0f, 0.0f, 0.0f)),
	_maxGravity(-30.0f),
	_collider(nullptr),
	_previousPosition(),
	_isGravity(true){

}

/// <summary>
/// 初期化時実行
/// </summary>
void NormalPhysics::start() {

	// 初期化
	_collider = _gameObject->getComponent<ICollider>();

	// イベント追加
	if (_collider) {

		_collider->setOnCollisionEnterEvent(this, &NormalPhysics::pushObject);
	}
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void NormalPhysics::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void NormalPhysics::fixedUpdate() {

	_previousPosition = _gameObject->getTransform().position;

	// 最大重力越えていないなら重力加速度を加算
	if (_nowVector.y > _maxGravity && _isGravity) {

		_nowVector.y += _gravity * static_cast<float>(TimeManager::fixedDeltaTime());
	}

	// このフレームで加算する力の計算
	auto tempVector = VScale(_nowVector, static_cast<float>(TimeManager::fixedDeltaTime()));

	// ベクトルたし算で力を加算
	_gameObject->getTransform().position = VAdd(
		_gameObject->getTransform().position,
		tempVector
	);
}

/// <summary>
/// 破棄時実行
/// </summary>
void NormalPhysics::destroy() {

	_collider->destroyOnCollisionEnterEvent(this, &NormalPhysics::pushObject);
}

/// <summary>
/// 重力加速度を設定する
/// </summary>
/// <param name="gravity">重力加速度</param>
/// <returns>メソッドチェーン用</returns>
NormalPhysics* NormalPhysics::setGravity(const float gravity) {

	_gravity = gravity;
	return this;
}

/// <summary>
/// 最大重力を設定する
/// </summary>
/// <param name="maxGravity">最大重力</param>
/// <returns>メソッドチェーン用</returns>
NormalPhysics* NormalPhysics::setMaxGravity(const float maxGravity) {

	_maxGravity = maxGravity;
	return this;
}

/// <summary>
/// 強制的に現在かかる力を設定
/// </summary>
/// <param name="vector">力の方向</param>
void NormalPhysics::setVector(const VECTOR vector) {

	_nowVector = vector;
}

/// <summary>
/// 現在かかっている力を取得する
/// </summary>
/// <returns>現在かかっている力</returns>
VECTOR NormalPhysics::getVector() const {

	return _nowVector;
}

/// <summary>
/// 重力処理をするか決める
/// </summary>
/// <param name="isGravity">重力つけるか</param>
void NormalPhysics::setIsGravity(bool isGravity) {

	_isGravity = isGravity;
}

/// <summary>
/// ここでは単純な押し出し処理を行う
/// </summary>
/// <param name="collider">受け取ったコライダー</param>
void NormalPhysics::pushObject(ICollider* collider) {

	if (!collider) return;

	_gameObject->getTransform().position = _previousPosition;
}