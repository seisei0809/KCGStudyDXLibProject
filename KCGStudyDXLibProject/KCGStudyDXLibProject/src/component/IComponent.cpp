#include "stdafx.h"
#include "IComponent.h"

/// <summary>
/// アタッチされているゲームオブジェクトをセットする
/// </summary>
/// <param name="obj">ゲームオブジェクト</param>
void IComponent::setGameObject(GameObject* obj) {

	_gameObject = obj;
}

/// <summary>
/// アタッチされているゲームオブジェクトの取得
/// </summary>
/// <returns>ゲームオブジェクト</returns>
GameObject* IComponent::getGameObject() const {

	return _gameObject;
}