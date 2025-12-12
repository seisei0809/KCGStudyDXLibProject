#pragma once

/// <summary>
/// シーン基底
/// </summary>
class IScene{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	IScene() = default;

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~IScene() = default;

	/// <summary>
	/// シーン開始時処理
	/// </summary>
	virtual void start() = 0;

	/// <summary>
	/// シーン破棄時処理
	/// </summary>
	virtual void destroy() = 0;
};

