#pragma once
#include "stdafx.h"

constexpr double FPS = 1000.0;
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr bool WINDOW_MODE = true;
constexpr const wchar_t* WINDOW_TITLE = L"アボイダー";

#ifdef _DEBUG
constexpr double DEBUG_CHECK_DURATION_MS = 1000.0;
#endif