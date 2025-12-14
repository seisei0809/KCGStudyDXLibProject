#pragma once
#include "IComponent.h"
#include "collider/ICollider.h"

/// <summary>
/// 通常の物理挙動
/// </summary>
class NormalPhysics : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	NormalPhysics();

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
	/// 重力加速度を設定する
	/// </summary>
	/// <param name="gravity">重力加速度</param>
	/// <returns>メソッドチェーン用</returns>
	NormalPhysics* setGravity(const float gravity);

	/// <summary>
	/// 最大重力を設定する
	/// </summary>
	/// <param name="maxGravity">最大重力</param>
	/// <returns>メソッドチェーン用</returns>
	NormalPhysics* setMaxGravity(const float maxGravity);

	/// <summary>
	/// 強制的に現在かかる力を設定
	/// </summary>
	/// <param name="vector">力の方向</param>
	void setVector(const VECTOR vector);

	/// <summary>
	/// 現在かかっている力を取得する
	/// </summary>
	/// <returns>現在かかっている力</returns>
	VECTOR getVector() const;

	/// <summary>
	/// ここでは単純な押し出し処理を行う
	/// </summary>
	/// <param name="collider">受け取ったコライダー</param>
	void pushObject(ICollider* collider);

private:

	// 重力加速度
	float _gravity;
	// 現在かかっている力
	VECTOR _nowVector;
	// 最大重力
	float _maxGravity;
	// コライダー(外から注入のため抽象化)
	ICollider* _collider;
	// 前回位置
	VECTOR _previousPosition;
};

