#pragma once
#include "CoreIncludes.h"
#include "Vector2.h"

class RenderManager;
static constexpr float starting_x = 100;
static constexpr float starting_y = 200;
static constexpr unsigned int width_divided = WIDTH / TILE_SIZE;
static constexpr unsigned int height_divided = HEIGHT / TILE_SIZE;
static constexpr float grid_size = 10.0f;

class Apple {
public:
  Vector2 position{starting_x, starting_y};

  void Render(const RenderManager &renderManager) const noexcept;
  void GiveRandomPosition() noexcept;
};