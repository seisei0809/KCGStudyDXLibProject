#include "stdafx.h"
#include "TitleScene.h"
#include "renderer/UI/UIText.h"
#include "GameObject.h"

/// <summary>
/// シーン開始時処理
/// </summary>
void TitleScene::start() {

	auto* title = GameObject::Builder()
		.build();
	title->AddComponent<UIText>()
		->setText(L"タイトル")
		->setColor(GetColor(255, 0, 0))
		->setUIScale(1)
		->setAnchor(IUIRenderer::Anchor::Center)
		->setCenter(true)
		->setLayer(100);
}

/// <summary>
/// シーン破棄時処理
/// </summary>
void TitleScene::destroy() {

}