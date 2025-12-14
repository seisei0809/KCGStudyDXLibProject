#pragma once

/// <summary>
/// リザルトに必要なパラメータ
/// </summary>
class ResultParameter {
public:

	/// <summary>
	/// 現在経過時間を取得する
	/// </summary>
	/// <returns></returns>
	static float getElapsedTime();

	/// <summary>
	/// 現在経過時間をセットする
	/// </summary>
	/// <param name="time">時間</param>
	/// <returns>セットされた時間</returns>
	static float setElapsedTime(const float time);

private:

	// 経過時間
	static float _elapsedTime;
};