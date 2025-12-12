#pragma once
#include "Singleton.h"
#include "IScene.h"

/// <summary>
/// シーン管理
/// </summary>
class SceneManager : public Utility::Singleton<SceneManager>{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneManager();
	
	/// <summary>
	/// シーン変更
	/// </summary>
	/// <typeparam name="T">シーンクラス</typeparam>
	template<typename T>
	void changeScene() {
	
		// 変更予定のシーンのインスタンスを返すようにする
		_GetChangeSceneInstance = []()-> IScene* {return new T(); };
		_isChange = true;
	}

	/// <summary>
	/// シーン更新
	/// </summary>
	void updateScene();

	/// <summary>
	/// 現在のシーンを取得する
	/// </summary>
	/// <returns>シーン</returns>
	IScene* getNowScene();

	/// <summary>
	/// シーンを終わらせる(ゲーム終了時)
	/// </summary>
	void endScene();

private:
	
	// 現在のシーン
	IScene* _nowScene;
	// シーン変更インスタンス取得関数ポインタ
	IScene* (*_GetChangeSceneInstance)();
	// 変更フラグ　
	// trueならシーン変更あり
	bool _isChange;
};

