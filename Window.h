#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning(disable:ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include "SDLDeleter.h"
#include <memory>
#include <string_view>
struct SDL_Window;
class Window
{	
  std::unique_ptr<SDL_Window, SDLDeleter> window;

public:
	Window(std::string_view title, unsigned int windowWidth, unsigned int windowHeight);
    SDL_Window *GetPtr() const noexcept;
};