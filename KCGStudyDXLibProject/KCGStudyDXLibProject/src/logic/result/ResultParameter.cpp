#include "stdafx.h"
#include "ResultParameter.h"

float ResultParameter::_elapsedTime = 0.0f;

/// <summary>
/// 現在経過時間を取得する
/// </summary>
/// <returns>経過時間</returns>
float ResultParameter::getElapsedTime() {

	return _elapsedTime;
}

/// <summary>
/// 現在経過時間をセットする
/// </summary>
/// <param name="time">時間</param>
/// <returns>セットされた時間</returns>
float ResultParameter::setElapsedTime(const float time) {

	_elapsedTime = time;
	return _elapsedTime;
}

/// <summary>
/// リセットする
/// </summary>
void ResultParameter::reset() {

	_elapsedTime = 0.0f;
}