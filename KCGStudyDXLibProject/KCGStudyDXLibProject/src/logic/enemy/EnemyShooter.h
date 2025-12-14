#pragma once
#include "GameObject.h"

/// <summary>
/// 敵の発射処理
/// </summary>
class EnemyShooter{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnemyShooter();

	/// <summary>
	/// 発射間隔のセット
	/// </summary>
	/// <param name="duration">間隔</param>
	/// <returns>メソッドチェーン用</returns>
	EnemyShooter* setDuration(float duration);

	/// <summary>
	/// 発射する位置をセットする
	/// </summary>
	/// <param name="pos">位置</param>
	/// <returns>メソッドチェーン用</returns>
	EnemyShooter* setShotPos(const VECTOR& pos);

	/// <summary>
	/// 発射する弾のパスをセットする
	/// </summary>
	/// <param name="path">パス</param>
	/// <returns>メソッドチェーン用</returns>
	EnemyShooter* setShotBulletPath(const wchar_t* path);

	/// <summary>
	/// プレイヤーのTransformをセットする
	/// </summary>
	/// <param name="transform">transform</param>
	/// <returns>メソッドチェーン用</returns>
	EnemyShooter* setPlayerTransform(Transform* transform);

	/// <summary>
	/// ループでこの関数を呼ぶ
	/// </summary>
	void shotLoop();

private:

	// 発射間隔
	float _duration;
	// 発射位置
	VECTOR _shotPos;
	// 発射する弾のパス
	const wchar_t* _shotBulletPath;
	// 経過時間
	float _elapsedTime;
	// プレイヤーのTransform
	Transform* _playerTransform;
};

