#pragma once
#include "IComponent.h"
#include "renderer/ui/UIText.h"
#include "ui/Button.h"

/// <summary>
/// ボタンの見た目を決定する
/// </summary>
class ButtonViewer : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	ButtonViewer();

	/// <summary>
	/// 初期化時実行
	/// </summary>
	void start() override;

	/// <summary>
	/// 毎フレーム実行
	/// </summary>
	void update() override;

	/// <summary>
	/// 固定間隔で実行
	/// </summary>
	void fixedUpdate() override;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	void destroy() override;

	/// <summary>
	/// 見た目を変える
	/// </summary>
	/// <param name="isSelect">選択状態</param>
	void changeView(bool isSelect);

	/// <summary>
	/// 選択時の色を設定する
	/// </summary>
	/// <param name="selectColor">選択時の色</param>
	/// <returns>メソッドチェーン用</returns>
	ButtonViewer* setSelectColor(unsigned int selectColor);

	/// <summary>
	/// 非選択時の色を設定する
	/// </summary>
	/// <param name="nonSelectColor">非選択時の色</param>
	/// <returns>メソッドチェーン用</returns>
	ButtonViewer* setNonSelectColor(unsigned int nonSelectColor);

private:

	// ボタン
	Button* _button;
	// ボタンの状態を表示するテキスト
	UIText* _stateText;
	// 選択時の色
	unsigned int _selectColor;
	// 非選択時の色
	unsigned int _nonSelectColor;
};

