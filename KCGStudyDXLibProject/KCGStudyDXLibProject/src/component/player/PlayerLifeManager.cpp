#include "stdafx.h"
#include "PlayerLifeManager.h"

PlayerLifeManager::PlayerLifeManager()
	:_life(0) {
}

/// <summary>
/// 初期化時実行
/// </summary>
void PlayerLifeManager::start() {

}

/// <summary>
/// 毎フレーム実行
/// </summary>
void PlayerLifeManager::update() {

}

/// <summary>
/// 固定間隔で実行
/// </summary>
void PlayerLifeManager::fixedUpdate() {

}

/// <summary>
/// 破棄時実行
/// </summary>
void PlayerLifeManager::destroy() {

}

/// <summary>
/// ライフをセットする
/// </summary>
/// <param name="life">ライフ</param>
/// <returns>メソッドチェーン用</returns>
PlayerLifeManager* PlayerLifeManager::setLife(int life) {

	_life = life;
	return this;
}

/// <summary>
/// ライフを取得する
/// </summary>
/// <returns>ライフ</returns>
int PlayerLifeManager::getLife() const {

	return _life;
}

/// <summary>
/// ライフを減らす
/// </summary>
void PlayerLifeManager::minusLife() {

	_life--;
	if (_life <= 0) {

		_onLifeZeroEvent.invoke();
	}
}