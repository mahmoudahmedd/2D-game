#include "Pickup.h"
#include "TextureHolder.h"

Pickup::Pickup(int _type)
{
	// Store the type of this pickup
	this->type = _type;

	// Associate the texture with the sprite
	if (this->type == 1)
	{
		this->sprite = Sprite(TextureHolder::GetTexture("graphics/health_pickup.png"));

		// How much is pickup worth
		this->value = HEALTH_START_VALUE;

	}
	else
	{
		this->sprite = Sprite(TextureHolder::GetTexture("graphics/ammo_pickup.png"));

		// How much is pickup worth
		this->value = AMMO_START_VALUE;
	}

	this->sprite.setOrigin(25, 25);

	this->secondsToLive = START_SECONDS_TO_LIVE;
	this->secondsToWait = START_WAIT_TIME;
}

void Pickup::setArena(IntRect _arena)
{

	// Copy the details of the arena to the pickup's m_Arena
	this->arena.left = _arena.left + 50;
	this->arena.width = _arena.width - 50;
	this->arena.top = _arena.top + 50;
	this->arena.height = _arena.height - 50;

	spawn();
}

void Pickup::spawn()
{
	// Spawn at a random location
	srand((int)time(0) / this->type);
	int x = (rand() % this->arena.width);
	srand((int)time(0) * this->type);
	int y = (rand() % this->arena.height);

	// Not currently spawned
	//m_Spawned = false;
	this->secondsSinceSpawn = 0;
	this->spawned = true;
	
	this->sprite.setPosition(x, y);
}

FloatRect Pickup::getPosition()
{
	return this->sprite.getGlobalBounds();
}

Sprite Pickup::getSprite()
{
	return this->sprite;
}

bool Pickup::isSpawned()
{
	return this->spawned;
}

int Pickup::gotIt()
{
	this->spawned = false;
	this->secondsSinceDeSpawn = 0;
	return this->value;
}

void Pickup::update(float _elapsedTime)
{
	if (this->spawned)
	{
		this->secondsSinceSpawn += _elapsedTime;
	}
	else
	{
		this->secondsSinceDeSpawn += _elapsedTime;
	}


	// Do we need to hide a pickup?
	if (this->secondsSinceSpawn > this->secondsToLive && this->spawned)
	{
		// Revove the pickup and put it somewhere else
		this->spawned = false;
		this->secondsSinceDeSpawn = 0;
	}

	// Do we need to spawn a pickup
	if (this->secondsSinceDeSpawn > this->secondsToWait && !this->spawned)
	{
		// spawn the pickup and reset the timer
		spawn();
	}

}

void Pickup::upgrade()
{
	if (this->type == 1)
	{
		this->value += (HEALTH_START_VALUE * .5);
	}
	else
	{
		this->value += (AMMO_START_VALUE * .5);
	}

	// Make them more frequent and last longer
	this->secondsToLive += (START_SECONDS_TO_LIVE / 10);
	this->secondsToWait -= (START_WAIT_TIME / 10);
}
