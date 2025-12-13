#pragma once
#include "stdafx.h"

/// <summary>
/// ゲームオブジェクトの位置、回転、スケール情報
/// </summary>
struct Transform {

	// 位置
	VECTOR position;
	// 回転
	VECTOR rotation;
	// スケール
	VECTOR scale;
};