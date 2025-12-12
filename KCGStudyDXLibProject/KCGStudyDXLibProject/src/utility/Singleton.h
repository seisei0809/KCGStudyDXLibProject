#pragma once

namespace Utility {

	/// <summary>
	/// シングルトン基底
	/// </summary>
	/// <typeparam name="T">シングルトンにしたい型</typeparam>
	template<typename T>
	class Singleton {
	public:

		/// <summary>
		/// シングルトンインスタンスを取得
		/// </summary>
		static T& getInstance() {
			static T instance;
			return instance;
		}
	};
}
