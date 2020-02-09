#include <cstdlib>
#include <ctime>

#include "zombie.h"
#include "TextureHolder.h"

using namespace std;

void Zombie::spawn(float _startX, float _startY, int _type, int _seed)
{
	switch (_type)
	{
	case 0:
		// Bloater
		this->sprite = Sprite(TextureHolder::GetTexture("graphics/bloater.png"));

		this->speed = 40;
		this->health = 5;
		break;

	case 1:
		// Chaser
		this->sprite = Sprite(TextureHolder::GetTexture("graphics/chaser.png"));

		this->speed = 70;
		this->health = 1;
		break;

	case 2:
		// Crawler
		this->sprite = Sprite(TextureHolder::GetTexture("graphics/crawler.png"));

		this->speed = 20;
		this->health = 3;
		break;
	}

	// Modify the speed to make the zombie unique
	// Every zombie is unique. Create a speed modifier
	srand((int)time(0) * _seed);
	// Somewhere between 80 an 100
	float modifier = (rand() % MAX_VARRIANCE) + OFFSET;
	// Express as a fraction of 1
	modifier /= 100; // Now equals between .7 and 1
	this->speed *= modifier;

	this->position.x = _startX;
	this->position.y = _startY;

	this->sprite.setOrigin(25, 25);
	this->sprite.setPosition(this->position);
}

bool Zombie::hit()
{
	this->health--;

	if (this->health < 0)
	{
		// dead
		this->alive = false;
		this->sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));

		return true;
	}

	// injured but not dead yet
	return false;
}

bool Zombie::isAlive()
{
	return this->alive;
}

FloatRect Zombie::getPosition()
{
	return this->sprite.getGlobalBounds();
}


Sprite Zombie::getSprite()
{
	return this->sprite;
}

void Zombie::update(float _elapsedTime, Vector2f _playerLocation)
{
	float playerX = _playerLocation.x;
	float playerY = _playerLocation.y;

	// Update the zombie position variables
	if (playerX > this->position.x)
	{
		this->position.x = this->position.x + this->speed * _elapsedTime;
	}

	if (playerY > this->position.y)
	{
		this->position.y = this->position.y + this->speed * _elapsedTime;
	}

	if (playerX < this->position.x)
	{
		this->position.x = this->position.x - this->speed * _elapsedTime;
	}

	if (playerY < this->position.y)
	{
		this->position.y = this->position.y - this->speed * _elapsedTime;
	}

	// Move the sprite
	this->sprite.setPosition(this->position);

	float xCoordinate = playerX - this->position.x;
	float yCoordinate = playerY - this->position.y;

	// Face the sprite in the correct direction
	float angle = (atan2(yCoordinate, xCoordinate) * 180) / 3.141;

	this->sprite.setRotation(angle);
}