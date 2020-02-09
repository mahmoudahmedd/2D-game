#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

//Start value for health pickups
const int HEALTH_START_VALUE = 50;
const int AMMO_START_VALUE = 12;
const int START_WAIT_TIME = 10;
const int START_SECONDS_TO_LIVE = 5;

class Pickup
{
private:
	// The sprite that represents this pickup
	Sprite sprite;

	// The arena it exists in
	IntRect arena;

	// How much is this pickup worth?
	int value;

	// What type of pickup is this? 
	// 1 = health, 2 = ammo
	int type;

	// Handle spawning and disappearing
	bool spawned;
	float secondsSinceSpawn;
	float secondsSinceDeSpawn;
	float secondsToLive;
	float secondsToWait;
public:
	Pickup::Pickup(int _type);

	// Prepare a new pickup
	void setArena(IntRect _arena);

	void spawn();

	// Check the position of a pickup
	FloatRect getPosition();

	// Get the sprite for drawing
	Sprite getSprite();

	// Let the pickup update itself each frame
	void update(float _elapsedTime);

	// Is this pickup currently spawned?
	bool isSpawned();

	// Get the goodness from the pickup
	int gotIt();

	// Upgrade the value of each pickup
	void upgrade();
};



