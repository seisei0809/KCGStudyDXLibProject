#include "stdafx.h"
#include "Camera.h"

/// <summary>
/// 初期化時実行
/// </summary>
void Camera::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void Camera::update() {

    updateView();
}

/// <summary>
/// 固定間隔で実行
/// </summary>
void Camera::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void Camera::destroy() {

}

/// <summary>
/// ターゲットの位置を見るようにする
/// </summary>
/// <param name="targetPos">ターゲット位置</param>
void Camera::lookAtTarget(const VECTOR targetPos) {

	Transform& transform = _gameObject->getTransform();
    VECTOR dif = VSub(targetPos, transform.position);

    transform.rotation.y = std::atan2(dif.x, dif.z);
    transform.rotation.x = std::atan2(dif.y, std::sqrt(dif.x * dif.x + dif.z * dif.z));

    // 更新したのでもう一回セット
    updateView();
}

/// <summary>
/// カメラの見え方を更新する
/// </summary>
void Camera::updateView() {

    auto pos = _gameObject->getTransform().position;
    auto rot = _gameObject->getTransform().rotation;

    VECTOR forward;
    forward.x = std::sin(rot.y) * std::cos(rot.x);
    forward.y = std::sin(rot.x);
    forward.z = std::cos(rot.y) * std::cos(rot.x);

    VECTOR target = VAdd(pos, forward);

    SetCameraPositionAndTarget_UpVecY(pos, target);
}