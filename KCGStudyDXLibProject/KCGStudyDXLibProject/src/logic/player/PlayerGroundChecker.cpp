#include "stdafx.h"
#include "PlayerGroundChecker.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerGroundChecker::PlayerGroundChecker()
	:_groundTag(),
	_onGround(false) {

}

/// <summary>
/// 地面タグをセットする
/// </summary>
/// <param name="tag">タグ</param>
	/// <returns>メソッドチェーン用</returns>
PlayerGroundChecker* PlayerGroundChecker::setGroundTag(AllEnumSpace::Tag tag) {

	_groundTag = tag;
	return this;
}

/// <summary>
/// 外部からも変更できるようにする
/// </summary>
/// <param name="onGround">地面の上か</param>
void PlayerGroundChecker::setOnGround(bool onGround) {

	_onGround = onGround;
}

/// <summary>
/// 地面に接地しているか
/// </summary>
/// <returns>接地していたらtrue</returns>
bool PlayerGroundChecker::onGrounded() {

	return _onGround;
}

/// <summary>
/// コライダーイベントに登録用
/// 地面に接地したかの処理
/// </summary>
/// <param name="collider">コライダー</param>
void PlayerGroundChecker::checkOnGround(ICollider* collider) {

	// 衝突したものとタグが一致したなら地面の上に居ることにする
	_onGround = _groundTag == collider->getGameObject()->getTag() ? true : false;
}