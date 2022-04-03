#pragma once
#include <string>

class Image {
public:	
	Image() = default;
	Image(std::string file_path, int width, int height) noexcept;
	void file_path(std::string new_file_path) noexcept;
	void width(int new_width) noexcept;
	void height(int new_height) noexcept;
	std::string_view file_path() const noexcept;
	int width() const noexcept;
	int height() const noexcept;
private:
	std::string file_path_{};
	int width_{};
	int height_{};
};