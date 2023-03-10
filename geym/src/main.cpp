#include <iostream>
#include "Game.h"

constexpr auto WINDOW_WIDTH = 1280;
constexpr auto WINDOW_HEIGHT = 720;

Game* game{ nullptr };


int main(int argc, char** argv) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	if (game->init("GameWindow", WINDOW_WIDTH, WINDOW_HEIGHT)) {
		return -1;
	}

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clear();
	delete game;

	return 0;
}