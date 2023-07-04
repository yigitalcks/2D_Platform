#pragma once

#include <vector>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_Image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "TextureManager.h"
#include "Entity.h"
#include "KeyboardHandling.h"
#include "Collision.h"
#include "Map.h"


class Game {
public:
	Game();
	~Game();

	int init(const char* title, int width, int height);
	void render();
	void update();
	void handle_events();
	void clear();
	bool running();

	static SDL_Renderer* renderer;
	static std::vector<std::unique_ptr<Entity>> entity_list;
	static bool isRunning;

private:
	Map* map;
	KeyboardHandling* keyHandler;
	SDL_Window* window;
};