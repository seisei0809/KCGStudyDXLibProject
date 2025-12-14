#pragma once
#include "collider/ICollider.h"

/// <summary>
/// プレイヤー用地面判定
/// </summary>
class PlayerGroundChecker{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	PlayerGroundChecker();

	/// <summary>
	/// 地面タグをセットする
	/// </summary>
	/// <param name="tag">タグ</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerGroundChecker* setGroundTag(AllEnumSpace::Tag tag);

	/// <summary>
	/// 外部からも変更できるようにする
	/// </summary>
	/// <param name="onGround">地面の上か</param>
	void setOnGround(bool onGround);

	/// <summary>
	/// 地面に接地しているか
	/// </summary>
	/// <returns>接地していたらtrue</returns>
	bool onGrounded();

	/// <summary>
	/// コライダーイベントに登録用
	/// 地面に接地したかの処理
	/// </summary>
	/// <param name="collider">コライダー</param>
	void checkOnGround(ICollider* collider);

private:

	// 地面タグ
	AllEnumSpace::Tag _groundTag;
	// 接地しているか
	bool _onGround;
};

