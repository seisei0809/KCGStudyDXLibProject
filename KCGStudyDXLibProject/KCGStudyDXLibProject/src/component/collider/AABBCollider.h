#pragma once
#include "ICollider.h"

/// <summary>
/// AABB当たり判定
/// </summary>
class AABBCollider : public ICollider{
public:

    /// <summary>
    /// AABB構造体
    /// </summary>
    struct AABB {

		// 最小位置
        VECTOR min;
		// 最大位置
        VECTOR max;
    };

	/// <summary>
	/// コンストラクタ
	/// </summary>
	AABBCollider();

	/// <summary>
	/// 初期化時実行
	/// </summary>
	void start() override;

	/// <summary>
	/// 毎フレーム実行
	/// </summary>
	void update() override;

	/// <summary>
	/// 固定間隔で実行
	/// </summary>
	void fixedUpdate() override;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	void destroy() override;

	/// <summary>
	/// 基本的に呼び出す側の衝突判定
	/// </summary>
	/// <param name="other">相手</param>
	/// <returns>trueなら衝突している</returns>
	bool collide(const ICollider& other) const override;

	/// <summary>
	/// 相手がAABBの場合の衝突判定
	/// </summary>
	/// <param name="other">相手</param>
	/// <returns>trueなら衝突している</returns>
	bool collideWithAABB(const AABBCollider& other) const override;

	/// <summary>
	/// AABBのセット
	/// </summary>
	/// <param name="min">最小位置</param>
	/// <param name="max">最大位置</param>
	/// <returns>メソッドチェーン用</returns>
	AABBCollider* setAABB(const VECTOR& min, const VECTOR& max);

private:

	// AABB情報
    AABB _aabb;
};

