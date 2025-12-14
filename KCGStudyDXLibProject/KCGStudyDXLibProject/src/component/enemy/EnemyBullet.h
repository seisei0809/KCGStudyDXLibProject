#pragma once
#include "IComponent.h"
#include "collider/ICollider.h"

/// <summary>
/// 敵弾
/// </summary>
class EnemyBullet :  public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnemyBullet();

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
	EnemyBullet* setSpeed(float speed);

	/// <summary>
	/// 方向をセットする
	/// </summary>
	/// <param name="dir"></param>
	/// <returns>メソッドチェーン用</returns>
	EnemyBullet* setDirection(VECTOR dir);

	/// <summary>
	/// 生存時間のセット
	/// </summary>
	/// <param name="time">時間</param>
	/// <returns>メソッドチェーン用</returns>
	EnemyBullet* setLifeTime(float time);

	/// <summary>
	/// 呼ばれたら攻撃処理
	/// </summary>
	/// <param name="collider">衝突相手</param>
	void Attack(ICollider* collider);

private:

	// スピード
	float _speed;
	// 方向
	VECTOR _direction;
	// ライフタイム
	float _lifeTime;
	// 経過時間
	float _elapsedTime;
	// コライダー
	ICollider* _collider;
};

