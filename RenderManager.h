#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include <memory>
#include "Color.h"
#include "SDLDeleter.h"

struct Vector2;
struct SDL_Renderer;
class Window;

class RenderManager {
  std::unique_ptr<SDL_Renderer, SDLDeleter> renderer;

public:
  RenderManager(const Window& window);

  void EnterFrame() const noexcept;
  void Render(Vector2 pos, Color _color) const noexcept;
  void ExitFrame() const noexcept;  
};
