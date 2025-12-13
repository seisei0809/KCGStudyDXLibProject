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
		/// デストラクタ
		/// </summary>
		~Event() {

			// 全部破棄
			for (auto it = _handlers.begin(); it != _handlers.end(); it++) {

				delete *it;
			}
			_handlers.clear();
		}

		/// <summary>
		/// イベントに追加
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数ポインタ</param>
		template<typename T>
		void add(T* object, void (T::* method)(Args...)) {

			// ハンドラーを生成して登録
			auto* h = new Handler<T>();
			h->object = object;
			h->method = method;

			_handlers.emplace_back(h);
		}

		/// <summary>
		/// イベントから削除する
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		/// <param name="object">インスタンス</param>
		/// <param name="method">メンバ関数ポインタ</param>
		template<typename T>
		void remove(T* object, void (T::* method)(Args...)) {

			// 探す
			for (auto it = _handlers.begin(); it != _handlers.end(); it++) {
				
				// キャスト成功したら進む
				auto* h = dynamic_cast<Handler<T>*>(it);
				if (!h.equals(object,method)) continue;

				// 消す
				it = _handlers.erase(it);
				delete it;
				return;
			}
		}

		/// <summary>
		/// 登録されているすべてのハンドラーを実行
		/// </summary>
		/// <param name="...args">複数引数</param>
		void invoke(Args... args) {

			for (auto& h : _handlers) {

				h->invoke(args...);
			}
		}

	private:

		/// <summary>
		/// ハンドラーの基底(vectorであらゆる関数を管理するため)
		/// </summary>
		struct HandlerBase {

			/// <summary>
			/// 関数実行
			/// </summary>
			/// <param name="...args">複数引数</param>
			virtual void invoke(Args... args) = 0;
		};

		/// <summary>
		/// ハンドラー
		/// </summary>
		/// <typeparam name="T">インスタンスの型</typeparam>
		template<typename T>
		struct Handler : HandlerBase {

			/// <summary>
			/// 関数実行
			/// </summary>
			/// <param name="...args">複数引数</param>
			void invoke(Args... args) override {

				(object->*method)(args...);
			}

			/// <summary>
			/// 引数に入れたものと等価か調べる
			/// </summary>
			/// <param name="obj">インスタンス</param>
			/// <param name="m">メンバ関数ポインタ</param>
			/// <returns>等価ならtrue</returns>
			bool equals(T* obj, void (T::* m)(Args...)) const {

				return object == obj && method == m;
			}

			// インスタンス
			T* object;
			// メンバ関数ポインタ
			void (T::* method)(Args...);
		};

		/// <summary>
		/// 全ハンドラーを配列管理
		/// </summary>
		std::vector<HandlerBase*> _handlers;
	};

}