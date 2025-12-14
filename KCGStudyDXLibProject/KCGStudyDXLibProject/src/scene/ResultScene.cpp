#include "stdafx.h"
#include "ResultScene.h"
#include "renderer/ui/UIText.h"

using namespace AllEnumSpace;

/// <summary>
/// オブジェクト配置場所
/// </summary>
void ResultScene::setGameObject() {

	// リザルトテキスト
	GameObject::Builder()
		.build()
		->setPosition(VGet(0.0f, -150.0f, 0.0f))->addComponent<UIText>()
		->setText(L"リザルト")
		->setColor(GetColor(255, 0, 0))
		->setUIScale(70)
		->setAnchor(Anchor::MiddleCenter)
		->setLayer(100);
}

/// <summary>
/// シーン破棄時に呼び出される
/// </summary>
void ResultScene::destroy() {


}
