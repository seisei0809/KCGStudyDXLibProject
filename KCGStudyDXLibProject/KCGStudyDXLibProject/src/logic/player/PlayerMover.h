#pragma once
#include "GameObject.h"
#include "PlayerGroundChecker.h"
#include "physics/NormalPhysics.h"

/// <summary>
/// プレイヤー移動定義
/// </summary>
class PlayerMover{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	PlayerMover();

	/// <summary>
	/// スピードをセットする
	/// </summary>
	/// <param name="speed">スピード</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerMover* setSpeed(const float speed);

	/// <summary>
	/// ジャンプ力をセットする
	/// </summary>
	/// <param name="jumpPower">ジャンプ力</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerMover* setJumpPower(const float jumpPower);

	/// <summary>
	/// 地面判定用
	/// </summary>
	/// <param name="groundChecker">地面判定</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerMover* setGroundChecker(PlayerGroundChecker* groundChecker);

	/// <summary>
	/// Transformをセット
	/// </summary>
	/// <param name="transform">trasform</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerMover* setTransform(Transform* transform);

	/// <summary>
	/// 物理干渉のためにセット
	/// </summary>
	/// <param name="physics">物理</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerMover* setPhysics(NormalPhysics* physics);

	/// <summary>
	/// 移動関係全ての処理
	/// </summary>
	void allMove();

	/// <summary>
	/// 移動入力状況を更新する
	/// </summary>
	/// <param name="isMoveForward">前</param>
	/// <param name="isMoveBack">後ろ</param>
	/// <param name="isMoveRight">右</param>
	/// <param name="isMoveLeft">左</param>
	void updateMoveInput(bool isMoveForward, bool isMoveBack, bool isMoveRight, bool isMoveLeft);

	/// <summary>
	/// ジャンプ入力を更新する
	/// </summary>
	/// <param name="isJump">ジャンプしているか</param>
	void updateJumpInput(bool isJump);

private:

	// スピード
	float _speed;
	// ジャンプ力
	float _jumpPower;
	// 移動入力状況
	bool _moveInput[4];
	// 地面判定
	PlayerGroundChecker* _groundChecker;
	// transform
	Transform* _transform;
	// ノーマル物理挙動
	NormalPhysics* _physics;
};

