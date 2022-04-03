#pragma once

struct Vector2
{
	float x = 0; 
	float y = 0;
		 
	Vector2 operator+(const Vector2& rhs) const noexcept;		 
	Vector2 operator-(const Vector2& rhs) const noexcept;		 
	Vector2 operator*(const Vector2& rhs) const noexcept;	
	Vector2 operator/(const Vector2& rhs) const noexcept;
	Vector2 operator*(const float rhs) const noexcept;			 
	Vector2 operator/(const float rhs) const noexcept;		

	bool operator==(const Vector2& rhs) const noexcept;

	void SetPosition(const float _x, const float _y) noexcept;
    void ChangePosition(const Vector2 vector) noexcept;
};