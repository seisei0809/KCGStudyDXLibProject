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
#include "player/PlayerManager.h"
#include "enemy/EnemySpawner.h"

using namespace AllEnumSpace;

/// <summary>
/// オブジェクト配置場所
/// </summary>
void GameScene::setGameObject() {

	// ゲームシーン管理
	_gameSceneManager = GameObject::Builder()
		.build()->addComponent<GameSceneManager>();

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
	_playerObj = GameObject::Builder()
		.setName("Player")
		.setTag(Tag::Player)
		.build()
		->setPosition(PLAYER_START_POSITION)
		->setScale(PLAYER_DEFAULT_SCALE)->addComponent<Model3D>()
		->loadModel(PLAYER_MODEL_PATH)
		->getGameObject();
	auto playerHalfScale = VScale(_playerObj->getTransform().scale,0.5f);
	_playerObj->addComponent<AABBCollider>()
		->setAABB(VGet(-playerHalfScale.x,-playerHalfScale.y,-playerHalfScale.z),
			playerHalfScale);
	_playerObj->addComponent<NormalPhysics>()
		->setGravity(PLAYER_GRAVITY)
		->setMaxGravity(PLAYER_MAX_GRAVITY);
	_playerObj->addComponent<PlayerManager>()
		->setSpeed(PLAYER_SPEED)
		->setJumpPower(PLAYER_JUMP_POWER)
		->setGroundTag(Tag::Ground);
	_playerLifeManager = _playerObj->addComponent<PlayerLifeManager>()
		->setLife(PLAYER_LIFE)
		->addLifeZeroEvent(_gameSceneManager, &GameSceneManager::endGameScene);

	// 敵スポナー
	GameObject::Builder()
		.build()
		->addComponent<EnemySpawner>()
		->setSpawnDuration(ENEMY_SPAWN_DURATION);

	// カメラ
	GameObject::Builder()
		.build()
		->setRotation(VGet(0, 20, 0))
		->addComponent<Camera>()
		->getGameObject()->addComponent<CameraController>()
		->setTarget(_playerObj)
		->setCameraOffset(CAMERA_DEFAULT_OFFSET)
		->setTargetOffset(CAMERA_TARGET_OFFSET);

	// ステージメイク
	// 地面
	auto* ground = GameObject::Builder()
		.setTag(Tag::Ground)
		.build()
		->setPosition(VGet(0, -200, 0))
		->setScale(VGet(10000, 300, 10000))
		->addComponent<Model3D>()
		->loadModel(STAGE_MODEL_PATH)
		->getGameObject();
	auto groundHalfScale = VScale(ground->getTransform().scale, 0.5f);
	ground->addComponent<AABBCollider>()
		->setAABB(VGet(-groundHalfScale.x, -groundHalfScale.y, -groundHalfScale.z),
			groundHalfScale);
	// 壁1
	auto* wall1 = GameObject::Builder()
		.setTag(Tag::Wall)
		.build()
		->setPosition(VGet(5000, 1400, 0))
		->setScale(VGet(200, 3000, 10000))
		->addComponent<Model3D>()
		->loadModel(STAGE_MODEL_PATH)
		->getGameObject();
	auto wall1HalfScale = VScale(wall1->getTransform().scale, 0.5f);
	wall1->addComponent<AABBCollider>()
		->setAABB(VGet(-wall1HalfScale.x, -wall1HalfScale.y, -wall1HalfScale.z),
			wall1HalfScale);
	// 壁2
	auto* wall2 = GameObject::Builder()
		.setTag(Tag::Wall)
		.build()
		->setPosition(VGet(-5000, 1400, 0))
		->setScale(VGet(200, 3000, 10000))
		->addComponent<Model3D>()
		->loadModel(STAGE_MODEL_PATH)
		->getGameObject();
	auto wall2HalfScale = VScale(wall2->getTransform().scale, 0.5f);
	wall2->addComponent<AABBCollider>()
		->setAABB(VGet(-wall2HalfScale.x, -wall2HalfScale.y, -wall2HalfScale.z),
			wall2HalfScale);
	// 壁3
	auto* wall3 = GameObject::Builder()
		.setTag(Tag::Wall)
		.build()
		->setPosition(VGet(0, 1400, 5000))
		->setScale(VGet(10000, 3000, 200))
		->addComponent<Model3D>()
		->loadModel(STAGE_MODEL_PATH)
		->getGameObject();
	auto wall3HalfScale = VScale(wall3->getTransform().scale, 0.5f);
	wall3->addComponent<AABBCollider>()
		->setAABB(VGet(-wall3HalfScale.x, -wall3HalfScale.y, -wall3HalfScale.z),
			wall3HalfScale);
	// 壁4
	auto* wall4 = GameObject::Builder()
		.setTag(Tag::Wall)
		.build()
		->setPosition(VGet(0, 1400, -5000))
		->setScale(VGet(10000, 3000, 200));
	auto wall4HalfScale = VScale(wall4->getTransform().scale, 0.5f);
	wall4->addComponent<AABBCollider>()
		->setAABB(VGet(-wall4HalfScale.x, -wall4HalfScale.y, -wall4HalfScale.z),
			wall4HalfScale);
}

/// <summary>
/// シーン破棄時に呼び出される
/// </summary>
void GameScene::destroy() {

	_playerLifeManager->destroyLifeZeroEvent(_gameSceneManager, &GameSceneManager::endGameScene);
}
