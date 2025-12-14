#pragma once
#include "IComponent.h"
#include "player/PlayerGroundChecker.h"
#include "player/PlayerMover.h"

/// <summary>
/// プレイヤー管理
/// </summary>
class PlayerManager : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	PlayerManager();

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
	/// スピードをセットする
	/// </summary>
	/// <param name="speed">スピード</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerManager* setSpeed(float speed);

	/// <summary>
	/// ジャンプ力をセットする
	/// </summary>
	/// <param name="power">ジャンプ力</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerManager* setJumpPower(float power);

	/// <summary>
	/// 地面のタグをセットする
	/// </summary>
	/// <param name="tag">タグ</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerManager* setGroundTag(AllEnumSpace::Tag tag);

private:

	// スピード
	float _speed;
	// ジャンプ力
	float _jumpPower;
	// 地面のタグ
	AllEnumSpace::Tag _groundTag;
	// 地面判定用
	PlayerGroundChecker* _groundChecker;
	// 移動用
	PlayerMover* _mover;
};

