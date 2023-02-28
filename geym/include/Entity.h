#pragma once
#include "SDL.h"

#define ENTITY_WIDTH 80
#define ENTITY_HEIGHT 80

class Entity {

public:
	Entity(const char* filename, int pix_x, int pix_y);
	~Entity();
	void update();
	void render();

	enum vel { NONE = -2, ZERO = 0, ONE = 2 };
	enum dir {RIGHT, LEFT};

	SDL_Rect& getSrcRect();
	SDL_Rect& getDestRect();

	int getState();
	void changeState();
	void setState(int state);
	void setDirection(SDL_RendererFlip flip);

	void setVelocityX(vel vel);
	void setVelocityY(vel vel);

private:
	struct{
		vel x{ZERO};
		vel y{ZERO};
	} Velocity;

	SDL_RendererFlip direction;
	SDL_Texture* texture[9];
	int state;

	struct {
		SDL_Rect src;
		SDL_Rect dest;
	} Rects;
};
