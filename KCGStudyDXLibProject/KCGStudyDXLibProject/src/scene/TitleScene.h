#pragma once
#include "IScene.h"
#include "ui/Button.h"
#include "scene_manager/TitleSceneManager.h"

class TitleScene : public IScene{
public:

	/// <summary>
	/// オブジェクト配置場所
	/// </summary>
	void setGameObject() override;

	// タイトル管理
	TitleSceneManager* titleSceneManager;
	// スタートボタン
	Button* startButton;
	// 終了ボタン
	Button* endButton;
};

