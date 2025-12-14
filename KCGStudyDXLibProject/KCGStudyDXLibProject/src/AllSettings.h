#pragma once
#include "stdafx.h"

constexpr double FPS = 120.0;
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr bool WINDOW_MODE = true;
constexpr const wchar_t* WINDOW_TITLE = L"アボイダー";

#ifdef _DEBUG
constexpr double DEBUG_CHECK_DURATION_MS = 1000.0;
#endif

const DxLib::VECTOR LIGHT_DIRECTION = VGet(0.5f, -0.8f, 1.0f);

constexpr const wchar_t* PLAYER_MODEL_PATH = L"asset/model/Player.mv1";
constexpr const wchar_t* ENEMY_MODEL_PATH = L"asset/model/Enemy.mv1";
constexpr const wchar_t* STAGE_MODEL_PATH = L"asset/model/Stage.mv1";
constexpr const wchar_t* BULLET_MODEL_PATH = L"asset/model/Bullet.mv1";