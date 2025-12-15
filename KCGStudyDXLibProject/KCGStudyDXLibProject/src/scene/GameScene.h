#pragma once
#include "IScene.h"
#include "scene_manager/GameSceneManager.h"
#include "player/PlayerLifeManager.h"

class GameScene : public IScene{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameScene();

	/// <summary>
	/// オブジェクト配置場所
	/// </summary>
	void setGameObject() override;

	/// <summary>
	/// シーン破棄時に呼び出される
	/// </summary>
	void destroy() override;

private:

	// ゲームシーン管理
	GameSceneManager* _gameSceneManager;
	// プレイヤーライフ管理
	PlayerLifeManager* _playerLifeManager;
	// プレイヤー
	GameObject* _playerObj;
};

