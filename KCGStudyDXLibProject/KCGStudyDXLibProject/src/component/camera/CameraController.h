#pragma once
#include "IComponent.h"
#include "Camera.h"

/// <summary>
/// カメラを動かす
/// </summary>
class CameraController : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	CameraController();

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
	/// ターゲットを設定する
	/// </summary>
	/// <param name="target">ターゲット</param>
	/// <returns>メソッドチェーン用</returns>
	CameraController* setTarget(GameObject* target);

	/// <summary>
	/// カメラオフセットを設定する
	/// </summary>
	/// <param name="offset">オフセット</param>
	/// <returns>メソッドチェーン用</returns>
	CameraController* setCameraOffset(const VECTOR offset);

	/// <summary>
	/// ターゲットオフセットを設定する
	/// </summary>
	/// <param name="offset">オフセット</param>
	/// <returns>メソッドチェーン用</returns>
	CameraController* setTargetOffset(const VECTOR offset);

private:

	// ターゲット
	GameObject* _target;
	// カメラオフセット
	VECTOR _cameraOffset;
	// ターゲットオフセット
	VECTOR _targetOffset;
	// 自分自身のカメラ
	Camera* _camera;
};

