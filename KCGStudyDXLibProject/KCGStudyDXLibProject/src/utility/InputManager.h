#pragma once
#include "stdafx.h"

namespace Utility {

	class InputManager {
	public:

		/// <summary>
		/// 入力状態を更新する
		/// </summary>
		static void update();

		/// <summary>
		/// UI操作の上入力を取得する
		/// </summary>
		/// <returns>押してるならtrue</returns>
		static const bool getUIUpButton();

		/// <summary>
		/// UI操作の下入力を取得する
		/// </summary>
		/// <returns>押してるならtrue</returns>
		static const bool getUIDownButton();

		/// <summary>
		/// ゲーム操作の上入力を取得する
		/// </summary>
		/// <returns>押してるならtrue</returns>
		static const bool getUpButton();

		/// <summary>
		/// ゲーム操作の下入力を取得する
		/// </summary>
		/// <returns>押してるならtrue</returns>
		static const bool getDownButton();

		/// <summary>
		/// ゲーム操作の右入力を取得する
		/// </summary>
		/// <returns>押してるならtrue</returns>
		static const bool getRightButton();

		/// <summary>
		/// ゲーム操作の左入力を取得する
		/// </summary>
		/// <returns>押してるならtrue</returns>
		static const bool getLeftButton();

		/// <summary>
		/// ゲーム操作のダッシュ入力を取得する
		/// </summary>
		/// <returns>押してるならtrue</returns>
		static const bool getDashButton();

		/// <summary>
		/// ゲーム操作のジャンプ入力を取得する
		/// </summary>
		/// <returns>押してるならtrue</returns>
		static const bool getJumpButton();

		/// <summary>
		/// UI操作の上入力がそのフレームで押されたか
		/// </summary>
		/// <returns>そのフレームで押してるならtrue</returns>
		static const bool getUIUpButtonDown();

		/// <summary>
		/// UI操作の下入力がそのフレームで押されたか
		/// </summary>
		/// <returns>そのフレームで押してるならtrue</returns>
		static const bool getUIDownButtonDown();

		/// <summary>
		/// ゲーム操作のジャンプ入力がそのフレームで押されたか
		/// </summary>
		/// <returns>そのフレームで押してるならtrue</returns>
		static const bool getJumpButtonDown();

	private:
		// 前フレームのキー状態
		static char _prevKey[256];

		// 現在のキー状態
		static char _currKey[256];
	};

}