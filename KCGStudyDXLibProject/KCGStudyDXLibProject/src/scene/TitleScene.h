#pragma once
#include "IScene.h"
#include "ui/Button.h"
#include "ui/ButtonViewer.h"
#include "scene_manager/TitleSceneManager.h"

/// <summary>
/// タイトルシーン
/// </summary>
class TitleScene : public IScene{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleScene();

	/// <summary>
	/// オブジェクト配置場所
	/// </summary>
	void setGameObject() override;

	/// <summary>
	/// シーン破棄時に呼び出される
	/// </summary>
	void destroy() override;

private:
	// タイトル管理
	TitleSceneManager* _titleSceneManager;
	// スタートボタン
	Button* _startButton;
	// 終了ボタン
	Button* _endButton;
	// スタートボタン表示用
	ButtonViewer* _startButtonViewer;
	// 終了ボタン表示用
	ButtonViewer* _endButtonViewer;
};

