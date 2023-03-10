#include <iostream>
#include "Game.h"

std::vector<std::unique_ptr<Entity>> Game::entity_list;
SDL_Renderer* Game::renderer = nullptr;
bool Game::isRunning = false;

KeyboardHandling handler;
Map* map {nullptr};

Game::Game() : window{ nullptr } {}
Game::~Game() {}

int Game::init(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		}
		else {
			std::cout << "renderer coud not created, SDL_Error: " << SDL_GetError();
			return -1;
		}
		isRunning = true;
	} 
	else {
		std::cout << "SDL could not initialized, SDL_Error:  " << SDL_GetError();
		return -1;
	}

	std::unique_ptr<Entity> entity(new Entity("assets/Warrior_Idle.png", 0, 0));
	map = new Map();
	Game::entity_list.push_back(std::move(entity));

	return 0;
}

void Game::render() {
	SDL_RenderClear(renderer);
	map->renderMap();
	for (auto& x : Game::entity_list) {
		x->render();
	}
	SDL_RenderPresent(renderer);
}
void Game::update() {
	for (auto& x : Game::entity_list) {
		x->update();
	}
}

void Game::handle_events() {
	for (auto& x : Game::entity_list) {
		handler.handle(x);
	}
}

bool Game::running() {
	return Game::isRunning;
}

void Game::clear() {
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(window);
	delete map;
	SDL_Quit();
}