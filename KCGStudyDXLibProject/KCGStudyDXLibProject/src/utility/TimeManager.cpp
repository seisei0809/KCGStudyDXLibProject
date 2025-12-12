#include "stdafx.h"
#include "TimeManager.h"

using namespace Utility;

double TimeManager::_deltaTime = 0.0f;
double TimeManager::_elapsedTime = 0.0f;
double TimeManager::_fixedDeltaTime = 1.0 / 60.0;

/// <summary>
/// 前フレームからの経過時間を取得
/// </summary>
/// <returns>間隔時間(秒)</returns>
double TimeManager::deltaTime() {

	return _deltaTime;
}

/// <summary>
/// 固定更新の間隔時間を取得
/// </summary>
/// <returns>固定間隔時間(秒)</returns>
double TimeManager::fixedDeltaTime() {

	return _fixedDeltaTime;
}

/// <summary>
/// ゲーム開始からの経過時間を取得
/// </summary>
/// <returns>経過時間(秒)</returns>
double TimeManager::time() {

	return _elapsedTime;
}

/// <summary>
/// フレーム更新
/// </summary>
/// <param name="deltaTime">間隔時間</param>
void TimeManager::update(double deltaTime) {

	_deltaTime = deltaTime;
	_elapsedTime += deltaTime;
}

/// <summary>
/// 固定更新の間隔時間を設定
/// </summary>
/// <param name="fixedDeltaTime">固定間隔時間(秒)</param>
void TimeManager::setFixedDeltaTime(double fixedDeltaTime) {

	_fixedDeltaTime = fixedDeltaTime;
}

/// <summary>
/// リセット
/// </summary>
void TimeManager::reset() {

	_deltaTime = 0.0f;
	_elapsedTime = 0.0f;
}