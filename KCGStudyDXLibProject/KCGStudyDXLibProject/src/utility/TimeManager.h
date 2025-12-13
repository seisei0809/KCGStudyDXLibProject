#pragma once

namespace Utility
{

	/// <summary>
	/// 時間管理
	/// </summary>
	class TimeManager{
	public:

		/// <summary>
		/// 前フレームからの経過時間を取得
		/// </summary>
		/// <returns>間隔時間(秒)</returns>
		static double deltaTime();

		/// <summary>
		/// 固定更新の間隔時間を取得
		/// Unity の Time.fixedDeltaTime 相当
		/// </summary>
		/// <returns>固定間隔時間(秒)</returns>
		static double fixedDeltaTime();

		/// <summary>
		/// ゲーム開始からの経過時間を取得
		/// </summary>
		/// <returns>経過時間(秒)</returns>
		static double time();

		/// <summary>
		/// フレーム更新
		/// </summary>
		/// <param name="deltaTime">間隔時間</param>
		static void update(double deltaTime);

		/// <summary>
		/// 固定更新の間隔時間を設定
		/// </summary>
		/// <param name="fixedDeltaTime">固定間隔時間(秒)</param>
		static void setFixedDeltaTime(double fixedDeltaTime);

		/// <summary>
		/// リセット
		/// </summary>
		static void reset();

	private:

		// 前フレームからの経過時間
		static double _deltaTime;
		// ゲーム開始からの経過時間
		static double _elapsedTime;
		// 固定更新の間隔時間
		static double _fixedDeltaTime;
	};

}