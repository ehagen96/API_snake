#pragma once
#include "CoreIncludes.h"
#include "Vector2.h"
#include "KeyCode.h"
#include <array>

class RenderManager;

static constexpr unsigned int max_length = 50;

class Player
{
	using PlayerPart = Vector2;	

    void CheckCollisionWithBody() noexcept;
	void Move() noexcept;
public:	
	void OnKeyDown(KeyCode key) noexcept;
	void Render(const RenderManager& renderManager) const noexcept;
	void Update() noexcept;
    void Grow() noexcept;
    Vector2 GetPosition() const noexcept;
	void ResetPlayer() noexcept;

private:
    PlayerPart head{STARTING_POS.x, STARTING_POS.y};
	std::array<PlayerPart, max_length> body_parts;  
	Vector2 heading = NONE;
	
	unsigned int score = START_SCORE;
};