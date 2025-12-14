#include "stdafx.h"
#include "PlayerMover.h"
#include "TimeManager.h"

using namespace Utility;

/// <summary>
/// コンストラクタ
/// </summary>
PlayerMover::PlayerMover()
	:_speed(300.0f),
	_jumpPower(600.0f),
    _groundChecker(),
    _transform(),
	_physics(){
	
	_moveInput[0] = false;
	_moveInput[1] = false;
	_moveInput[2] = false;
	_moveInput[3] = false;
}

/// <summary>
/// スピードをセットする
/// </summary>
/// <param name="speed">スピード</param>
/// <returns>メソッドチェーン用</returns>
PlayerMover* PlayerMover::setSpeed(const float speed) {

	_speed = speed;
	return this;
}

/// <summary>
/// ジャンプ力をセットする
/// </summary>
/// <param name="jumpPower">ジャンプ力</param>
/// <returns>メソッドチェーン用</returns>
PlayerMover* PlayerMover::setJumpPower(const float jumpPower) {

	_jumpPower = jumpPower;
	return this;
}

/// <summary>
/// 地面判定用
/// </summary>
/// <param name="groundChecker">地面判定</param>
/// <returns>メソッドチェーン用</returns>
PlayerMover* PlayerMover::setGroundChecker(PlayerGroundChecker* groundChecker) {

	_groundChecker = groundChecker;
    return this;
}

/// <summary>
/// Transformをセット
/// </summary>
/// <param name="transform">trasform</param>
/// <returns>メソッドチェーン用</returns>
PlayerMover* PlayerMover::setTransform(Transform* transform) {

	_transform = transform;
	return this;
}

/// <summary>
/// 物理干渉のためにセット
/// </summary>
/// <param name="physics">物理</param>
/// <returns>メソッドチェーン用</returns>
PlayerMover* PlayerMover::setPhysics(NormalPhysics* physics) {

	_physics = physics;
	return this;
}

/// <summary>
/// 移動関係全ての処理
/// </summary>
void PlayerMover::allMove() {

    float dt = static_cast<float>(TimeManager::fixedDeltaTime());

    VECTOR move = VGet(0.0f, 0.0f, 0.0f);

    // 入力更新
    if (_moveInput[0]) move.z += 1.0f;
    if (_moveInput[1]) move.z -= 1.0f;
    if (_moveInput[2]) move.x += 1.0f;
    if (_moveInput[3]) move.x -= 1.0f;

    // 正規化（斜め移動対策）
    float len = std::sqrt(move.x * move.x + move.z * move.z);
    if (len > 0.0f) {
        move.x /= len;
        move.z /= len;
    }

    // 移動
	VECTOR v = _physics->getVector();
	v.x = move.x * _speed;
	v.z = move.z * _speed;
	_physics->setVector(v);
	// 地面付いてたらYは0にする
	if (_groundChecker->onGrounded()) {

		_physics->setVector(VGet(
			_physics->getVector().x,
			0.0f,
			_physics->getVector().z));
		_physics->setIsGravity(false);
	}
}

/// <summary>
/// 入力状況を更新する
/// </summary>
/// <param name="isMoveForward">前</param>
/// <param name="isMoveBack">後ろ</param>
/// <param name="isMoveRight">右</param>
/// <param name="isMoveLeft">左</param>
void PlayerMover::updateMoveInput(bool isMoveForward, bool isMoveBack, bool isMoveRight, bool isMoveLeft) {

	_moveInput[0] = isMoveForward;
	_moveInput[1] = isMoveBack;
	_moveInput[2] = isMoveRight;
	_moveInput[3] = isMoveLeft;
}

/// <summary>
/// ジャンプ入力を更新する
/// </summary>
/// <param name="isJump">ジャンプしているか</param>
void PlayerMover::updateJumpInput(bool isJump) {

	//地面ならジャンプ力を加える
	_physics->setVector(VGet(
		_physics->getVector().x,
		isJump && _groundChecker->onGrounded() ? _jumpPower : _physics->getVector().y,
		_physics->getVector().z));
	_groundChecker->setOnGround(false);
	// ジャンプした時に重力有効
	_physics->setIsGravity(true);
}