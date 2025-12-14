#include "stdafx.h"
#include "ColliderManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
ColliderManager::ColliderManager()
	:_colliders() {

}

/// <summary>
/// コライダーの更新
/// </summary>
void ColliderManager::updateCollider() {
	
	_UpdateColliderArray();

	if (_colliders.size() < 2) return;

	for (auto& colliderA : _colliders) {

		for (auto& colliderB : _colliders) {


			if (colliderA == colliderB) continue;

			if (colliderA->collide(*colliderB)) {

				colliderA->getOnCollisionEnterEvent().invoke(colliderB);
			}
		}
	}

	_UpdateColliderArray();
}

/// <summary>
/// コライダーを追加する
/// </summary>
/// <param name="collider">コライダー</param>
void ColliderManager::addCollider(ICollider* collider) {

	_addColliders.emplace_back(collider);
}

/// <summary>
/// コライダーを破棄する
/// </summary>
/// <param name="collider">コライダー</param>
void ColliderManager::destroyCollider(ICollider* collider) {

	_destroyColliders.emplace_back(collider);
}

/// <summary>
/// コライダー配列の更新
/// </summary>
void ColliderManager::_UpdateColliderArray() {

	// 追加処理
	for (auto* addCollider : _addColliders) {

		_colliders.emplace_back(addCollider);
	}
	_addColliders.clear();

	// 破棄処理
	for (auto* destroyCollider : _destroyColliders) {

		for (auto it = _colliders.begin(); it != _colliders.end(); ++it) {

			if (*it == destroyCollider) {

				_colliders.erase(it);
				break;
			}
		}
	}
	_destroyColliders.clear();
}