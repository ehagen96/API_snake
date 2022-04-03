#pragma once

#include "Apple.h"
#include "RenderManager.h"
#include <algorithm>

void Apple::Render(const RenderManager &renderManager) const noexcept {
  renderManager.Render(position, APPLE_COLOR);
}

void Apple::GiveRandomPosition() noexcept {
  position.SetPosition((rand() % width_divided) * grid_size,
                        (rand() % height_divided) * grid_size);
}
