#pragma once
#include "IComponent.h"
#include "Event.h"

class AABBCollider;

/// <summary>
/// コライダーインターフェース
/// </summary>
class ICollider : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	ICollider();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~ICollider();

	/// <summary>
	/// 基本的に呼び出す側の衝突判定
	/// </summary>
	/// <param name="other">相手</param>
	/// <returns>trueなら衝突している</returns>
	virtual bool collide(const ICollider& other) const = 0;

	/// <summary>
	/// 相手がAABBの場合の衝突判定
	/// </summary>
	/// <param name="other">相手</param>
	/// <returns>trueなら衝突している</returns>
	virtual bool collideWithAABB(const AABBCollider& other) const = 0;

	/// <summary>
	/// 衝突時に発火するイベントに追加
	/// </summary>
	/// <typeparam name="T">インスタンスの型</typeparam>
	/// <param name="obj">インスタンス</param>
	/// <param name="method">メンバ関数ポインタ</param>
	/// <returns>メソッドチェーン用</returns>
	template<typename T>
	ICollider* setOnCollisionEnterEvent(T* obj, void (T::* method)(ICollider*)) {

		_onCollisionEnterEvent.add(obj, method);
	}

	/// <summary>
	/// 衝突時に発火するイベントから破棄
	/// </summary>
	/// <typeparam name="T">インスタンスの型</typeparam>
	/// <param name="obj">インスタンス</param>
	/// <param name="method">メンバ関数ポインタ</param>
	/// <returns>メソッドチェーン用</returns>
	template<typename T>
	ICollider* destroyOnCollisionEnterEvent(T* obj, void (T::* method)(ICollider*)) {

		_onCollisionEnterEvent.remove(obj, method);
	}

	/// <summary>
	/// 外部発火用の衝突検知イベント取得
	/// </summary>
	/// <returns>イベント</returns>
	Utility::Event<ICollider*>& getOnCollisionEnterEvent();

private:

	// 衝突検知イベント
	Utility::Event<ICollider*> _onCollisionEnterEvent;
};

