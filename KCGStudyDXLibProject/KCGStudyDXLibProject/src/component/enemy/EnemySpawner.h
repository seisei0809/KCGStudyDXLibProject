#pragma once
#include "IComponent.h"

/// <summary>
/// 敵生成
/// </summary>
class EnemySpawner :  public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnemySpawner();

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
	/// スポーン間隔のセット
	/// </summary>
	/// <param name="duration">間隔</param>
	/// <returns>メソッドチェーン用</returns>
	EnemySpawner* setSpawnDuration(float duration);

private:

	// スポーン間隔
	float _spawnDuration;
	// 経過時間
	float _elapsedTime;
};

