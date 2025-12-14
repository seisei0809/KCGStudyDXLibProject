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
	:_titleSceneManager(nullptr),
	_startButton(nullptr),
	_endButton(nullptr),
	_startButtonViewer(),
	_endButtonViewer(){

}

/// <summary>
/// オブジェクト配置場所
/// </summary>
void TitleScene::setGameObject() {

	// タイトル管理
	_titleSceneManager = GameObject::Builder()
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
	_startButtonViewer = startButtonObj->addComponent<ButtonViewer>();
	_startButton = startButtonObj->addComponent<Button>()
		->setIsSelect(true)
		->setUpButton(nullptr)
		->setDownButton(&_endButton)
		->setSelectChangeEvent(_startButtonViewer,&ButtonViewer::changeView)
		->setEnterEvent(_titleSceneManager, &TitleSceneManager::startGame);
	InputManager::addUI2DirEvent(_startButton, &Button::selectChange);
	InputManager::addEnterKeyEvent(_startButton, &Button::enter);

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
	_endButtonViewer = endButtonObj->addComponent<ButtonViewer>();
	_endButton = endButtonObj->addComponent<Button>()
		->setUpButton(&_startButton)
		->setDownButton(nullptr)
		->setSelectChangeEvent(_endButtonViewer,&ButtonViewer::changeView)
		->setEnterEvent(_titleSceneManager, &TitleSceneManager::endGame);
	InputManager::addUI2DirEvent(_endButton, &Button::selectChange);
	InputManager::addEnterKeyEvent(_endButton, &Button::enter);
}

/// <summary>
/// シーン破棄時に呼び出される
/// </summary>
void TitleScene::destroy() {

	_startButton->destroySelectChangeEvent(_startButtonViewer, &ButtonViewer::changeView);
	_startButton->destoryEnterEvent(_titleSceneManager, &TitleSceneManager::startGame);
	_endButton->destroySelectChangeEvent(_endButtonViewer, &ButtonViewer::changeView);
	_endButton->destoryEnterEvent(_titleSceneManager, &TitleSceneManager::endGame);

	InputManager::removeUI2DirEvent(_startButton, &Button::selectChange);
	InputManager::removeEnterKeyEvent(_startButton, &Button::enter);
	InputManager::removeUI2DirEvent(_endButton, &Button::selectChange);
	InputManager::removeEnterKeyEvent(_endButton, &Button::enter);
}