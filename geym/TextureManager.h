#pragma once
#include "SDL.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void draw(SDL_Texture* texture, SDL_Rect* srcR, SDL_Rect* destR);
	static void clearTexture(SDL_Texture* texture);
};
