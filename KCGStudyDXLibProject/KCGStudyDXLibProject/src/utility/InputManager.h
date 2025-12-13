#pragma once
#include "stdafx.h"
#include "utility/Event.h"

namespace Utility {

	/// <summary>
	/// 入力管理
	/// </summary>
	class InputManager {
	public:

		/// <summary>
		/// 入力状態を更新する
		/// </summary>
		static void update();

		/// <summary>
		/// UI操作の上下入力イベントを登録する
		/// </summary>
		/// <param name="handler">(上下)入力変更されたら呼ばれる</param>
		static void registerUI2DirEvent(void(*handler)(bool,bool));

		/// <summary>
		/// ゲーム操作の4方向入力イベントを登録する
		/// </summary>
		/// <param name="handler">(上下右左)入力変更されたら呼ばれる</param>
		static void registerDir4Event(void(*handler)(bool,bool,bool,bool));

		/// <summary>
		/// ジャンプボタンイベントを登録する
		/// </summary>
		/// <param name="handler">入力変更されたら呼ばれる</param>
		static void registerJumpEvent(void(*handler)());


	private:

		// UI二方向入力イベント
		static Utility::Event<bool,bool> _uiDir2DownEvent;
		// 四方向入力イベント
		static Utility::Event <bool,bool,bool,bool> _dir4Event;
		// ジャンプ入力イベント
		static Utility::Event<> _jumpEvent;
		// 前フレームのキー状態
		static char _prevKey[256];
		// 現在のキー状態
		static char _currKey[256];
	};

}