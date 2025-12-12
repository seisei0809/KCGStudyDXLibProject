#include "stdafx.h"
#include "RendererManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
RendererManager::RendererManager()
	:_renders() {

}

/// <summary>
/// 全て描画
/// </summary>
const void RendererManager::allRender()const {

    // コピーして消し込みながら描画
    std::vector<IRenderer*> temp = _renders;

    while (!temp.empty()) {

        // 最小レイヤー探索
        int minLayer = temp[0]->getLayer();
        for (int i = 1; i < temp.size(); ++i) {

            if (temp[i]->getLayer() < minLayer) {

                minLayer = temp[i]->getLayer();
            }
        }
        // 最小レイヤーのものを描画し、消す
        for (auto it = temp.begin(); it != temp.end(); ) {

            if ((*it)->getLayer() != minLayer) {

				++it;
				continue;
			}
			(*it)->render();
			it = temp.erase(it);
		}
    }
}

/// <summary>
/// レンダラーを追加する
/// </summary>
/// <param name="renderer">レンダラー</param>
void RendererManager::addRenderer(IRenderer* renderer) {

	_renders.emplace_back(renderer);
}

/// <summary>
/// レンダラーを破棄する
/// </summary>
/// <param name="renderer">レンダラー</param>
void RendererManager::destroyRenderer(IRenderer* renderer) {

	for (auto it = _renders.begin(); it != _renders.end(); it++) {

		// 一致したら消す
		if (*it != renderer) continue;
		_renders.erase(it);
		break;
	}
}