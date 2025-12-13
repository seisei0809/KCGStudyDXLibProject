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
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数のポインタ</param>
		template<typename T>
		static void addUI2DirEvent(T* object, void (T::* method)(bool, bool)) {

			_uiDir2DownEvent.add(object, method);
		}

		/// <summary>
		/// ゲーム操作の4方向入力イベントを登録する
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数のポインタ</param>
		template<typename T>
		static void addDir4Event(T* object, void (T::* method)(bool, bool, bool, bool)) {

			_dir4Event.add(object, method);
		}

		/// <summary>
		/// ジャンプボタンイベントを登録する
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数のポインタ</param>
		template<typename T>
		static void addJumpEvent(T* object, void (T::* method)(bool)) {

			_jumpEvent.add(object, method);
		}

		/// <summary>
		/// スペースキーイベントを登録する
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数のポインタ</param>
		template<typename T>
		static void addEnterKeyEvent(T* object, void (T::* method)(bool)) {

			_enterKeyEvent.add(object, method);
		}

		/// <summary>
		/// UI操作の上下入力イベントを削除する
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数のポインタ</param>
		template<typename T>
		static void removeUI2DirEvent(T* object, void (T::* method)(bool, bool)) {

			_uiDir2DownEvent.remove(object, method);
		}

		/// <summary>
		/// ゲーム操作の4方向入力イベントを削除する
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数のポインタ</param>
		template<typename T>
		static void removeDir4Event(T* object, void (T::* method)(bool, bool, bool, bool)) {

			_dir4Event.remove(object, method);
		}

		/// <summary>
		/// ジャンプボタンイベントを削除する
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数のポインタ</param>
		template<typename T>
		static void removeJumpEvent(T* object, void (T::* method)(bool)) {

			_jumpEvent.remove(object, method);
		}

		/// <summary>
		/// スペースキーイベントを削除する
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数のポインタ</param>
		template<typename T>
		static void removeEnterKeyEvent(T* object, void (T::* method)(bool)) {

			_enterKeyEvent.remove(object, method);
		}

	private:

		// UI二方向入力イベント
		static Utility::Event<bool,bool> _uiDir2DownEvent;
		// 四方向入力イベント
		static Utility::Event <bool,bool,bool,bool> _dir4Event;
		// ジャンプ入力イベント
		static Utility::Event<bool> _jumpEvent;
		// エンターキー入力イベント
		static Utility::Event<bool> _enterKeyEvent;
		// 前フレームのキー状態
		static char _prevKey[256];
		// 現在のキー状態
		static char _currKey[256];
	};

}