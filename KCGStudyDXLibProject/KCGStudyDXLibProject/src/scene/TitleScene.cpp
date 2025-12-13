#include "stdafx.h"
#include "TitleScene.h"
#include "renderer/Model3D.h"
#include "renderer/ui/UIText.h"
#include "ui/ButtonViewer.h"
#include "GameObject.h"
#include "utility/InputManager.h"
#include "AllSettings.h"

using namespace AllEnumSpace;
using namespace Utility;

/// <summary>
/// オブジェクト配置場所
/// </summary>
void TitleScene::setGameObject() {

	// タイトル管理
	titleSceneManager = GameObject::Builder()
		.build()->addComponent<TitleSceneManager>();

	// タイトルテキスト
	GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, -100.0f, 0.0f))->addComponent<UIText>()
		->setText(WINDOW_TITLE)
		->setColor(GetColor(255, 0, 0))
		->setUIScale(70)
		->setAnchor(Anchor::MiddleCenter)
		->setLayer(100);

	// スタートボタン
	auto* const startButtonObj = GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, 100.0f, 0.0f))
		->addComponent<UIText>()
		->setText(L"はじめる")
		->setColor(GetColor(255, 0, 0))
		->setUIScale(30)
		->setAnchor(Anchor::MiddleCenter)
		->setLayer(100)
		->getGameObject();
	auto* const startButtonViewer = startButtonObj->addComponent<ButtonViewer>();
	startButton = startButtonObj->addComponent<Button>()
		->setIsSelect(true)
		->setUpButton(nullptr)
		->setDownButton(&endButton)
		->setSelectChangeEvent(startButtonViewer,&ButtonViewer::changeView);
	InputManager::addUI2DirEvent(startButton, &Button::selectChange);

	// 終了ボタン
	auto* const endButtonObj = GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, 200.0f, 0.0f))
		->addComponent<UIText>()
		->setText(L"おわる")
		->setColor(GetColor(128, 128, 128))
		->setUIScale(30)
		->setAnchor(Anchor::MiddleCenter)
		->setLayer(100)
		->getGameObject();
	auto* const endButtonViewer = endButtonObj->addComponent<ButtonViewer>();
	endButton = endButtonObj->addComponent<Button>()
		->setUpButton(&startButton)
		->setDownButton(nullptr)
		->setSelectChangeEvent(endButtonViewer,&ButtonViewer::changeView)
		->setEnterEvent(titleSceneManager, &TitleSceneManager::endGame);
	InputManager::addUI2DirEvent(endButton, &Button::selectChange);
	InputManager::addEnterKeyEvent(endButton, &Button::enter);
}