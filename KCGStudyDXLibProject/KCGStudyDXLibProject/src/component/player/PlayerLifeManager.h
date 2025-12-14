#pragma once
#include "IComponent.h"
#include "Event.h"

class PlayerLifeManager : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	PlayerLifeManager();

	/// <summary>
	/// 初期化時実行
	/// </summary>
	void start() override;

	/// <summary>
	/// 毎フレーム実行
	/// </summary>
	void update() override;

	/// <summary>
	/// 固定間隔で実行
	/// </summary>
	void fixedUpdate() override;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	void destroy() override;

	/// <summary>
	/// ライフをセットする
	/// </summary>
	/// <param name="life">ライフ</param>
	/// <returns>メソッドチェーン用</returns>
	PlayerLifeManager* setLife(int life);

	/// <summary>
	/// ライフを取得する
	/// </summary>
	/// <returns>ライフ</returns>
	int getLife() const;

	/// <summary>
	/// ライフを減らす
	/// </summary>
	void minusLife();

	/// <summary>
	/// HPが0になった時のイベントを追加する
	/// </summary>
	/// <typeparam name="T">型</typeparam>
	/// <param name="obj">インスタンス</param>
	/// <param name="method">関数</param>
	/// <returns>メソッドチェーン用</returns>
	template<class T>
	PlayerLifeManager* addLifeZeroEvent(T* obj, void (T::* method)()) {

		_onLifeZeroEvent.add(obj, method);
		return this;
	}

	/// <summary>
	/// HPが0になった時のイベントから破棄する
	/// </summary>
	/// <typeparam name="T">型</typeparam>
	/// <param name="obj">インスタンス</param>
	/// <param name="method">関数</param>
	/// <returns>メソッドチェーン用</returns>
	template<class T>
	PlayerLifeManager* destroyLifeZeroEvent(T* obj, void (T::* method)()) {

		_onLifeZeroEvent.remove(obj, method);
		return this;
	}

private:

	// ライフ
	int _life;
	// ライフが0になった時に発火するイベント
	Utility::Event<> _onLifeZeroEvent;
};

