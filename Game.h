#pragma once
#include "Apple.h"
#include "Player.h"
#include "RenderManager.h"
#include "SDLInit.h"
#include "Window.h"

class Game {
  SDLInit sdl{SDL_INIT_EVERYTHING};
  Window window{TITLE, WIDTH, HEIGHT};
  RenderManager renderer{window};

  Player player;
  Apple apple;

  bool running = false;

  void Update() noexcept;
  void OnKeyDown(KeyCode key) noexcept;
  void InputHandler() noexcept;
  void Render() const noexcept;

public:
  void Run() noexcept;
};
