#pragma once
#include "IComponent.h"

/// <summary>
/// カメラ
/// </summary>
class Camera : public IComponent{
public:

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
	/// ターゲットの位置を見るようにする
	/// </summary>
	/// <param name="targetPos">ターゲット位置</param>
	void lookAtTarget(const VECTOR targetPos);

	/// <summary>
	/// カメラの見え方を更新する
	/// </summary>
	void updateView();
};

