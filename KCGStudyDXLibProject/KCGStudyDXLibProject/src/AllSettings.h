#pragma once
#include "stdafx.h"

constexpr double FPS = 120.0;
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr const wchar_t* WINDOW_TITLE = L"アボイダー";

#ifdef _DEBUG
constexpr double DEBUG_CHECK_DURATION_MS = 1000.0;
#endif