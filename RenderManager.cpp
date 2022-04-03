#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include "CoreIncludes.h"
#include "RenderManager.h"
#include "Window.h"
#include "Vector2.h"
#include <stdexcept>

RenderManager::RenderManager(const Window& window)
    : renderer(std::unique_ptr<SDL_Renderer, SDLDeleter>(SDL_CreateRenderer(
          window.GetPtr(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED))) {
  if (!renderer) {
    throw std::runtime_error(SDL_GetError());
  }
}

void RenderManager::Render(Vector2 pos, Color _color) const noexcept {
  SDL_SetRenderDrawColor(renderer.get(), _color.r, _color.g,
                         _color.b, _color.a);
  const SDL_Rect sdlrect{static_cast<int>(pos.x), static_cast<int>(pos.y),
                         TILE_SIZE, TILE_SIZE};
  SDL_RenderFillRect(renderer.get(), &sdlrect);
}

void RenderManager::EnterFrame() const noexcept {
  SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
  SDL_RenderClear(renderer.get());
}

void RenderManager::ExitFrame() const noexcept { SDL_RenderPresent(renderer.get()); }