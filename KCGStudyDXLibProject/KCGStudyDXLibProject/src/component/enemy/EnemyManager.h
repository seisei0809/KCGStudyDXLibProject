#pragma once
#include "IComponent.h"
#include "enemy/EnemyShooter.h"

/// <summary>
/// 敵管理
/// </summary>
class EnemyManager : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnemyManager();

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
	/// 発射間隔を設定する
	/// </summary>
	/// <param name="duration">間隔</param>
	/// <returns>メソッドチェーン用</returns>
	EnemyManager* setShotDuration(float duration);

	/// <summary>
	/// プレイヤーのTransformをセットする
	/// </summary>
	/// <param name="tr">transform</param>
	/// <returns>メソッドチェーン用</returns>
	EnemyManager* setPlayerTransform(Transform& tr);

private:

	// 間隔
	float _duration;
	// PlayerのTransform
	Transform* _playerTransform;
	// 発射用
	EnemyShooter* _shooter;
};

