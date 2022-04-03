#include "Sprite.h"
#include "Image.h"

Sprite::Sprite(Image& image) noexcept : source_(0, 0, 0, 0), color_({}, {}, {}, {}), image_(&image)
{
}

Sprite::Sprite(Rectangle source, Color color, Image& image) noexcept : source_(source), color_(color), image_(&image)
{
}

Sprite::Sprite(int x, int y, int w, int h, Color color, Image& image) noexcept : source_(x,y,w,h), color_(color), image_(&image)
{
}

Sprite::Sprite(Rectangle source, std::byte r, std::byte g, std::byte b, std::byte a, Image& image) noexcept : source_(source), color_(r, g, b, a), image_(&image)
{
}

Sprite::Sprite(int x, int y, int w, int h, std::byte r, std::byte g, std::byte b, std::byte a, Image& image) noexcept : source_(x,y,w,h), color_(r,g,b,a), image_(&image)
{
}

void Sprite::set_image(const Image& _image) noexcept
{
	image_ = &_image;
}

void Sprite::set_source(int x, int y, int w, int h) noexcept
{
	source_.SetBounds(x, y, w, h);
}

void Sprite::color(std::byte r, std::byte g, std::byte b, std::byte a) noexcept
{
	color_.color(r, g, b, a);
}

Color Sprite::color() const noexcept
{
	return color_;
}

Rectangle Sprite::source() const noexcept
{
	return source_;
}

int Sprite::width() const noexcept
{
	return image_->width();
}

int Sprite::height() const noexcept
{
	return image_->height();
}

std::string_view Sprite::image_file_path() const noexcept
{
	return image_->file_path();
}
