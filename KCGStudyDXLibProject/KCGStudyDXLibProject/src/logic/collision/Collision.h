#pragma once
#include "collider/AABBCollider.h"

/// <summary>
/// 当たり判定計算
/// </summary>
class Collision{
public:

	/// <summary>
	/// AABBが衝突しているかのチェック
	/// </summary>
	/// <param name="left">1つ目</param>
	/// <param name="right">2つ目</param>
	/// <returns>trueなら衝突している</returns>
	static bool checkAABB(const AABBCollider::AABB left, const AABBCollider::AABB right);
};

