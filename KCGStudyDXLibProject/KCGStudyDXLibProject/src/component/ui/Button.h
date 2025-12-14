#pragma once
#include "IComponent.h"
#include "utility/Event.h"

/// <summary>
/// ボタン
/// </summary>
class Button : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Button();

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
	void fixedUpdate()override;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	void destroy() override;

	/// <summary>
	/// 選択状態のセット
	/// </summary>
	/// <param name="isSelect">trueなら選択している</param>
	/// <returns>メソッドチェーン用</returns>
	Button* setIsSelect(const bool isSelect);

	/// <summary>
	/// 上のボタンをセット
	/// </summary>
	/// <param name="upButton">上のボタン</param>
	/// <returns>メソッドチェーン用</returns>
	Button* setUpButton(Button** upButton);

	/// <summary>
	/// 下のボタンをセット
	/// </summary>
	/// <param name="downButton">下のボタン</param>
	/// <returns>メソッドチェーン用</returns>
	Button* setDownButton(Button** downButton);

	/// <summary>
	/// 選択状態変更監視用追加
	/// </summary>
	/// <typeparam name="T">型</typeparam>
	/// <param name="obj">インスタンス</param>
	/// <param name="method">関数</param>
	/// <returns>メソッドチェーン用</returns>
	template<class T>
	Button* setSelectChangeEvent(T* obj, void (T::* method)(bool)) {

		_onSelectChangeEvent.add(obj, method);
		return this;
	}

	/// <summary>
	/// 選択状態変更監視用破棄
	/// </summary>
	/// <typeparam name="T">型</typeparam>
	/// <param name="obj">インスタンス</param>
	/// <param name="method">関数</param>
	/// <returns>メソッドチェーン用</returns>
	template<class T>
	Button* destroySelectChangeEvent(T* obj, void (T::* method)(bool)) {

		_onSelectChangeEvent.remove(obj, method);
		return this;
	}

	/// <summary>
	/// エンター状態変更監視用追加
	/// </summary>
	/// <typeparam name="T">型</typeparam>
	/// <param name="obj">インスタンス</param>
	/// <param name="method">関数</param>
	/// <returns>メソッドチェーン用</returns>
	template<class T>
	Button* setEnterEvent(T* obj, void (T::* method)(bool)) {

		_onEnterEvent.add(obj, method);
		return this;
	}

	/// <summary>
	/// エンター状態変更監視用破棄
	/// </summary>
	/// <typeparam name="T">型</typeparam>
	/// <param name="obj">インスタンス</param>
	/// <param name="method">関数</param>
	/// <returns>メソッドチェーン用</returns>
	template<class T>
	Button* destoryEnterEvent(T* obj, void (T::* method)(bool)) {

		_onEnterEvent.remove(obj, method);
		return this;
	}

	/// <summary>
	/// 選択状態の変更
	/// </summary>
	/// <param name="up">上</param>
	/// <param name="down">下</param>
	void selectChange(bool up,bool down);

	/// <summary>
	/// エンターしたかどうか
	/// </summary>
	/// <param name="isEnter">trueならエンターした</param>
	void enter(bool isEnter);

private:

	// 選択されているかどうか
	bool _isSelect;
	// 上のボタンへのポインタ
	Button** _upButton;
	// 下のボタンへのポインタ
	Button** _downButton;
	// 選択状態の変更がかかった時に起動するイベント
	Utility::Event<bool> _onSelectChangeEvent;
	// エンターがかかった時に起動するイベント
	Utility::Event<bool> _onEnterEvent;
};

