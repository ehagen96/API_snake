#include <SDL.h>
#include "ResourceManager.h" 
#include "Image.h"

std::map<std::string, std::unique_ptr<SDL_Texture, SDL_Deleter>> ResourceManager::textures_;

ResourceManager::ResourceManager(SDL_Renderer& renderer_view) noexcept : renderer_view_(renderer_view)
{
}

bool ResourceManager::load_image_from_file(Image& image, const std::string& filePath)
{
	for (const auto& [file_path, texture_ptr] : textures_) {
		if (file_path._Equal(filePath)) {
			image.file_path(filePath);
			return true;
		}
	}

	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
	if (surface) {
		std::unique_ptr<SDL_Texture, SDL_Deleter> texture(SDL_CreateTextureFromSurface(&renderer_view_, surface));
		if (texture) {
			textures_.insert(std::make_pair(filePath, std::move(texture)));
			image.file_path(filePath);
			image.width(surface->w);
			image.height(surface->h);
			return true;
		}
	}
	return false;
}
;

SDL_Texture* ResourceManager::get_texture_view(const std::string_view file_path)
{
	return textures_.at(file_path.data()).get();
}