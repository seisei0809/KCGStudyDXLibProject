#include "stdafx.h"
#include "AllSettings.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "RendererManager.h"
#include "TitleScene.h"
#include "InputManager.h"
#include "GameManager.h"
#include "resource.h"

/// <summary>
/// コンストラクタ
/// </summary>
Game::Builder::Builder()
	:_fps(60.0f) {

}

/// <summary>
/// ウィンドウのサイズを設定する
/// </summary>
/// <param name="width">ウィンドウの幅</param>
/// <param name="height">ウィンドウの高さ</param>
/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
Game::Builder& Game::Builder::setWindowSize(const int width, const int height) {

	SetGraphMode(width, height, 32);
	return *this;
}

/// <summary>
/// ウィンドウタイトルを設定する
/// </summary>
/// <param name="title">設定するウィンドウタイトルの文字列</param>
/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
Game::Builder& Game::Builder::setWindowTitle(const TCHAR* title) {

	SetMainWindowText(title);
	return *this;
}

/// <summary>
/// スクリーンモードを設定する
/// </summary>
/// <param name="isWindow">ウィンドウモードの場合はtrue、フルスクリーンモードの場合はfalse</param>
/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
Game::Builder& Game::Builder::setScreenMode(const bool isWindow) {

	ChangeWindowMode(isWindow);
	return *this;
}

/// <summary>
/// FPSを設定する
/// </summary>
/// <param name="fps">設定するFPS値</param>
/// <returns>メソッドチェーンを可能にするBuilderオブジェクトへの参照</returns>
Game::Builder& Game::Builder::setFPS(const float fps) {

	this->_fps = fps;
	return *this;
}

/// <summary>
/// ビルドする
/// </summary>
/// <returns>Gameインスタンスを渡す</returns>
Game* Game::Builder::build() {

	Game* game = new Game(*this);
	return game;
}

/// <summary>
/// FPS取得
/// </summary>
/// <returns>FPS</returns>
constexpr float Game::Builder::getFPS() const {

	return _fps;
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="builder">ビルド設定</param>
Game::Game(const Builder& builder)
	:_fps(),
	_frameDuration(),
	_frameDurationNs() {

	_fps = builder.getFPS();
}

/// <summary>
/// ゲームを開始する
/// </summary>
/// <returns></returns>
void Game::start() {

	// ここからシーケンス的に起動
	_Setting();
	_Run();
	_End();
}

/// <summary>
/// 設定初期化
/// </summary>
void Game::_Setting() {

	using namespace Utility;

	// 初期化
	DxLib_Init();

	// フルスクリーンなら再セット
	if (!WINDOW_MODE) {

		// 現在のウィンドウサイズを取得
		int windowWidth, windowHeight;
		GetWindowSize(&windowWidth, &windowHeight);

		SetGraphMode(windowWidth, windowHeight, 32);
	}

	// 垂直同期は切る
	SetWaitVSyncFlag(false);
	// Zバッファを有効にする
	SetUseZBuffer3D(true);
	// Zバッファへの書き込みを有効にする
	SetWriteZBuffer3D(true);
	// アイコン固定
	SetWindowIconID(IDI_ICON1);

	// ライトを適当につける
	SetLightEnable(true);
	SetLightDirection(VGet(1.0f, -1.0f, 1.0f));

	// フレーム間隔秒数
	_frameDuration = 1 / FPS;
	// フレーム間隔ナノ秒数変換
	_frameDurationNs = std::chrono::duration_cast<std::chrono::nanoseconds>
		(std::chrono::duration<double>(_frameDuration));

	// 時間管理のリセット
	TimeManager::reset();
	TimeManager::setFixedDeltaTime(_frameDuration);
}

/// <summary>
/// ループ開始
/// </summary>
void Game::_Run() const {

	using namespace std::chrono;
	using namespace Utility;

#ifdef _DEBUG
	// FPSとフレーム数計測用
	auto fpsCountStart = steady_clock::now();
	int fpsFrameCount = 0;
	double currentFPS = 0.0;
	unsigned long long frameCount = 0;
#endif

	// スレッド待機用の次フレーム時間
	auto nextFrameTime = steady_clock::now();
	auto lastFrameTime = steady_clock::now();

	SceneManager::getInstance().changeScene<TitleScene>();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !GameManager::getInstance().isGameEnd()) {

		// 現在のフレーム時間
		auto now = steady_clock::now();

		// 前フレームからの経過時間計測
		auto deltaTimeNs = duration_cast<nanoseconds>(now - lastFrameTime);
		auto deltaTime = duration<double>(deltaTimeNs).count();
		lastFrameTime = now;

		// 時間管理の更新
		TimeManager::update(deltaTime);
		// 入力状態の更新
		InputManager::update();

#ifdef _DEBUG
		// フレームカウント
		frameCount++;
		fpsFrameCount++;

		// FPS計測
		auto elapsed = duration_cast<milliseconds>(now - fpsCountStart).count();

		if (elapsed >= DEBUG_CHECK_DURATION_MS) {
			currentFPS = fpsFrameCount / (elapsed / DEBUG_CHECK_DURATION_MS);
			fpsFrameCount = 0;
			fpsCountStart = now;
		}

		// 手動で小数点以下2桁に整形
		int intPart = static_cast<int>(currentFPS);          // 整数部
		int deciPart = static_cast<int>((currentFPS - intPart) * 100);  // 小数部（2桁）

		// 描画
		std::cout << "\rFPS: " << intPart << "."
			<< (deciPart < 10 ? "0" : "") << deciPart << std::flush;
#endif

		// 裏画面を描画対象にする
		SetDrawScreen(DX_SCREEN_BACK);

		// 画面クリア
		ClearDrawScreen();

		// 物理演算用の更新
		GameObjectManager::getInstance().allFixedUpdate();

		// ゲームオブジェクト全体の更新
		GameObjectManager::getInstance().allUpdate();

		// レンダラー管理の描画更新
		RendererManager::getInstance().allRender();

		// 裏画面を描画対象にする
		ScreenFlip();

		// シーン更新があるなら更新
		SceneManager::getInstance().updateScene();

		nextFrameTime += _frameDurationNs;

		std::this_thread::sleep_until(nextFrameTime);
	}

}

/// <summary>
/// 終了処理
/// </summary>
void Game::_End() {		
	
	// 全てのゲームオブジェクトを破棄
	GameObjectManager::getInstance().destroyAllGameObject();

	// シーン終了
	SceneManager::getInstance().endScene();

	// DxLib終了
	DxLib_End();
}