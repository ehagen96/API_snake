#include <iostream>
#include <exception>
#include "CoreIncludes.h"
#include "Game.h"

#undef main

int main() {

  try {
    Game game;
    game.Run();     
  } catch (const std::runtime_error &e) {
    std::cerr << e.what();
  } catch (...) {
    std::cerr << "catastrophic and unknown failure!";
  }

  return 0;
}

