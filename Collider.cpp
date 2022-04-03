#include "Collider.h"

Collider::Collider(const int x, const int y, const int w, const int h) noexcept 
	: rect(x,y,w,h)
{
}

void Collider::set_bounds(const int new_x, const int new_y, const int new_w, const int new_h) noexcept
{
	rect.SetBounds(new_x, new_y, new_w, new_h);
}
