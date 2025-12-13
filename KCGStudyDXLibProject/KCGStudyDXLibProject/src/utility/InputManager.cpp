#include "stdafx.h"
#include "InputManager.h"

using namespace Utility;

Event<bool, bool> InputManager::_uiDir2DownEvent;
Event <bool, bool, bool, bool> InputManager::_dir4Event;
Event<> InputManager::_jumpEvent;
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
	if (_currKey[KEY_INPUT_UP] != _prevKey[KEY_INPUT_UP] ||
		_currKey[KEY_INPUT_DOWN] != _prevKey[KEY_INPUT_DOWN] ||
		_currKey[KEY_INPUT_RIGHT] != _prevKey[KEY_INPUT_RIGHT] ||
		_currKey[KEY_INPUT_LEFT] != _prevKey[KEY_INPUT_LEFT]) {

		_dir4Event.invoke(
			_currKey[KEY_INPUT_UP],
			_currKey[KEY_INPUT_DOWN],
			_currKey[KEY_INPUT_RIGHT],
			_currKey[KEY_INPUT_LEFT]);
	}
	// ジャンプボタンイベント発火
	if (_currKey[KEY_INPUT_SPACE] && !_prevKey[KEY_INPUT_SPACE]) {

		_jumpEvent.invoke();
	}
}

/// <summary>
/// UI操作の上下入力イベントを登録する
/// </summary>
/// <param name="handler">(上下)入力変更されたら呼ばれる</param>
void InputManager::registerUI2DirEvent(void(*handler)(bool, bool)) {

	_uiDir2DownEvent += handler;
}

/// <summary>
/// ゲーム操作の4方向入力イベントを登録する
/// </summary>
/// <param name="handler">(上下右左)入力変更されたら呼ばれる</param>
void InputManager::registerDir4Event(void(*handler)(bool, bool, bool, bool)) {

	_dir4Event += handler;
}

/// <summary>
/// ジャンプボタンイベントを登録する
/// </summary>
/// <param name="handler">入力変更されたら呼ばれる</param>
void InputManager::registerJumpEvent(void(*handler)()) {

	_jumpEvent += handler;
}