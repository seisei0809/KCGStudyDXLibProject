#include "stdafx.h"
#include "Collision.h"

/// <summary>
/// AABBが衝突しているかのチェック
/// </summary>
/// <param name="left">1つ目</param>
/// <param name="right">2つ目</param>
/// <returns>trueなら衝突している</returns>
bool Collision::checkAABB(const AABBCollider::AABB left, const AABBCollider::AABB right) {

    if (left.max.x < right.min.x || left.min.x > right.max.x) return false;
    if (left.max.y < right.min.y || left.min.y > right.max.y) return false;
    if (left.max.z < right.min.z || left.min.z > right.max.z) return false;
    return true;
}