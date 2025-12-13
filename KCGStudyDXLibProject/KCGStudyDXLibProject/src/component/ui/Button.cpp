#include "stdafx.h"
#include "Button.h"

/// <summary>
/// コンストラクタ
/// </summary>
Button::Button()
	:_isSelect(false),
	_upButton(nullptr),
	_downButton(nullptr) {

}

/// <summary>
/// 初期化時実行
/// </summary>
void Button::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void Button::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void Button::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void Button::destroy() {

}

/// <summary>
/// 選択状態のセット
/// </summary>
/// <param name="isSelect">trueなら選択している</param>
/// <returns>メソッドチェーン用</returns>
Button* Button::setIsSelect(const bool isSelect) {

	_isSelect = isSelect;
	return this;
}

/// <summary>
/// 上のボタンをセット
/// </summary>
/// <param name="upButton">上のボタン</param>
/// <returns>メソッドチェーン用</returns>
Button* Button::setUpButton(Button** upButton) {

	_upButton = upButton;
	return this;
}

/// <summary>
/// 下のボタンをセット
/// </summary>
/// <param name="downButton">下のボタン</param>
/// <returns>メソッドチェーン用</returns>
Button* Button::setDownButton(Button** downButton) {

	_downButton = downButton;
	return this;
}

/// <summary>
/// 選択状態変更監視用
/// </summary>
/// <param name="handler">登録したい関数</param>
/// <returns>メソッドチェーン用</returns>
Button& Button::setSelectChangeEvent(void (*handler)(bool)) {

	_onSelectChangeEvent += handler;
	return *this;
}

/// <summary>
/// 選択状態の変更
/// </summary>
/// <param name="up">上</param>
/// <param name="down">下</param>
void Button::selectChange(bool up, bool down) {

	// 上ボタンが押されていて、上ボタンが存在するなら
	if(up && _upButton) {

		_isSelect = false;
		_onSelectChangeEvent.invoke(_isSelect);
		(*_upButton)->setIsSelect(true);
		(*_upButton)->_onSelectChangeEvent.invoke(true);
	}
	// 下ボタンが押されていて、下ボタンが存在するなら
	else if (down && _downButton) {

		_isSelect = false;
		_onSelectChangeEvent.invoke(_isSelect);
		(*_downButton)->setIsSelect(true);
		(*_downButton)->_onSelectChangeEvent.invoke(true);
	}
}