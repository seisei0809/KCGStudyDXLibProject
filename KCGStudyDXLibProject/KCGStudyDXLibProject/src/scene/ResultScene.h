#pragma once
#include "IScene.h"
#include "scene_manager/ResultSceneManager.h"
#include "ui/Button.h"
#include "ui/ButtonViewer.h"

class ResultScene : public IScene{
public:

	/// <summary>
	/// オブジェクト配置場所
	/// </summary>
	void setGameObject() override;

	/// <summary>
	/// シーン破棄時に呼び出される
	/// </summary>
	void destroy() override;

private:

	// リザルト管理
	ResultSceneManager* _resultSceneManager;
	// リトライボタン
	Button* _retryButton;
	// タイトルボタン
	Button* _titleButton;
	// リトライボタン表示用
	ButtonViewer* _retryButtonViewer;
	// タイトルボタン表示用
	ButtonViewer* _titleButtonViewer;
};

