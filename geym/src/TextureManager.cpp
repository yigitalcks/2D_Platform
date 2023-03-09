#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	SDL_Texture* tmpTexture{ nullptr };
	SDL_Surface* tmpSurface = IMG_Load(filename);
	tmpTexture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);

	return tmpTexture;
}

void TextureManager::clearTexture(SDL_Texture* texture) {
	SDL_DestroyTexture(texture);
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect* srcR, SDL_Rect* destR) {
	if (SDL_RenderCopy(Game::renderer, texture, srcR, destR) < 0) {
		std::cout << "hata" << SDL_GetError() <<"\n";
	}
}