#include "stdafx.h"
#include "GameObject.h"
#include "IComponent.h"
#include "GameObjectManager.h"

using namespace AllEnumSpace;

/// <summary>
/// コンストラクタ
/// </summary>
GameObject::Builder::Builder()
	:_name("GameObject"),
	_tag(Tag::None) {

}

/// <summary>
/// 名前を設定する
/// </summary>
/// <param name="name">名前</param>
/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
GameObject::Builder& GameObject::Builder::setName(const std::string& name) {

	_name = name;
	return *this;
}

/// <summary>
/// タグを設定する
/// </summary>
/// <param name="tag">タグ</param>
/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
GameObject::Builder& GameObject::Builder::setTag(const Tag tag) {

	_tag = tag;
	return *this;
}

/// <summary>
/// ビルドする
/// </summary>
/// <returns>GameObjectインスタンスを渡す</returns>
GameObject* GameObject::Builder::build() {

	GameObject* gameObject = new GameObject(*this);
	return gameObject;
}

/// <summary>
/// 名前を取得する
/// </summary>
/// <returns>名前</returns>
const std::string GameObject::Builder::getName() const {

	return _name;
}

/// <summary>
/// タグを取得する
/// </summary>
/// <returns>タグ</returns>
constexpr Tag GameObject::Builder::getTag() const {

	return _tag;
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="builder">ビルド設定</param>
GameObject::GameObject(const Builder& builder)
	:_components(),
	_addComponents(),
	_destroyComponents(),
	_transform(),
	_name(),
	_tag(),
	_isActive(true){

	_name = builder.getName();
	_tag = builder.getTag();
	GameObjectManager::getInstance().addGameObject(this);
}

/// <summary>
/// デストラクタ
/// </summary>
GameObject::~GameObject() {

	// 破棄時コンポーネントを全て破棄
	for (auto& component : _components) {

		delete component;
	}
	_components.clear();

	for (auto& component : _addComponents) {

		delete component;
	}
	_addComponents.clear();

	_destroyComponents.clear();
}

/// <summary>
/// コンポーネントのStart呼び出し
/// </summary>
void GameObject::start() {

	for (auto& component : _components) {

		component->start();
	}
}

/// <summary>
/// コンポーネントのUpdate呼び出し
/// </summary>
void GameObject::update() {

	if (!_isActive) return;

	_UpdateComponentArray();

	for (auto& component : _components) {

		component->update();
	}

	_UpdateComponentArray();
}

/// <summary>
/// コンポーネントのFixedUpdate呼び出し
/// </summary>
void GameObject::fixedUpdate() {

	if (!_isActive) return;

	_UpdateComponentArray();

	for (auto& component : _components) {

		if (component != nullptr) {

			component->fixedUpdate();
		}
	}

	_UpdateComponentArray();
}

/// <summary>
/// コンポーネントのDestroy呼び出し
/// </summary>
void GameObject::destroy() {

	for (auto& component : _components) {

		component->destroy();
	}
}

/// <summary>
/// コンポーネントを削除する
/// </summary>
void GameObject::removeComponent(IComponent* component) {

	if (component == nullptr) return;

	// 削除予定配列に追加
	_destroyComponents.emplace_back(component);
}

/// <summary>
/// 位置のセット
/// </summary>
/// <param name="position">位置</param>
/// <returns>メソッドチェーン用</returns>
GameObject* GameObject::setPosition(const VECTOR position) {

	_transform.position = position;
	return this;
}

/// <summary>
/// 回転のセット
/// </summary>
/// <param name="rotation">回転</param>
/// <returns>メソッドチェーン用</returns>
GameObject* GameObject::setRotation(const VECTOR rotation) {

	_transform.rotation = rotation;
	return this;
}

/// <summary>
/// スケールのセット
/// </summary>
/// <param name="scale">スケール</param>
/// <returns>メソッドチェーン用</returns>
GameObject* GameObject::setScale(const VECTOR scale) {

	_transform.scale = scale;
	return this;
}

/// <summary>
/// Transform情報の取得
/// </summary>
/// <returns>Transform</returns>
Transform& GameObject::getTransform() {

	return _transform;
}

/// <summary>
/// コンポーネント配列の更新
/// </summary>
void GameObject::_UpdateComponentArray() {

	// 追加処理
	for (auto& component : _addComponents) {

		if (component != nullptr) {

			// 追加時にstartを呼ぶ
			_components.emplace_back(component);
			component->start();
		}
	}
	_addComponents.clear();

	// 削除処理
	for (auto& removeComponent : _destroyComponents) {

		for (auto it = _components.begin(); it != _components.end(); it++) {

			if ((*it) != removeComponent)continue;
			// destroyを呼んでから破棄して削除
			(*it)->destroy();
			delete* it;
			_components.erase(it);
			break;
		}
	}
	_destroyComponents.clear();
}