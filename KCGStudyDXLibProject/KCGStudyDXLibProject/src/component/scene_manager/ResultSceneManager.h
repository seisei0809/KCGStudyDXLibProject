#pragma once
#include "IComponent.h"
class ResultSceneManager : public IComponent{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	ResultSceneManager();

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
	/// リトライする
	/// </summary>
	/// <param name="isRetry">リトライするか</param>
	void retry(bool isRetry);

	/// <summary>
	/// タイトルに戻る
	/// </summary>
	/// <param name="isTitle">タイトルに戻るか</param>
	void tilteBack(bool isTitle);
};

