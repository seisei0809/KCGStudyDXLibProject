#include "stdafx.h"
#include "UIText.h"

/// <summary>
/// コンストラクタ
/// </summary>
UIText::UIText()
	: IUIRenderer()
	, _text()
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

	// 回転角度を取得
	float rotationRad = _GetRotationRadian();

	// フォントハンドルを作成・更新
	if (_fontHandle == -1 && _preUIScale != _uiScale) {

		_preUIScale = _uiScale;
		if (_fontHandle != -1) {

			DeleteFontToHandle(_fontHandle);
		}
		_fontHandle = CreateFontToHandle(nullptr, static_cast<int>(_uiScale), -1, DX_FONTTYPE_ANTIALIASING);
	}

	// テキストサイズ取得
	int textWidth = GetDrawStringWidthToHandle(_text.c_str(), static_cast<int>(_text.size()), _fontHandle);
	int textHeight = GetFontSizeToHandle(_fontHandle);

	// 画面座標を取得
	float screenX, screenY;
	_GetScreenPosition(screenX, screenY, static_cast<float>(textWidth), static_cast<float>(textHeight));
	_GetScreenPosition(screenX, screenY, static_cast<float>(textWidth), static_cast<float>(textHeight));

	// 回転中心を設定
	float rotaCenterX = textWidth / 2.0f;
	float rotaCenterY = textHeight / 2.0f;

	// 回転ありでテキスト描画
	DrawRotaStringToHandle(
		static_cast<int>(screenX),
		static_cast<int>(screenY),
		1,
		1, 
		rotaCenterX,
		rotaCenterY,
		rotationRad,
		_color,
		_fontHandle,
		0,
		0,
		_text.c_str()
	);
}