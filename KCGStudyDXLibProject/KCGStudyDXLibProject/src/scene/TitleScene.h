#pragma once
#include "IScene.h"

class TitleScene : public IScene{
public:

	/// <summary>
	/// シーン開始時処理
	/// </summary>
	void start() override;

	/// <summary>
	/// シーン破棄時処理
	/// </summary>
	void destroy() override;
};

