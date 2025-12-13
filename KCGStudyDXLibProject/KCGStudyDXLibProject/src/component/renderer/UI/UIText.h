#pragma once
#include "IUIRenderer.h"
#include <string>

/// <summary>
/// UIテキスト描画
/// </summary>
class UIText : public IUIRenderer {
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	UIText();

	/// <summary>
	/// 文字をセットする
	/// </summary>
	/// <param name="text">文字</param>
	/// <returns>メソッドチェーン用</returns>
	UIText* setText(const std::wstring& text);

	/// <summary>
	/// 文字の色をセットする
	/// </summary>
	/// <param name="color">色(GetColor)</param>
	/// <returns>メソッドチェーン用</returns>
	UIText* setColor(unsigned int color);

	/// <summary>
	/// 初期化時実行
	/// </summary>
	void start()override;

	/// <summary>
	/// 毎フレーム実行
	/// </summary>
	void update()override;

	/// <summary>
	/// 固定間隔で実行
	/// </summary>
	void fixedUpdate()override;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	void destroy() override;

	/// <summary>
	/// 描画実行
	/// </summary>
	void render() override;

private:

	// 表示テキスト
	std::wstring _text;
	// 色
	unsigned int _color;
	// フォントハンドル
	int _fontHandle;
};