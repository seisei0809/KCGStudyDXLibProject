#pragma once
#include "IScene.h"

class GameScene : public IScene{
public:

	/// <summary>
	/// オブジェクト配置場所
	/// </summary>
	void setGameObject() override;

	/// <summary>
	/// シーン破棄時に呼び出される
	/// </summary>
	void destroy() override;
};

