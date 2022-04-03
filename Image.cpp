#include "Image.h"

Image::Image(std::string file_path, int width, int height) noexcept : file_path_(file_path), width_(width), height_(height)
{
}

void Image::file_path(std::string new_file_path) noexcept
{
	file_path_ = new_file_path;
}

void Image::width(int new_width) noexcept
{
	width_ = new_width;
}

void Image::height(int new_height) noexcept
{
	height_ = new_height;
}

std::string_view Image::file_path() const noexcept
{
	return file_path_;
}

int Image::width() const noexcept
{
	return width_;
}

int Image::height() const noexcept
{
	return height_;
}
