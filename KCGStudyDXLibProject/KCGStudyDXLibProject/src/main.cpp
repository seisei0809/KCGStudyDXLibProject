#include "stdafx.h"
#include "AllSettings.h"
#include "Game.h"

#ifdef _DEBUG

int main() {

#else
#include <windows.h>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

#endif

	// ゲームの初期化
	// 1280*720のウィンドウモードでビルド
	Game* const game =Game::Builder()
		.setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT)
		.setWindowTitle(WINDOW_TITLE)
		.setScreenMode(true)
		.setFPS(FPS)
		.build();

	// ゲーム開始
	game->start();



	//int ModelHandle = DxLib::MV1LoadModel(TEXT("asset/model/Bullet.mv1"));

	//MV1SetUseZBuffer(ModelHandle, true);
	//MV1SetWriteZBuffer(ModelHandle,true);

	//float rotation = 0.0F;
	//MV1SetOpacityRate(ModelHandle, 1);
	//auto nextFrameTime = std::chrono::steady_clock::now();

	//// FPS計測用
	//auto fpsCountStart = std::chrono::steady_clock::now();
	//int fpsFrameCount = 0;
	//double currentFPS = 0.0;

	//// マテリアル数を取得
	//int matNum = MV1GetMaterialNum(ModelHandle);

	//for (int i = 0; i < matNum; i++) {
	//	int texNum = MV1GetTextureNum(ModelHandle);;
	//	auto name = MV1GetTextureName(ModelHandle, i);
	//	
	//	// Emissive（自己発光）も少し付けると確実に赤になる
	//	MV1SetMaterialAmbColor(ModelHandle, i, GetColorF(1, 1, 1, 1));
	//	MV1SetMaterialDifColor(ModelHandle, i, GetColorF(1, 1, 1, 1));

	//	// 修正: wchar_t* を std::wcout で出力
	//	std::wcout << L"Material " << i << L": TextureNum = " << texNum << L": " << name << std::endl;
	//}

	//while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

	//	auto now = std::chrono::steady_clock::now();

	//	// FPS計測（1秒ごとに更新）
	//	fpsFrameCount++;
	//	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - fpsCountStart).count();

	//	if (elapsed >= 1'000) {
	//		currentFPS = fpsFrameCount / (elapsed / 1000.0);
	//		fpsFrameCount = 0;
	//		fpsCountStart = now;
	//	}

	//	// 手動で小数点以下2桁に整形
	//	int intPart = static_cast<int>(currentFPS);          // 整数部
	//	int deciPart = static_cast<int>((currentFPS - intPart) * 100);  // 小数部（2桁）

	//	// 描画
	//	std::cout << "\rFPS: " << intPart << "."
	//		<< (deciPart < 10 ? "0" : "") << deciPart << "    " << std::flush;

	//	SetDrawScreen(DX_SCREEN_BACK); // 裏画面を描画対象にする

	//	ClearDrawScreen();
	//	SetLightEnable(true);

	//	SetLightDifColor(GetColorF(1, 1, 1, 1));
	//	SetLightDirection(VGet(-1, -1, 1));

	//	if (CheckHitKey(KEY_INPUT_SPACE) == 1) rotation += 6;
	//	MV1SetRotationXYZ(ModelHandle, VGet(rotation * DX_PI_F / 180, rotation * DX_PI_F / 180, rotation * DX_PI_F / 180));
	//	MV1SetPosition(ModelHandle, VGet(320, 200, -100));
	//	MV1SetScale(ModelHandle, VGet(100, 100, 100));

	//	MV1DrawModel(ModelHandle);
	//	DrawSphere3D(VGet(320, 200, 0), 50.0f, 16, GetColor(255, 255, 255), GetColor(255, 0, 255), TRUE);

	//	SetDrawScreen(DX_SCREEN_FRONT); // 裏画面を描画対象にする

	//	nextFrameTime += frameDurationNs;

	//	std::this_thread::sleep_until(nextFrameTime);
	//}

	//MV1DeleteModel(ModelHandle);
	//DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 

}