#pragma once

#include <string>
#include <map>
#include <memory>
#include "SDL_Deleter.h"

class Image;


class ResourceManager {
public:
	ResourceManager(SDL_Renderer& renderer_view) noexcept;

	bool load_image_from_file(Image& image, const std::string &filePath);
	static SDL_Texture* get_texture_view(const std::string_view file_path);
private:
	SDL_Renderer& renderer_view_;
	static std::map<std::string, std::unique_ptr<SDL_Texture, SDL_Deleter>> textures_;
};
