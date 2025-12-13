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
	Game* const game =Game::Builder()
		.setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT)
		.setWindowTitle(WINDOW_TITLE)
		.setScreenMode(WINDOW_MODE)
		.setFPS(FPS)
		.build();

	// ゲーム開始
	game->start();

	return 0;

}