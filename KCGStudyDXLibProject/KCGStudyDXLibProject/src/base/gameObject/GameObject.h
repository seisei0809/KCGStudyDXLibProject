#pragma once
#include "GameObjectAny.h"
#include "AllEnum.h"

class IComponent;

/// <summary>
/// ゲームオブジェクト
/// </summary>
class GameObject {
public:

	class Builder {
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Builder();

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
		Builder& setTag(const AllEnumSpace::Tag tag);

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
		constexpr AllEnumSpace::Tag getTag() const;

	private:

		// デフォルト名前
		std::string _name;
		// デフォルトタグ
		AllEnumSpace::Tag _tag;
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
	void removeComponent(IComponent* component);

	/// <summary>
	/// コンポーネントを追加する
	/// </summary>
	/// <typeparam name="T">Component基底クラス</typeparam>
	/// <returns>コンポーネント</returns>
	template<typename T>
	inline T* addComponent() {

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
	inline T* getComponent() {

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
	/// 位置のセット
	/// </summary>
	/// <param name="position">位置</param>
	/// <returns>メソッドチェーン用</returns>
	GameObject* setPosition(const VECTOR position);

	/// <summary>
	/// 回転のセット
	/// </summary>
	/// <param name="rotation">回転</param>
	/// <returns>メソッドチェーン用</returns>
	GameObject* setRotation(const VECTOR rotation);

	/// <summary>
	/// スケールのセット
	/// </summary>
	/// <param name="scale">スケール</param>
	/// <returns>メソッドチェーン用</returns>
	GameObject* setScale(const VECTOR scale);

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
	AllEnumSpace::Tag _tag;
	/// <summary>
	/// オブジェクトのアクティブ状態
	/// trueならアクティブ
	/// </summary>
	bool _isActive;
};

