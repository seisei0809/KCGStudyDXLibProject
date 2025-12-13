#pragma once

/// <summary>
/// 全ての列挙型
/// </summary>
namespace AllEnumSpace
{
	/// <summary>
	/// ゲームオブジェクトのタグ
	/// </summary>
	enum class Tag {

		// 無し
		None,
		// プレイヤー
		Player,
		// 敵
		Enemy,
		// 弾
		Bullet,
		// ステージ
		Stage,
	};

	/// <summary>
	/// アンカー位置
	/// </summary>
	enum class Anchor {
		// 左上
		TopLeft,
		// 上中央
		TopCenter,
		// 右上
		TopRight,
		// 左中央
		MiddleLeft,
		// 中央
		Center,
		// 右中央
		MiddleRight,
		// 左下
		BottomLeft,
		// 下中央
		BottomCenter,
		// 右下
		BottomRight
	};
}