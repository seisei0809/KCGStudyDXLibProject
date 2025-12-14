#include "stdafx.h"
#include "GameScene.h"
#include "AllSettings.h"
#include "renderer/ui/UIText.h"
#include "timer/GameTimer.h"
#include "renderer/Model3D.h"
#include "camera/Camera.h"
#include "camera/CameraController.h"
#include "collider/AABBCollider.h"
#include "physics/NormalPhysics.h"

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
		->setPosition(VGet(200, 2000, 200))
		->setScale(VGet(100, 100, 100))->addComponent<Model3D>()
		->loadModel(PLAYER_MODEL_PATH)
		->getGameObject();
	auto playerHalfScale = VScale(player->getTransform().scale,0.5f);
	player->addComponent<AABBCollider>()
		->setAABB(VGet(-playerHalfScale.x,-playerHalfScale.y,-playerHalfScale.z),
			playerHalfScale);
	player->addComponent<NormalPhysics>()
		->setGravity(-600.0f)
		->setMaxGravity(-3000.0f);

	// カメラ
	GameObject::Builder()
		.build()
		->setRotation(VGet(0, 20, 0))
		->addComponent<Camera>()
		->getGameObject()->addComponent<CameraController>()
		->setTarget(player)
		->setCameraOffset(VGet(0, 400, -400))
		->setTargetOffset(VGet(0, 200, 0));

	// ステージメイク
	auto* stage1 = GameObject::Builder()
		.setName("stage1")
		.build()
		->setPosition(VGet(0, -200, 0))
		->setScale(VGet(10000, 300, 10000))
		->addComponent<Model3D>()
		->loadModel(STAGE_MODEL_PATH)
		->getGameObject();
	auto stage1HalfScale = VScale(stage1->getTransform().scale, 0.5f);
	stage1->addComponent<AABBCollider>()
		->setAABB(VGet(-stage1HalfScale.x, -stage1HalfScale.y, -stage1HalfScale.z),
			stage1HalfScale);
}

/// <summary>
/// シーン破棄時に呼び出される
/// </summary>
void GameScene::destroy() {


}
