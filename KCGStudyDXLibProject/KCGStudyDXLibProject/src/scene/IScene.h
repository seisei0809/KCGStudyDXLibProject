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
	/// オブジェクト配置場所
	/// </summary>
	virtual void setGameObject() = 0;

	/// <summary>
	/// シーン破棄時に呼び出される
	/// </summary>
	virtual void destroy() = 0;
};

