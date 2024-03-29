#include <iostream>
#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;
bool Game::isRunning = false;

Game::Game() : window{ nullptr }, map{ nullptr }, keyHandler{nullptr} {}
Game::~Game() {
	delete map;
	delete keyHandler;
}

int Game::init(const char* title, int width, int height) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL could not initialized, SDL_Error:  " << SDL_GetError() << std::endl;
		return -1;
	}
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer) {
		std::cout << "renderer coud not created, SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	isRunning = true;

	//if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
	//	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	//	renderer = SDL_CreateRenderer(window, -1, 0);
	//	if (renderer) {
	//		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//	}
	//	else {
	//		std::cout << "renderer coud not created, SDL_Error: " << SDL_GetError();
	//		return -1;
	//	}
	//	isRunning = true;
	//} 
	//else {
	//	std::cout << "SDL could not initialized, SDL_Error:  " << SDL_GetError();
	//	return -1;
	//}
	if (TTF_Init() < 0) {
		std::cout << "Error intializing SDL_ttf: " << TTF_GetError() << std::endl;
		return false;
	}

	map = new Map();
	keyHandler = new KeyboardHandling();

	std::unique_ptr<Entity> entity(new Entity("assets/Warrior_Idle.png", 0, 0));
	entity_list.push_back(std::move(entity));

	return 0;
}

void Game::render() {
	SDL_RenderClear(renderer);
	map->renderMap();
	for (auto& x : entity_list) {
		x->render();
	}
	SDL_RenderPresent(renderer);
}
void Game::update() {
	for (auto& x : entity_list) {
		x->update();
	}
}

void Game::handle_events() {
	for (auto& x : entity_list) {
		keyHandler->handle(x);
	}
}

bool Game::running() {
	return Game::isRunning;
}

void Game::clear() {
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}