#include "Vector2.h"
#include <cmath>

Vector2 Vector2::operator+(const Vector2 &rhs) const noexcept {
  return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2 &rhs) const noexcept {
  return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const Vector2 &rhs) const noexcept {
  return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator/(const Vector2 &rhs) const noexcept {
  return Vector2(x / rhs.x, y / rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const noexcept {
  return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const noexcept {
  return Vector2(x / rhs, y / rhs);
}

bool Vector2::operator==(const Vector2 &rhs) const noexcept {
  return (this->x == rhs.x && this->y == rhs.y);
}

void Vector2::SetPosition(const float _x, const float _y) noexcept {
  x = _x;
  y = _y;
}

void Vector2::ChangePosition(const Vector2 vector) noexcept {
  x += vector.x;
  y += vector.y;
}
