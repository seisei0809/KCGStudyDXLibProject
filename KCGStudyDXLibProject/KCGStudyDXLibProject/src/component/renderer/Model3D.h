#pragma once
#include "IRenderer.h"

/// <summary>
/// 3Dモデル描画用
/// </summary>
class Model3D : public IRenderer{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Model3D();

	/// <summary>
	/// モデルファイルを読み込む
	/// </summary>
	/// <param name="filePath">モデルファイルパス</param>
	/// <returns>メソッドチェーン用</returns>
	Model3D* loadModel(const std::wstring& filePath);

	/// <summary>
	/// モデルハンドルを取得する
	/// </summary>
	/// <returns>モデルハンドル</returns>
	int getModelHandle() const;

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
	void fixedUpdate()override;

	/// <summary>
	/// 破棄時実行
	/// </summary>
	void destroy() override;

	/// <summary>
	/// 描画実行
	/// </summary>
	void render() override;

private:

	// モデルハンドル
	int _modelHandle = -1;
	// モデルファイルパス
	std::wstring  _modelFilePath;
};

