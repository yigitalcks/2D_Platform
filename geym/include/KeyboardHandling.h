#pragma once
#include "Entity.h"
#include <memory>

class KeyboardHandling {
public:
	void handle(std::unique_ptr<Entity>& entity);
private:
	SDL_Event event;
};