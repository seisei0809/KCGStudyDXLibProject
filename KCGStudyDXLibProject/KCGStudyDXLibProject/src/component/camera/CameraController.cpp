#include "stdafx.h"
#include "CameraController.h"

/// <summary>
/// コンストラクタ
/// </summary>
CameraController::CameraController()
	:_target(),
	_cameraOffset(),
	_targetOffset(),
	_camera() {

}

/// <summary>
/// 初期化時実行
/// </summary>
void CameraController::start() {

	_camera = _gameObject->getComponent<Camera>();
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void CameraController::update() {

	if (!_target || !_camera) return;

	// ターゲットからオフセットされた位置にする
	VECTOR targetPos = _target->getTransform().position;
	VECTOR cameraPos = VAdd(targetPos, _cameraOffset);
	_gameObject->getTransform().position = cameraPos;

	// カメラをターゲットの位置を見るようにする
	_camera->lookAtTarget(VAdd(targetPos,_targetOffset));
}

/// <summary>
/// 固定間隔で実行
/// </summary>
void CameraController::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void CameraController::destroy() {

}

/// <summary>
/// ターゲットを設定する
/// </summary>
/// <param name="target">ターゲット</param>
/// <returns>メソッドチェーン用</returns>
CameraController* CameraController::setTarget(GameObject* target) {

	_target = target;
	return this;
}

/// <summary>
/// カメラオフセットを設定する
/// </summary>
/// <param name="offset">オフセット</param>
/// <returns>メソッドチェーン用</returns>
CameraController* CameraController::setCameraOffset(const VECTOR offset) {

	_cameraOffset = offset;
	return this;
}

/// <summary>
/// ターゲットオフセットを設定する
/// </summary>
/// <param name="offset">オフセット</param>
/// <returns>メソッドチェーン用</returns>
CameraController* CameraController::setTargetOffset(const VECTOR offset) {

	_targetOffset = offset;
	return this;
}