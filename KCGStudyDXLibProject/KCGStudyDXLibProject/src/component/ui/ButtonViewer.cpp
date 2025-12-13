#include "stdafx.h"
#include "ButtonViewer.h"

/// <summary>
/// コンストラクタ
/// </summary>
ButtonViewer::ButtonViewer()
	:_button(nullptr),
	_stateText(nullptr),
	_selectColor(GetColor(255, 0, 0)),
	_nonSelectColor(GetColor(128, 128, 128)) {

}

/// <summary>
/// 初期化時実行
/// </summary>
void ButtonViewer::start() {

	// 初期化
	_button = _gameObject->getComponent<Button>();
	_stateText = _gameObject->getComponent<UIText>();
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void ButtonViewer::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void ButtonViewer::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void ButtonViewer::destroy() {

}

/// <summary>
/// 見た目を変える
/// </summary>
/// <param name="isSelect">選択状態</param>
void ButtonViewer::changeView(bool isSelect) {

	_stateText->setColor(isSelect ? _selectColor : _nonSelectColor);
}

/// <summary>
/// 選択時の色を設定する
/// </summary>
/// <param name="selectColor">選択時の色</param>
/// <returns>メソッドチェーン用</returns>
ButtonViewer* ButtonViewer::setSelectColor(unsigned int selectColor) {

	_selectColor = selectColor;
	return this;
}

/// <summary>
/// 非選択時の色を設定する
/// </summary>
/// <param name="nonSelectColor">非選択時の色</param>
/// <returns>メソッドチェーン用</returns>
ButtonViewer* ButtonViewer::setNonSelectColor(unsigned int nonSelectColor) {

	_nonSelectColor = nonSelectColor;
	return this;
}