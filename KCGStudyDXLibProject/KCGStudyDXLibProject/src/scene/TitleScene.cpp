#include "stdafx.h"
#include "TitleScene.h"
#include "renderer/UI/UIText.h"
#include "GameObject.h"

using namespace AllEnumSpace;

/// <summary>
/// オブジェクト配置場所
/// </summary>
void TitleScene::SetGameObject() {

	// タイトルテキスト
	GameObject::Builder()
		.build()->AddComponent<UIText>()
		->setText(L"タイトル")
		->setColor(GetColor(255, 0, 0))
		->setUIScale(1)
		->setAnchor(Anchor::Center)
		->setCenter(true)
		->setLayer(100);
}