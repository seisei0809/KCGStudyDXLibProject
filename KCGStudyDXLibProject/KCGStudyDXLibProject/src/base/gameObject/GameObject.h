#pragma once
#include "GameObjectAny.h"

class IComponent;

/// <summary>
/// ゲームオブジェクト
/// </summary>
class GameObject {
public:

	class Builder {
	public:

		/// <summary>
		/// 名前を設定する
		/// </summary>
		/// <param name="name">名前</param>
		/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
		Builder& setName(const std::string& name);

		/// <summary>
		/// タグを設定する
		/// </summary>
		/// <param name="tag">タグ</param>
		/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
		Builder& setTag(const Tag tag);

		/// <summary>
		/// ビルドする
		/// </summary>
		/// <returns>GameObjectインスタンスを渡す</returns>
		GameObject* build();

		/// <summary>
		/// 名前を取得する
		/// </summary>
		/// <returns>名前</returns>
		const std::string getName() const;

		/// <summary>
		/// タグを取得する
		/// </summary>
		/// <returns>タグ</returns>
		constexpr Tag getTag() const;

	private:

		// デフォルト名前
		std::string _name = std::string("GameObject");
		// デフォルトタグ
		Tag _tag = Tag::None;
	};

	GameObject(const Builder& builder);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameObject();

	/// <summary>
	/// コンポーネントのStart呼び出し
	/// </summary>
	void start();

	/// <summary>
	/// コンポーネントのUpdate呼び出し
	/// </summary>
	void update();

	/// <summary>
	/// コンポーネントのFixedUpdate呼び出し
	/// </summary>
	void fixedUpdate();

	/// <summary>
	/// コンポーネントのDestroy呼び出し
	/// </summary>
	void destroy();

	/// <summary>
	/// コンポーネントを削除する
	/// </summary>
	/// <param name="component">コンポーネント</param>
	void RemoveComponent(IComponent* component);

	/// <summary>
	/// コンポーネントを追加する
	/// </summary>
	/// <typeparam name="T">Component基底クラス</typeparam>
	/// <returns>コンポーネント</returns>
	template<typename T>
	inline T* AddComponent() {

		// 生成して追加予定配列に追加
		T* component = new T();
		component->setGameObject(this);
		_addComponents.emplace_back(component);
		return component;
	}

	/// <summary>
	/// コンポーネントの参照を取得する
	/// </summary>
	/// <typeparam name="T">Component基底クラス</typeparam>
	/// <returns>コンポーネント</returns>
	template<typename T>
	inline T* GetComponent() {

		for (auto& component : _components) {

			// キャスト成功したら返す
			T* temp = dynamic_cast<T*>(component);
			if (temp != nullptr) {

				return temp;
			}
		}
		return nullptr;
	}

	/// <summary>
	/// Transform情報の取得
	/// </summary>
	/// <returns>Transform</returns>
	Transform& getTransform();

private:

	/// <summary>
	/// コンポーネント配列の更新
	/// </summary>
	void _UpdateComponentArray();

	// アタッチしているコンポーネント配列
	std::vector<IComponent*> _components;
	// 追加予定のコンポーネント配列
	std::vector<IComponent*> _addComponents;
	// 削除予定のコンポーネント配列
	std::vector<IComponent*> _destroyComponents;
	// Transform情報
	Transform _transform;
	// 名前
	std::string _name;
	// タグ
	Tag _tag;
	/// <summary>
	/// オブジェクトのアクティブ状態
	/// trueならアクティブ
	/// </summary>
	bool _isActive;
};

