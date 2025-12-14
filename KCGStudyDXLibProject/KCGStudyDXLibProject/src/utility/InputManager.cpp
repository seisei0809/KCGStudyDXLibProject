#include "stdafx.h"
#include "InputManager.h"

using namespace Utility;

Event<bool, bool> InputManager::_uiDir2DownEvent;
Event <bool, bool, bool, bool> InputManager::_dir4Event;
Event<bool> InputManager::_jumpEvent;
Event<bool> InputManager::_enterKeyEvent;
char InputManager::_prevKey[256] = { 0 };
char InputManager::_currKey[256] = { 0 };

/// <summary>
/// 入力状態を更新する
/// </summary>
void InputManager::update() {

	// 前回の入力を更新
	if (_currKey) {

		for (int i = 0; i < 256; i++) {

			_prevKey[i] = _currKey[i];
		}
	}
	// 現在の入力を取得
	GetHitKeyStateAll(_currKey);

	// UI操作の上下入力イベント発火
	if(_currKey[KEY_INPUT_UP] != _prevKey[KEY_INPUT_UP] ||
		_currKey[KEY_INPUT_DOWN] != _prevKey[KEY_INPUT_DOWN]) {

		_uiDir2DownEvent.invoke(_currKey[KEY_INPUT_UP], _currKey[KEY_INPUT_DOWN]);
	}
	// ゲーム操作の4方向入力イベント発火
	if (_currKey[KEY_INPUT_W] != _prevKey[KEY_INPUT_W] ||
		_currKey[KEY_INPUT_S] != _prevKey[KEY_INPUT_S] ||
		_currKey[KEY_INPUT_D] != _prevKey[KEY_INPUT_D] ||
		_currKey[KEY_INPUT_A] != _prevKey[KEY_INPUT_A]) {

		_dir4Event.invoke(
			_currKey[KEY_INPUT_W],
			_currKey[KEY_INPUT_S],
			_currKey[KEY_INPUT_D],
			_currKey[KEY_INPUT_A]);
	}
	// ジャンプボタンイベント発火
	if (_currKey[KEY_INPUT_SPACE] && !_prevKey[KEY_INPUT_SPACE]) {

		_jumpEvent.invoke(_currKey[KEY_INPUT_SPACE]);
	}
	// エンターキーイベント発火
	if (_currKey[KEY_INPUT_RETURN] && !_prevKey[KEY_INPUT_RETURN]) {

		_enterKeyEvent.invoke(_currKey[KEY_INPUT_RETURN]);
	}
}