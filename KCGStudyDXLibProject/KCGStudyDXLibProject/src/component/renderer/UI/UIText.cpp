#include "stdafx.h"
#include "UIText.h"

/// <summary>
/// コンストラクタ
/// </summary>
UIText::UIText()
	: IUIRenderer()
	, _text()
	, _fontSize(32)
	, _color(GetColor(255, 255, 255))
	, _fontHandle(-1) {

}

/// <summary>
/// 文字をセットする
/// </summary>
/// <param name="text">文字</param>
/// <returns>メソッドチェーン用</returns>
UIText* UIText::setText(const std::wstring& text) {

	_text = text;
	return this;
}

/// <summary>
/// フォントの大きさをセットする
/// </summary>
/// <param name="size">大きさ</param>
/// <returns>メソッドチェーン用</returns>
UIText* UIText::setFontSize(int size) {

	_fontSize = size;
	return this;
}

/// <summary>
/// 文字の色をセットする
/// </summary>
/// <param name="color">色(GetColor)</param>
/// <returns>メソッドチェーン用</returns>
UIText* UIText::setColor(unsigned int color) {

	_color = color;
	return this;
}

/// <summary>
/// 初期化時実行
/// </summary>
void UIText::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void UIText::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void UIText::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void UIText::destroy() {

	if (_fontHandle != -1) {

		DeleteFontToHandle(_fontHandle);
		_fontHandle = -1;
	}
}

/// <summary>
/// 描画実行
/// </summary>
void UIText::render() {

	if (_text.empty()) return;

	// 画面座標を取得
	float screenX, screenY;
	_GetScreenPosition(screenX, screenY);

	// 回転角度を取得
	float rotationRad = _GetRotationRadian();

	// スケールを適用したフォントサイズ
	int scaledFontSize = static_cast<int>(_fontSize * _uiScale);

	// フォントハンドルを作成・更新
	if (_fontHandle == -1 || GetFontSizeToHandle(_fontHandle) != scaledFontSize) {

		if (_fontHandle != -1) {

			DeleteFontToHandle(_fontHandle);
		}
		_fontHandle = CreateFontToHandle(nullptr, scaledFontSize, -1, DX_FONTTYPE_ANTIALIASING);
	}

	// テキストサイズ取得
	int textWidth = GetDrawStringWidthToHandle(_text.c_str(), _text.size(), _fontHandle);
	int textHeight = GetFontSizeToHandle(_fontHandle);

	// 基準点オフセット
	float offsetX = 0.0f;
	float offsetY = 0.0f;
	// 中心なら中心にオフセット
	if (_isCenter) {

		offsetX = textWidth / 2.0f;
		offsetY = textHeight / 2.0f;
	}

	// 回転ありでテキスト描画
	DrawRotaStringToHandle(
		static_cast<int>(screenX),
		static_cast<int>(screenY),
		1.0, 1.0, 
		offsetX, offsetY,
		rotationRad,
		_color,
		_fontHandle,
		0,
		0,
		_text.c_str()
	);
}