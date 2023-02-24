#pragma once
#include "SDL.h"
#include <iostream>

class Map {
public:
	Map();
	~Map();

	void renderMap();
	void initMap(int arr[18][32]);

private:
	SDL_Rect srcR, destR;
	SDL_Texture* dirt;
	SDL_Texture* grass;

	int map[18][32];

};

