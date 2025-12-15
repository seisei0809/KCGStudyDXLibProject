#include "stdafx.h"
#include "PlayerLifeViewer.h"
#include "AllSettings.h"
#include "GameObjectManager.h"

using namespace AllEnumSpace;

/// <summary>
/// コンストラクタ
/// </summary>
PlayerLifeViewer::PlayerLifeViewer()
	:_playerLifeManager(nullptr),
	_lifeImages(),
	_prevLife(){
}

/// <summary>
/// 初期化時実行
/// </summary>
void PlayerLifeViewer::start() {

	_lifeImages.clear();

	int life = _playerLifeManager->getLife();
	_prevLife = life;

	for (int i = 0; i < life; i++) {

		_lifeImages.emplace_back(GameObject::Builder()
			.build()
			->setPosition({ PLAYER_LIFE_UI_OFFSET_X * i,0,0 })
			->addComponent<UIImage>()
			->loadImage(UI_LIFE_IMAGE_PATH)
			->setAnchor(Anchor::BottomLeft)
			->setUIScale(PLAYER_LIFE_UI_SCALE)
			->setLayer(100));
	}
}

/// <summary>
/// 毎フレーム実行
/// </summary>
void PlayerLifeViewer::update() {

	int life = _playerLifeManager->getLife();

	if (life == _prevLife) return;

	for (int i = 0; i < _lifeImages.size(); i++) {

		_lifeImages[i]->getGameObject()->setActive(i < life);
	}

	_prevLife = life;
}

/// <summary>
/// 固定間隔で実行
/// </summary>
void PlayerLifeViewer::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void PlayerLifeViewer::destroy() {

}

/// <summary>
/// プレイヤーのライフ管理をセットする
/// </summary>
/// <param name="lifeManager">ライフ管理</param>
/// <returns>メソッドチェーン用</returns>
PlayerLifeViewer* PlayerLifeViewer::setLifeManager(PlayerLifeManager* lifeManager) {
		
	_playerLifeManager = lifeManager;
	return this;
}