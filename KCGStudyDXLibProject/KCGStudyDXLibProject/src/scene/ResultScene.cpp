#include "stdafx.h"
#include "ResultScene.h"
#include "renderer/ui/UIText.h"
#include "result/ResultParameter.h"
#include "InputManager.h"

using namespace Utility;
using namespace AllEnumSpace;

/// <summary>
/// オブジェクト配置場所
/// </summary>
void ResultScene::setGameObject() {

	// リザルトテキスト
	GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, -150.0f, 0.0f))->addComponent<UIText>()
		->setText(L"リザルト")
		->setColor(GetColor(255, 0, 0))
		->setUIScale(80)
		->setAnchor(Anchor::MiddleCenter)
		->setLayer(100);

	// 結果表示テキスト
	auto time = ResultParameter::getElapsedTime();
	int minutes = static_cast<int>(time) / 60;
	int seconds = static_cast<int>(time) % 60;
	std::wstring result = L"" + (minutes < 10 ? std::to_wstring(0) : L"") + std::to_wstring(minutes) +
		L":" + (seconds < 10 ? std::to_wstring(0) : L"") + std::to_wstring(seconds);
	GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, 0.0f, 0.0f))->addComponent<UIText>()
		->setText(result)
		->setColor(GetColor(255,0,0))
		->setUIScale(70)
		->setAnchor(AllEnumSpace::Anchor::MiddleCenter)
		->setLayer(100);

	// リトライボタン
	auto* const retryButtonObj = GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, 100.0f, 0.0f))
		->addComponent<UIText>()
		->setText(L"もういっかい")
		->setColor(GetColor(255, 0, 0))
		->setUIScale(30)
		->setAnchor(Anchor::MiddleCenter)
		->setLayer(100)
		->getGameObject();
	_retryButtonViewer = retryButtonObj->addComponent<ButtonViewer>();
	_retryButton = retryButtonObj->addComponent<Button>()
		->setIsSelect(true)
		->setUpButton(nullptr)
		->setDownButton(&_titleButton)
		->setSelectChangeEvent(_retryButtonViewer, &ButtonViewer::changeView)
		->setEnterEvent(_resultSceneManager, &ResultSceneManager::retry);
	InputManager::addUI2DirEvent(_retryButton, &Button::selectChange);
	InputManager::addEnterKeyEvent(_retryButton, &Button::enter);

	// タイトルボタン
	auto* const titleButtonObj = GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, 200.0f, 0.0f))
		->addComponent<UIText>()
		->setText(L"たいとるへ")
		->setColor(GetColor(128, 128, 128))
		->setUIScale(30)
		->setAnchor(Anchor::MiddleCenter)
		->setLayer(100)
		->getGameObject();
	_titleButtonViewer = titleButtonObj->addComponent<ButtonViewer>();
	_titleButton = titleButtonObj->addComponent<Button>()
		->setIsSelect(false)
		->setUpButton(&_retryButton)
		->setDownButton(nullptr)
		->setSelectChangeEvent(_titleButtonViewer, &ButtonViewer::changeView)
		->setEnterEvent(_resultSceneManager, &ResultSceneManager::tilteBack);
	InputManager::addUI2DirEvent(_titleButton, &Button::selectChange);
	InputManager::addEnterKeyEvent(_titleButton, &Button::enter);
}

/// <summary>
/// シーン破棄時に呼び出される
/// </summary>
void ResultScene::destroy() {

	_retryButton->destroySelectChangeEvent(_retryButtonViewer, &ButtonViewer::changeView);
	_retryButton->destoryEnterEvent(_resultSceneManager, &ResultSceneManager::retry);
	_titleButton->destroySelectChangeEvent(_titleButtonViewer, &ButtonViewer::changeView);
	_titleButton->destoryEnterEvent(_resultSceneManager, &ResultSceneManager::tilteBack);

	InputManager::removeUI2DirEvent(_retryButton, &Button::selectChange);
	InputManager::removeEnterKeyEvent(_retryButton, &Button::enter);
	InputManager::removeUI2DirEvent(_titleButton, &Button::selectChange);
	InputManager::removeEnterKeyEvent(_titleButton, &Button::enter);
}
