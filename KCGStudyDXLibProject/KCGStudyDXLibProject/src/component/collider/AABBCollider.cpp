#include "stdafx.h"
#include "AABBCollider.h"
#include "collision/Collision.h"

/// <summary>
/// コンストラクタ
/// </summary>
AABBCollider::AABBCollider()
	:_aabb{} {
}

/// <summary>
/// 初期化時実行
/// </summary>
void AABBCollider::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void AABBCollider::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void AABBCollider::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void AABBCollider::destroy() {

}

/// <summary>
/// 基本的に呼び出す側の衝突判定
/// </summary>
/// <param name="other">相手</param>
/// <returns>trueなら衝突している</returns>
bool AABBCollider::collide(const ICollider& other) const {

    // 自分がAABBだと相手に伝える
    return other.collideWithAABB(*this);
}

/// <summary>
/// 相手がAABBの場合の衝突判定
/// </summary>
/// <param name="other">相手</param>
/// <returns>trueなら衝突している</returns>
bool AABBCollider::collideWithAABB(const AABBCollider& other) const {

    auto myAABB = this->_aabb;
	auto otherAABB = other._aabb;

	auto& playerTr = _gameObject->getTransform();
	myAABB.min = VAdd(myAABB.min, playerTr.position);
	myAABB.max = VAdd(myAABB.max, playerTr.position);

	auto& otherTr = other._gameObject->getTransform();
	otherAABB.min = VAdd(otherAABB.min, otherTr.position);
	otherAABB.max = VAdd(otherAABB.max, otherTr.position);

    return Collision::checkAABB(myAABB, otherAABB);
}

/// <summary>
/// AABBのセット
/// </summary>
/// <param name="min">最小位置</param>
/// <param name="max">最大位置</param>
/// <returns>メソッドチェーン用</returns>
AABBCollider* AABBCollider::setAABB(const VECTOR& min, const VECTOR& max) {

    _aabb.min = min;
    _aabb.max = max;
	return this;
}