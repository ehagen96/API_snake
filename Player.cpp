
#include "Player.h"
#include "RenderManager.h"
#include <algorithm>
#include <cmath>

void Player::Render(const RenderManager &renderManager) const noexcept {
  renderManager.Render(head, PLAYER_COLOR);

  const auto renderPart = [&](PlayerPart part) noexcept {
    renderManager.Render(part, PLAYER_COLOR);
  };
  std::for_each_n(body_parts.begin(), score, renderPart);
}

void Player::Update() noexcept {
  Move();
  CheckCollisionWithBody();
}

void Player::Move() noexcept {
  std::move(body_parts.begin(), body_parts.end() - 1, body_parts.begin() + 1);
  body_parts.front() = head;
  head.ChangePosition(heading * TILE_SIZE);
}

void Player::OnKeyDown(KeyCode key) noexcept {
  if (key == KeyCode::LEFT_ARROW && heading != RIGHT) {
    heading = LEFT;
  } else if (key == KeyCode::RIGHT_ARROW && heading != LEFT) {
    heading = RIGHT;
  } else if (key == KeyCode::UP_ARROW && heading != DOWN) {
    heading = UP;
  } else if (key == KeyCode::DOWN_ARROW && heading != UP) {
    heading = DOWN;
  }
}

void Player::CheckCollisionWithBody() noexcept {
  const auto checkCollision = [&](const PlayerPart &part) noexcept {
    if (part == head) {
      ResetPlayer();
      return;
    }
  };
  std::for_each_n(body_parts.begin(), score, checkCollision);
}

void Player::Grow() noexcept {
  if (score < max_length) {
    score++;
  }
}

Vector2 Player::GetPosition() const noexcept { return head; }

void Player::ResetPlayer() noexcept {
  score = START_SCORE;
  heading = NONE;
  head.SetPosition(STARTING_POS.x, STARTING_POS.y);
}