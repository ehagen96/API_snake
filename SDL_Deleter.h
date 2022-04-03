#pragma once

#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning(disable:ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)

struct SDL_Deleter {
	void operator()(SDL_Window* window) const noexcept { SDL_DestroyWindow(window); }
	void operator()(SDL_Renderer* renderer) const noexcept { SDL_DestroyRenderer(renderer); }
	void operator()(SDL_Texture* texture) const noexcept { SDL_DestroyTexture(texture); }
};