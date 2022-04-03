#pragma once

#include "Rectangle.h"
#include "Color.h"
#include <string>

class Image;

class Sprite {
public:
	Sprite() = default;
	Sprite(Image& image) noexcept;
	Sprite(Rectangle source, Color color, Image& image) noexcept;
	Sprite(int x, int y, int w, int h, Color color, Image& image) noexcept;
	Sprite(Rectangle source, std::byte r, std::byte g, std::byte b, std::byte a, Image& image) noexcept;
	Sprite(int x, int y, int w, int h, std::byte r, std::byte g, std::byte b, std::byte a, Image& image) noexcept;
	
	void set_image(const Image& image) noexcept;
	void set_source(int x, int y, int w, int h) noexcept;
	void color(std::byte r, std::byte g, std::byte b, std::byte a) noexcept;
	Color color() const noexcept;
	Rectangle source() const noexcept;
	int width() const noexcept;
	int height() const noexcept;
	std::string_view image_file_path() const noexcept;
private:
	Rectangle source_{};
	Color color_{};
	const Image* image_{};
};