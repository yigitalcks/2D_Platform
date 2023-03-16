#pragma once

constexpr auto ENTITY_WIDTH = 80;
constexpr auto ENTITY_HEIGHT = 80;

constexpr auto MAX_VEL = 4;
constexpr auto MIN_VEL = -4;

#include "SDL2/SDL.h"

class Entity {

public:
	Entity(const char* filename, int pix_x, int pix_y);
	~Entity();
	void update();
	void render();

	enum dir {RIGHT, LEFT};

	SDL_Rect& getSrcRect();
	SDL_Rect& getDestRect();

	int getState() const;
	void increaseState();
	void decreaseState();
	void setState(int state);

	void setDirection(SDL_RendererFlip flip);

	int getVelocityX();
	//int getVelocityY();

	void increaseVelX();
	void decreaseVelX();
	void setVelX(int vel);
	void setVelY(int vel);

private:
	struct{
		int x{};
		int y{};
	} Velocity;

	SDL_RendererFlip direction;
	SDL_Texture* texture[9];
	int state;

	struct {
		SDL_Rect src{NULL};
		SDL_Rect dest{NULL};
	} Rects;
};
