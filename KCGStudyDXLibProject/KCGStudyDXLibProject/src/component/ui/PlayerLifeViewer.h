#pragma once
#include "IComponent.h"
#include "player/PlayerLifeManager.h"
#include "renderer/ui/UIImage.h"

class PlayerLifeViewer : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	PlayerLifeViewer();

	/// <summary>
	/// 初期化時実行
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// 毎フレーム実行
	/// </summary>
	virtual void update() override;

	/// <summary>
	/// 固定間隔で実行
	/// </summary>
	virtual void fixedUpdate() override;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	virtual void destroy() override;

	/// <summary>
	/// プレイヤーのライフ管理をセットする
	/// </summary>
	/// <param name="lifeManager">ライフ管理</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerLifeViewer* setLifeManager(PlayerLifeManager* lifeManager);

private:  

	// プレイヤーライフマネージャー
	PlayerLifeManager* _playerLifeManager;
	// ライフ表示用Image配列
	std::vector<IRenderer*> _lifeImages;
	// 前回のライフ
	int _prevLife;
};

