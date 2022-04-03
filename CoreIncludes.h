#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include <stdexcept>
#include <string_view>
#include "Color.h"
#include "Vector2.h"

constexpr static unsigned int WIDTH = 1250;
constexpr static unsigned int HEIGHT = 700;
constexpr static unsigned int TILE_SIZE = 10;
constexpr static std::string_view TITLE = "Snake";
constexpr static uint8_t ALPHA_OPAQUE = 255;
constexpr static uint8_t ALPHA_TRANSPARENT = 0;
const static Color PLAYER_COLOR{255, 0, 0, ALPHA_OPAQUE};
const static Color APPLE_COLOR{0, 255, 0, ALPHA_OPAQUE};
const static Vector2 STARTING_POS(300.0f, 300.0f);
constexpr static unsigned int START_SCORE = 0;
constexpr static unsigned FRAME_DELAY_MS = 1000 / 20;

const static Vector2 NONE(0, 0);
const static Vector2 LEFT(-1, 0);
const static Vector2 RIGHT(1, 0);
const static Vector2 UP(0, -1);
const static Vector2 DOWN(0, 1);
