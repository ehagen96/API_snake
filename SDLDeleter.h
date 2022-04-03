#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)

struct SDLDeleter {
  void operator()(SDL_Window *window) const noexcept {
    SDL_DestroyWindow(window);
  }
  void operator()(SDL_Renderer *renderer) const noexcept {
    SDL_DestroyRenderer(renderer);
  }
};
