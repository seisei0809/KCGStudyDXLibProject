#include "stdafx.h"
#include "InputManager.h"

using namespace Utility;

char InputManager::_prevKey[256] = { 0 };
char InputManager::_currKey[256] = { 0 };

/// <summary>
/// 入力状態を更新する
/// </summary>
void InputManager::update() {

	if (_currKey) {

		for (int i = 0; i < 256; i++) {

			_prevKey[i] = _currKey[i];
		}
	}
	GetHitKeyStateAll(_currKey);
}

/// <summary>
/// UI操作の上入力を取得する
/// </summary>
/// <returns>押してるならtrue</returns>
const bool InputManager::getUIUpButton() {

	return CheckHitKey(KEY_INPUT_UP);
}

/// <summary>
/// UI操作の下入力を取得する
/// </summary>
/// <returns>押してるならtrue</returns>
const bool InputManager::getUIDownButton() {

	return CheckHitKey(KEY_INPUT_DOWN);
}

/// <summary>
/// ゲーム操作の上入力を取得する
/// </summary>
/// <returns>押してるならtrue</returns>
const bool InputManager::getUpButton() {

	return CheckHitKey(KEY_INPUT_UP);
}

/// <summary>
/// ゲーム操作の下入力を取得する
/// </summary>
/// <returns>押してるならtrue</returns>
const bool InputManager::getDownButton() {

	return CheckHitKey(KEY_INPUT_DOWN);
}

/// <summary>
/// ゲーム操作の右入力を取得する
/// </summary>
/// <returns>押してるならtrue</returns>
const bool InputManager::getRightButton() {

	return CheckHitKey(KEY_INPUT_RIGHT);
}

/// <summary>
/// ゲーム操作の左入力を取得する
/// </summary>
/// <returns>押してるならtrue</returns>
const bool InputManager::getLeftButton() {

	return CheckHitKey(KEY_INPUT_LEFT);
}

/// <summary>
/// ゲーム操作のダッシュ入力を取得する
/// </summary>
/// <returns>押してるならtrue</returns>
const bool InputManager::getDashButton() {

	return CheckHitKey(KEY_INPUT_LSHIFT);
}

/// <summary>
/// ゲーム操作のジャンプ入力を取得する
/// </summary>
/// <returns>押してるならtrue</returns>
const bool InputManager::getJumpButton() {

	return _currKey[KEY_INPUT_SPACE];
}

/// <summary>
/// UI操作の上入力がそのフレームで押されたか
/// </summary>
/// <returns>そのフレームで押してるならtrue</returns>
const bool InputManager::getUIUpButtonDown() {

	return _currKey[KEY_INPUT_UP] && !_prevKey[KEY_INPUT_UP];
}

/// <summary>
/// UI操作の下入力がそのフレームで押されたか
/// </summary>
/// <returns>そのフレームで押してるならtrue</returns>
const bool InputManager::getUIDownButtonDown() {

	return _currKey[KEY_INPUT_DOWN] && !_prevKey[KEY_INPUT_DOWN];
}

/// <summary>
/// ゲーム操作のジャンプ入力がそのフレームで押されたか
/// </summary>
/// <returns>そのフレームで押してるならtrue</returns>
const bool InputManager::getJumpButtonDown() {

	return _currKey[KEY_INPUT_SPACE] && !_prevKey[KEY_INPUT_SPACE];
}