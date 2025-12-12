#pragma once
#include "IUIRenderer.h"
#include <string>

/// <summary>
/// UI画像描画（回転対応）
/// </summary>
class UIImage : public IUIRenderer {
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	UIImage();

	/// <summary>
	/// 画像を読み込む
	/// </summary>
	/// <returns>メソッドチェーン用</returns>
	UIImage* loadImage(const std::wstring& filePath);

	/// <summary>
	/// 画像ハンドルを設定
	/// </summary>
	/// <returns>メソッドチェーン用</returns>
	UIImage* setImageHandle(int handle);

	/// <summary>
	/// 初期化時実行
	/// </summary>
	void start()override;

	/// <summary>
	/// 毎フレーム実行
	/// </summary>
	void update()override;

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

	// 画像ハンドル
	int _imageHandle;
	// 自分で読み込んだかどうか
	bool _isOwnImage;
	// 画像の幅（デフォルトは元画像のサイズ）
	int _imageWidth;
	// 画像の高さ（デフォルトは元画像のサイズ）
	int _imageHeight;
};