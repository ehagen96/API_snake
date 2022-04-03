#include "SDLInit.h"
#include "CoreIncludes.h"


SDLInit::SDLInit(unsigned flags) {
  const auto result = SDL_Init(flags);
  if (result == -1) {
    throw std::runtime_error(SDL_GetError());
  }
}

SDLInit::~SDLInit() noexcept { SDL_Quit(); }