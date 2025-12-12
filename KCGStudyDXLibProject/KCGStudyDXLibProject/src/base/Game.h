#pragma once

/// <summary>
/// ゲームの基底
/// </summary>
class Game{
public:

	/// <summary>
	/// Gameクラスのビルド設定
	/// </summary>
	class Builder {
	public:

		/// <summary>
		/// ウィンドウのサイズを設定する
		/// </summary>
		/// <param name="width">ウィンドウの幅</param>
		/// <param name="height">ウィンドウの高さ</param>
		/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
		Builder& setWindowSize(const int width, const int height);

		/// <summary>
		/// ウィンドウタイトルを設定する
		/// </summary>
		/// <param name="title">設定するウィンドウタイトルの文字列</param>
		/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
		Builder& setWindowTitle(const TCHAR* title);

		/// <summary>
		/// スクリーンモードを設定する
		/// </summary>
		/// <param name="isWindow">ウィンドウモードの場合はtrue、フルスクリーンモードの場合はfalse</param>
		/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
		Builder& setScreenMode(const bool isWindow);

		/// <summary>
		/// FPSを設定する
		/// </summary>
		/// <param name="fps">設定するFPS値</param>
		/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
		Builder& setFPS(const float fps);

		/// <summary>
		/// ビルドする
		/// </summary>
		/// <returns>Gameインスタンスを渡す</returns>
		Game* build();

		/// <summary>
		/// FPS取得
		/// </summary>
		/// <returns>FPS</returns>
		constexpr float getFPS() const;

	private:
		// デフォルトFPS値
		float fps = 60.0;
	};

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="builder">ビルド設定</param>
	Game(const Builder& builder);

	/// <summary>
	/// ゲームを開始する
	/// </summary>
	void start();


private:

	/// <summary>
	/// 設定初期化
	/// </summary>
	void _Setting();

	/// <summary>
	/// ループ開始
	/// </summary>
	void _Run() const;

	/// <summary>
	/// 終了処理
	/// </summary>
	void _End();

	// FPS値
	float _fps;
	// フレーム間隔秒数
	double _frameDuration;
	// フレーム間隔ナノ秒数変換
	std::chrono::nanoseconds _frameDurationNs;
};