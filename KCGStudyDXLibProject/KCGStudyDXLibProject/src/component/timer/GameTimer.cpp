#include "stdafx.h"
#include "GameTimer.h"
#include "logic/result/ResultParameter.h"
#include "TimeManager.h"

using namespace Utility;

/// <summary>
/// コンストラクタ
/// </summary>
GameTimer::GameTimer()
	:_uiText(nullptr){

}

/// <summary>
/// 初期化時実行
/// </summary>
void GameTimer::start() {

	// 初期化
	_uiText = _gameObject->getComponent<UIText>();
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void GameTimer::update() {

	// 経過時間の更新
	float time = ResultParameter::setElapsedTime(ResultParameter::getElapsedTime() + static_cast<float>(TimeManager::deltaTime()));
	
	// UIテキストの更新
	if (_uiText) {

		int minutes = static_cast<int>(time) / 60;
		int seconds = static_cast<int>(time) % 60;
		std::wstring result = L""+(minutes < 10 ? std::to_wstring(0) : L"") + std::to_wstring(minutes) +
			L":" + (seconds < 10 ? std::to_wstring(0) : L"") + std::to_wstring(seconds);
		_uiText->setText(result);
	}
}

/// <summary>
/// 固定間隔で実行
/// </summary>
void GameTimer::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void GameTimer::destroy() {

}