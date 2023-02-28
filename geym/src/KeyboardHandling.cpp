#include "../include/KeyboardHandling.h"
#include "../include/Game.h"

void KeyboardHandling::handle(std::unique_ptr<Entity>& entity) {
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) {
		Game::isRunning = false;
	}

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		//case SDLK_w:
		//	entity->setVelocityY(Entity::NONE);
		//	break;
		case SDLK_a:
			entity->setVelocityX(Entity::NONE);
			entity->setDirection(SDL_FLIP_HORIZONTAL);
			if (entity->getState() != 8) {
				entity->changeState();
			} 
			else {
				entity->setState(1);
			}
			break;
		//case SDLK_s:
		//	entity->setVelocityY(Entity::ONE);
		//	break;
		case SDLK_d:
			entity->setVelocityX(Entity::ONE);
			entity->setDirection(SDL_FLIP_NONE);
			if (entity->getState() != 8) {
				entity->changeState();
			}
			else {
				entity->setState(1);
			}
			break;
		default:
			break;
		}
	}

	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym)
		{
		//case SDLK_w:
		//	entity->setVelocityY(Entity::ZERO);
		//	break;
		case SDLK_a:
			entity->setVelocityX(Entity::ZERO);
			if (entity->getState() < 8 && entity->getState() > 0) {
				entity->setState(0);
			}
			else {
				entity->setState(0);
			}
			break;
		//case SDLK_s:
		//	entity->setVelocityY(Entity::ZERO);
		//	break;
		case SDLK_d:
			entity->setVelocityX(Entity::ZERO);
			if (entity->getState() < 8 && entity->getState() > 0) {
				entity->setState(0);
			}
			else {
				entity->setState(0);
			}
			break;
		default:
			if (entity->getState() < 8 && entity->getState() > 0) {
				entity->setState(0);
			}
			else {
				entity->setState(0);
			}
			break;
		}
	}
}
