#pragma once
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void draw(SDL_Texture* texture, SDL_Rect* srcR, SDL_Rect* destR);
	static void clearTexture(SDL_Texture* texture);
};
