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
/// コンストラクタ
/// </summary>
TitleScene::TitleScene()
	:titleSceneManager(nullptr),
	startButton(nullptr),
	endButton(nullptr) {

}

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
	startButtonViewer = startButtonObj->addComponent<ButtonViewer>();
	startButton = startButtonObj->addComponent<Button>()
		->setIsSelect(true)
		->setUpButton(nullptr)
		->setDownButton(&endButton)
		->setSelectChangeEvent(startButtonViewer,&ButtonViewer::changeView)
		->setEnterEvent(titleSceneManager, &TitleSceneManager::startGame);
	InputManager::addUI2DirEvent(startButton, &Button::selectChange);
	InputManager::addEnterKeyEvent(startButton, &Button::enter);

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
	endButtonViewer = endButtonObj->addComponent<ButtonViewer>();
	endButton = endButtonObj->addComponent<Button>()
		->setUpButton(&startButton)
		->setDownButton(nullptr)
		->setSelectChangeEvent(endButtonViewer,&ButtonViewer::changeView)
		->setEnterEvent(titleSceneManager, &TitleSceneManager::endGame);
	InputManager::addUI2DirEvent(endButton, &Button::selectChange);
	InputManager::addEnterKeyEvent(endButton, &Button::enter);
}

/// <summary>
/// シーン破棄時に呼び出される
/// </summary>
void TitleScene::destroy() {

	startButton->destroySelectChangeEvent(startButtonViewer, &ButtonViewer::changeView);
	startButton->destoryEnterEvent(titleSceneManager, &TitleSceneManager::startGame);
	endButton->destroySelectChangeEvent(endButtonViewer, &ButtonViewer::changeView);
	endButton->destoryEnterEvent(titleSceneManager, &TitleSceneManager::startGame);

	InputManager::removeUI2DirEvent(startButton, &Button::selectChange);
	InputManager::removeEnterKeyEvent(startButton, &Button::enter);
	InputManager::removeUI2DirEvent(endButton, &Button::selectChange);
	InputManager::removeEnterKeyEvent(endButton, &Button::enter);
}