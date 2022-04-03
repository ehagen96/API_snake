#pragma once
#include <string>
#include "Vector2.h"

struct GlobalConfig {
	inline static const std::string WINDOW_TITLE = "Snake";
	static constexpr unsigned int SCREEN_WIDTH = 1250;
	static constexpr unsigned int SCREEN_HEIGHT = 700;
	static constexpr unsigned int GRID_SIZE = 10;
};