#include "stdafx.h"
#include "PlayerManager.h"
#include "InputManager.h"

using namespace Utility;

/// <summary>
/// コンストラクタ
/// </summary>
PlayerManager::PlayerManager()
	:_speed(0.0f),
	_jumpPower(0.0f),
	_groundTag(AllEnumSpace::Tag::None),
	_groundChecker(),
	_mover(){

}

/// <summary>
/// 初期化時実行
/// </summary>
void PlayerManager::start() {

	_groundChecker = new PlayerGroundChecker();
	_groundChecker->setGroundTag(_groundTag);
	_gameObject->getComponent<ICollider>()
		->setOnCollisionEnterEvent(_groundChecker, &PlayerGroundChecker::checkOnGround);

	_mover = new PlayerMover();
	_mover->setSpeed(_speed)
		->setJumpPower(_jumpPower)
		->setGroundChecker(_groundChecker)
		->setTransform(&_gameObject->getTransform())
		->setPhysics(_gameObject->getComponent<NormalPhysics>());
	InputManager::addDir4Event(_mover, &PlayerMover::updateMoveInput);
	InputManager::addJumpEvent(_mover, &PlayerMover::updateJumpInput);
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void PlayerManager::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void PlayerManager::fixedUpdate() {

	_mover->allMove();
}

/// <summary>
/// 破棄時実行
/// </summary>
void PlayerManager::destroy() {

	InputManager::removeDir4Event(_mover, &PlayerMover::updateMoveInput);
	InputManager::removeJumpEvent(_mover, &PlayerMover::updateJumpInput);

	delete _groundChecker;
	delete _mover;
}

/// <summary>
/// スピードをセットする
/// </summary>
/// <param name="speed">スピード</param>
/// <returns>メソッドチェーン用</returns>
PlayerManager* PlayerManager::setSpeed(float speed) {

	_speed = speed;
	return this;
}

/// <summary>
/// ジャンプ力をセットする
/// </summary>
/// <param name="power">ジャンプ力</param>
/// <returns>メソッドチェーン用</returns>
PlayerManager* PlayerManager::setJumpPower(float power) {

	_jumpPower = power;
	return this;
}

/// <summary>
/// 地面のタグをセットする
/// </summary>
/// <param name="tag">タグ</param>
/// <returns>メソッドチェーン用</returns>
PlayerManager* PlayerManager::setGroundTag(AllEnumSpace::Tag tag) {

	_groundTag = tag;
	return this;
}