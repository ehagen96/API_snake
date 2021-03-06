#include "Game.h"
#include "CoreIncludes.h"

KeyCode TranslateKeyCode(SDL_Keycode code) noexcept {
  switch (code) {
  case SDLK_ESCAPE:
    return KeyCode::ESCAPE;
    break;
  case SDLK_SPACE:
    return KeyCode::SPACE;
    break;
  case SDLK_RETURN:
    return KeyCode::ENTER;
    break;
  case SDLK_RETURN2:
    return KeyCode::ENTER;
    break;
  case SDLK_a:
    return KeyCode::A;
    break;
  case SDLK_b:
    return KeyCode::B;
    break;
  case SDLK_c:
    return KeyCode::C;
    break;
  case SDLK_d:
    return KeyCode::D;
    break;
  case SDLK_e:
    return KeyCode::E;
    break;
  case SDLK_f:
    return KeyCode::F;
    break;
  case SDLK_g:
    return KeyCode::G;
    break;
  case SDLK_h:
    return KeyCode::H;
    break;
  case SDLK_i:
    return KeyCode::I;
    break;
  case SDLK_j:
    return KeyCode::J;
    break;
  case SDLK_k:
    return KeyCode::K;
    break;
  case SDLK_l:
    return KeyCode::L;
    break;
  case SDLK_m:
    return KeyCode::M;
    break;
  case SDLK_n:
    return KeyCode::N;
    break;
  case SDLK_o:
    return KeyCode::O;
    break;
  case SDLK_p:
    return KeyCode::P;
    break;
  case SDLK_q:
    return KeyCode::Q;
    break;
  case SDLK_r:
    return KeyCode::R;
    break;
  case SDLK_s:
    return KeyCode::S;
    break;
  case SDLK_t:
    return KeyCode::T;
    break;
  case SDLK_u:
    return KeyCode::U;
    break;
  case SDLK_v:
    return KeyCode::V;
    break;
  case SDLK_w:
    return KeyCode::W;
    break;
  case SDLK_x:
    return KeyCode::X;
    break;
  case SDLK_y:
    return KeyCode::Y;
    break;
  case SDLK_z:
    return KeyCode::Z;
    break;
  case SDLK_LEFT:
    return KeyCode::LEFT_ARROW;
    break;
  case SDLK_RIGHT:
    return KeyCode::RIGHT_ARROW;
    break;
  case SDLK_UP:
    return KeyCode::UP_ARROW;
    break;
  case SDLK_DOWN:
    return KeyCode::DOWN_ARROW;
    break;
  default:
    return KeyCode::INVALID;
    break;
  }
}

bool CheckOutOfBounds(Vector2 position) noexcept {
  if (position.x > WIDTH - TILE_SIZE || position.x < WIDTH - WIDTH || 
      position.y > HEIGHT - TILE_SIZE || position.y < WIDTH - WIDTH) {
    return true;
  }
  return false;
} 

bool CheckAppleCollision(Vector2 playerPos, Vector2 applePos) noexcept {
  if (playerPos == applePos) {
    return true;
  }
  return false;
}

void Game::Update() noexcept {
  player.Update();
  if (CheckAppleCollision(player.GetPosition(), apple.position)) {
    player.Grow();
    apple.GiveRandomPosition();
  }
  if (CheckOutOfBounds(player.GetPosition())) {
    player.ResetPlayer();
  }
}

void Game::OnKeyDown(KeyCode key) noexcept { player.OnKeyDown(key); }

void Game::InputHandler() noexcept {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_KEYDOWN:
      OnKeyDown(TranslateKeyCode(e.key.keysym.sym));
      break;
    default:
      break;
    }
  }
}

void Game::Render() const noexcept {
    renderer.EnterFrame();
    player.Render(renderer);
    apple.Render(renderer);
    renderer.ExitFrame();
}

void Game::Run() noexcept {
  running = true;

  while (running) {
    InputHandler();
    Update();
    Render();

    SDL_Delay(FRAME_DELAY_MS);
  }
}
