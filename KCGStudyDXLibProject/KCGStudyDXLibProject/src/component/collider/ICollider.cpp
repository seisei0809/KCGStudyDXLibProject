#include "stdafx.h"
#include "ICollider.h"
#include "ColliderManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
ICollider::ICollider() {

	ColliderManager::getInstance().addCollider(this);
}

/// <summary>
/// デストラクタ
/// </summary>
ICollider::~ICollider() {

	ColliderManager::getInstance().destroyCollider(this);
}

/// <summary>
/// 外部発火用の衝突検知イベント取得
/// </summary>
/// <returns>イベント</returns>
Utility::Event<ICollider*>& ICollider::getOnCollisionEnterEvent() {

	return _onCollisionEnterEvent;
}