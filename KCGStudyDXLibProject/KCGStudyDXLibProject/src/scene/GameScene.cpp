#include "stdafx.h"
#include "GameScene.h"
#include "AllSettings.h"
#include "renderer/ui/UIText.h"
#include "timer/GameTimer.h"
#include "renderer/Model3D.h"
#include "camera/Camera.h"
#include "camera/CameraController.h"

using namespace AllEnumSpace;

/// <summary>
/// オブジェクト配置場所
/// </summary>
void GameScene::setGameObject() {

	// 経過時間
	GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, 0.0f, 0.0f))->addComponent<UIText>()
		->setText(L"経過時間 00:00")
		->setColor(GetColor(255, 0, 0))
		->setUIScale(50)
		->setAnchor(Anchor::TopLeft)
		->setLayer(100)
		->getGameObject()->addComponent<GameTimer>();

	// プレイヤー
	auto* player = GameObject::Builder()
		.setName("Player")
		.setTag(Tag::Player)
		.build()
		->setPosition(VGet(200,1000,200))
		->setScale(VGet(100, 100, 100))->addComponent<Model3D>()
		->loadModel(PLAYER_MODEL_PATH);

	// カメラ
	GameObject::Builder()
		.build()
		->setRotation(VGet(0, 20, 0))
		->addComponent<Camera>()
		->getGameObject()->addComponent<CameraController>()
		->setTarget(player->getGameObject())
		->setCameraOffset(VGet(0, 200, -500))
		->setTargetOffset(VGet(0, 150, 0));

	// ステージメイク
	GameObject::Builder()
		.build()
		->setPosition(VGet(0, -200, 0))
		->setScale(VGet(10000, 10, 10000))
		->addComponent<Model3D>()
		->loadModel(STAGE_MODEL_PATH);
}

/// <summary>
/// シーン破棄時に呼び出される
/// </summary>
void GameScene::destroy() {


}
