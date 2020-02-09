#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

// How fast is each zombie type?
const float BLOATER_SPEED = 40;
const float CHASER_SPEED = 80;
const float CRAWLER_SPEED = 20;

// How tough is each zombie type
const float BLOATER_HEALTH = 5;
const float CHASER_HEALTH = 1;
const float CRAWLER_HEALTH = 3;

// Make each zombie vary its speed slightly
const int MAX_VARRIANCE = 30;
const int OFFSET = 101 - MAX_VARRIANCE;

class Zombie
{
private:
	// Where is this zombie?
	Vector2f position;

	// A sprite for the zombie
	Sprite sprite;

	// How fast can this one run/crawl?
	float speed;

	// How much health has it got?
	float health;

	// Is it still alive?
	bool alive;
public:
	// Handle when a bullet hits a zombie
	bool hit();

	// Find out if the zombie is alive
	bool isAlive();

	// Spawn a new zombie
	void spawn(float _startX, float _startY, int _type, int _seed);

	// Return a rectangle that is the position in the world
	FloatRect getPosition();

	// Get a copy of the sprite to draw
	Sprite getSprite();

	// Update the zombie each frame
	void update(float _elapsedTime, Vector2f _playerLocation);
};


