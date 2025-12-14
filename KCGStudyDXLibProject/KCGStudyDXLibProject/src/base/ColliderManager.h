#pragma once
#include "Singleton.h"
#include "collider/ICollider.h"

/// <summary>
/// コライダー管理
/// </summary>
class ColliderManager : public Utility::Singleton<ColliderManager>{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	ColliderManager();

	/// <summary>
	/// コライダーの更新
	/// </summary>
	void updateCollider();

	/// <summary>
	/// コライダーを追加する
	/// </summary>
	/// <param name="collider">コライダー</param>
	void addCollider(ICollider* collider);

	/// <summary>
	/// コライダーを破棄する
	/// </summary>
	/// <param name="collider">コライダー</param>
	void destroyCollider(ICollider* collider);

private:

	/// <summary>
	/// コライダー配列の更新
	/// </summary>
	void _UpdateColliderArray();

	// コライダー配列
	std::vector<ICollider*> _colliders;
	// 追加予定のコライダー配列
	std::vector<ICollider*> _addColliders;
	// 破棄予定のコライダー配列
	std::vector<ICollider*> _destroyColliders;
};

