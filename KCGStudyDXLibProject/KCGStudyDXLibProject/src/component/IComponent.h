#pragma once
#include "GameObject.h"

/// <summary>
/// コンポーネント基底
/// </summary>
class IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	IComponent() = default;

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~IComponent() = default;

	/// <summary>
	/// 初期化時実行
	/// </summary>
	virtual void start() = 0;

	/// <summary>
	/// 毎フレーム実行
	/// </summary>
	virtual void update() = 0;

	/// <summary>
	/// 固定間隔で実行
	/// </summary>
	virtual void fixedUpdate() = 0;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	virtual void destroy() = 0;

	/// <summary>
	/// アタッチされているゲームオブジェクトをセットする
	/// </summary>
	/// <param name="obj">ゲームオブジェクト</param>
	void setGameObject(GameObject* obj);

	/// <summary>
	/// アタッチされているゲームオブジェクトの取得
	/// </summary>
	/// <returns>ゲームオブジェクト</returns>
	GameObject* getGameObject() const;

protected:

	// アタッチされているゲームオブジェクト
	GameObject* _gameObject = nullptr;
};

