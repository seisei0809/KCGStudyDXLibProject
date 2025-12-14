#pragma once
#include "stdafx.h"

constexpr double FPS = 60.0;
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

constexpr float PLAYER_SPEED = 1000.0f;
constexpr float PLAYER_JUMP_POWER = 1600.0f;
constexpr float PLAYER_GRAVITY = -800.0f;
constexpr float PLAYER_MAX_GRAVITY = -3500.0f;
constexpr VECTOR PLAYER_START_POSITION = { 200.0f, 2000.0f, 50.0f };
constexpr VECTOR PLAYER_DEFAULT_SCALE = { 150.0f, 150.0f, 150.0f };
constexpr int PLAYER_LIFE = 3;

constexpr float ENEMY_SHOT_DURATION = 2.0f;
constexpr VECTOR ENEMY_DEFAULT_SCALE = { 75.0f, 75.0f, 75.0f };
constexpr float ENEMY_BULLET_LIFE_TIME = 5.0f;
constexpr float ENEMY_BULLET_SPEED = 700.0f;
constexpr VECTOR ENEMY_BULLET_DEFAULT_SCALE = { 75.0f, 75.0f, 75.0f };
constexpr float ENEMY_SPAWN_DURATION = 5.0f;
constexpr VECTOR ENEMY_SPAWN_RANGE_MIN = { -900.0f, 0.0f, -900.0f };
constexpr VECTOR ENEMY_SPAWN_RANGE_MAX = { 900.0f, 500.0f, 900.0f };

constexpr VECTOR CAMERA_DEFAULT_OFFSET = { 0.0f, 900.0f, -2000.0f };
constexpr VECTOR CAMERA_TARGET_OFFSET = { 0.0f, 100.0f, 0.0f };