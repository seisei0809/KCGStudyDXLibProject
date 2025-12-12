#pragma once

namespace Utility {

	/// <summary>
	/// イベントシステム
	/// </summary>
	/// <typeparam name="Args">可変長引数の型</typeparam>
	template<typename... Args>
	class Event {
	public:

		/// <summary>
		/// 関数ポインタのエイリアス
		/// </summary>
		using HandlerType = void(*)(Args...);

		/// <summary>
		/// ハンドラーを追加
		/// </summary>
		/// <param name="target">追加ターゲット</param>
		void operator+=(HandlerType target) {

			_handlers.emplace_back(target);
		}

		/// <summary>
		/// ハンドラーを削除
		/// </summary>
		/// <param name="target">削除ターゲット</param>
		void operator-=(HandlerType target) {

			for (auto it = _handlers.begin(); it != _handlers.end(); it++) {

				if (*it == target) {

					// 削除してリターン
					_handlers.erase(it);
					return;
				}
			}
		}

		/// <summary>
		/// 登録されているすべてのハンドラーを実行
		/// </summary>
		/// <param name="...args">複数引数</param>
		void invoke(Args... args) {

			for (auto handler : _handlers) {

				handler(args...);
			}
		}

		/// <summary>
		/// すべてのハンドラーをクリア
		/// </summary>
		void clear() {

			_handlers.clear();
		}

	private:

		/// <summary>
		/// 全ハンドラーを配列管理
		/// </summary>
		std::vector<HandlerType> _handlers;
	};

}