#include "stdafx.h"
#include "TitleScene.h"
#include "renderer/UI/UIText.h"
#include "renderer/UI/UIImage.h"
#include "GameObject.h"

using namespace AllEnumSpace;

/// <summary>
/// オブジェクト配置場所
/// </summary>
void TitleScene::SetGameObject() {

	// タイトルテキスト
	GameObject::Builder()
		.build()->addComponent<UIText>()
		->setText(L"タイトル")
		->setColor(GetColor(255, 0, 0))
		->setUIScale(50)
		->setAnchor(Anchor::BottomRight)
		->setLayer(100);
}