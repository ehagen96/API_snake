#include "Window.h"
#include <stdexcept>

Window::Window(std::string_view title, unsigned int windowWidth, unsigned int windowHeight) {
	const std::string temp(title);
	window = std::unique_ptr<SDL_Window, SDLDeleter>(SDL_CreateWindow(temp.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WindowFlags::SDL_WINDOW_RESIZABLE));
	if (!window)
	{
        throw std::runtime_error(SDL_GetError());
	}
}

SDL_Window* Window::GetPtr() const noexcept{ return window.get();
 }

