#include "KeyboardHandling.h"
#include "Game.h"

void KeyboardHandling::handle(std::unique_ptr<Entity>& entity) {
	if (SDL_PollEvent(&event) != 0) {
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
				if (entity->getVelocityX() > 0) {
					entity->setVelX(0);
					entity->setState(0);
					break;
				}
				if (entity->getVelocityX() != -4) {
					entity->decreaseVelX();
				}
				entity->setDirection(SDL_FLIP_HORIZONTAL);
				if (entity->getState() != 8) {
					entity->increaseState();
					break;
				}
				entity->setState(1);
				break;
			//case SDLK_s:
				//	entity->setVelocityY(Entity::ONE);
				//	break;
			case SDLK_d:
				if (entity->getVelocityX() < 0) {
					entity->setVelX(0);
					entity->setState(0);
					break;
				}
				if (entity->getVelocityX() != 4) {
					entity->increaseVelX();
				}
				entity->setDirection(SDL_FLIP_NONE);
				if (entity->getState() != 8) {
					entity->increaseState();
					break;
				}
				entity->setState(1);
				break;
			default:
				entity->setVelX(0);
				entity->setState(0);
				break;
			}
		}

		else if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			//case SDLK_w:
				//	entity->setVelocityY(Entity::ZERO);
				//	break;
			case SDLK_a:
				if (entity->getVelocityX() != 0) {
					entity->setVelX(0);
					entity->setState(0);
				}
				break;
			//case SDLK_s:
				//	entity->setVelocityY(Entity::ZERO);
				//	break;
			case SDLK_d:
				if (entity->getVelocityX() != 0) {
					entity->setVelX(0);
					entity->setState(0);
				}
				break;
			default:

				break;
			}
		}
	}
}	
