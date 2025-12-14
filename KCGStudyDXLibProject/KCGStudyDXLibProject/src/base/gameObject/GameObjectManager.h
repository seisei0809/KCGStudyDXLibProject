#pragma once
#include "GameObject.h"
#include "Singleton.h"

/// <summary>
/// ゲームオブジェクト管理
/// </summary>
class GameObjectManager : public Utility::Singleton<GameObjectManager>{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameObjectManager();

	/// <summary>
	/// 全てのゲームオブジェクトの更新
	/// </summary>
	void allUpdate();

	/// <summary>
	/// 全てのゲームオブジェクトの固定更新
	/// </summary>
	void allFixedUpdate();

	/// <summary>
	/// ゲームオブジェクトを追加する
	/// </summary>
	/// <param name="gameObject">ゲームオブジェクト</param>
	void addGameObject(GameObject* gameObject);

	/// <summary>
	/// ゲームオブジェトを破棄する
	/// </summary>
	/// <param name="gameObject">ゲームオブジェクト</param>
	void destroyGameObject(GameObject* gameObject);

	/// <summary>
	/// 全てのゲームオブジェクトを破棄する
	/// </summary>
	void destroyAllGameObject();

	/// <summary>
	/// 型でゲームオブジェクトを探す
	/// </summary>
	/// <typeparam name="T">型</typeparam>
	/// <returns>インスタンス</returns>
	template<typename T>
	GameObject* getGameObjectByType() {

		for (auto& gameObject : _gameObjects) {
			
			T* temp = gameObject->getComponent<T>();
			if (temp != nullptr) {

				return gameObject;
			}
		}
		return nullptr;
	}

private:

	/// <summary>
	/// ゲームオブジェクト配列の更新
	/// </summary>
	void _UpdateGameObjectArray();

	// ゲームオブジェクト配列
	std::vector<GameObject*> _gameObjects;
	// 追加予定のゲームオブジェクト配列
	std::vector<GameObject*> _addGameObjects;
	// 破棄予定のゲームオブジェクト配列
	std::vector<GameObject*> _destroyGameObjects;
	// FixedUpdate用の累積時間
	double _fixedUpdateCumulativeTime;
};

