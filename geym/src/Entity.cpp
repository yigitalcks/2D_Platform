#include "Entity.h"
#include "Game.h"

Entity::Entity(const char* filename, int pix_x, int pix_y) : state{ 0 }, direction{SDL_FLIP_NONE} {
	texture[0] = TextureManager::LoadTexture(filename);
	texture[1] = TextureManager::LoadTexture("assets/Warrior_Run_1.png");
	texture[2] = TextureManager::LoadTexture("assets/Warrior_Run_2.png");
	texture[3] = TextureManager::LoadTexture("assets/Warrior_Run_3.png");
	texture[4] = TextureManager::LoadTexture("assets/Warrior_Run_4.png");
	texture[5] = TextureManager::LoadTexture("assets/Warrior_Run_5.png");
	texture[6] = TextureManager::LoadTexture("assets/Warrior_Run_6.png");
	texture[7] = TextureManager::LoadTexture("assets/Warrior_Run_7.png");
	texture[8] = TextureManager::LoadTexture("assets/Warrior_Run_8.png");

	Rects.src = { pix_x, pix_y, ENTITY_WIDTH / 2, ENTITY_WIDTH / 2 };
	Rects.dest = { 0, 280, ENTITY_WIDTH, ENTITY_HEIGHT };
}
Entity::~Entity() {
	for (int i = 0; i < 9; i++) {
		TextureManager::clearTexture(texture[i]);
	}
}

void Entity::update() {
	Rects.dest.x += Velocity.x;
	Rects.dest.y += Velocity.y;
}

void Entity::render() {
	SDL_RenderCopyEx(Game::renderer, texture[state], &Rects.src, &Rects.dest, 0.0, NULL, direction);
}

SDL_Rect& Entity::getSrcRect() {
	return Rects.src;
}

SDL_Rect& Entity::getDestRect() {
	return Rects.dest;
}
int Entity::getState() const {
	return state;
}
void Entity::setDirection(SDL_RendererFlip flip) {
	direction = flip;
}

void Entity::increaseVelX() {
	Velocity.x++;
}

void Entity::decreaseVelX() {
	Velocity.x--;
}

void Entity::setVelX(int vel) {
	Velocity.x = vel;
}
void Entity::setVelY(int vel) {
	Velocity.y = vel;
}

int Entity::getVelocityX() {
	return Velocity.x;
}

void Entity::setState(int state) {
	this->state = state;
}

void Entity::increaseState() {
	state++;
}
void Entity::decreaseState() {
	state--;
}