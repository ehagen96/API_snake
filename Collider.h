#pragma once

#include "Rectangle.h"

/* GOAL: make type trivial and later oversee if a collider is really just a rectangle */

class Collider {
public:
	Collider() = default;
	Collider(const int x, const int y, const int w, const int h) noexcept;
	void set_bounds(const int x, const int y, const int w, const int h) noexcept;
private:
	Rectangle rect{};
};