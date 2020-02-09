#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

const float START_SPEED = 200;
const float START_HEALTH = 100;

class Player
{
private:
	// Where is the player
	Vector2f position;

	// Of course we will need a sprite
	Sprite sprite;

	// And a texture
	// !!Watch this space!!
	Texture texture;

	// What is the screen resolution
	Vector2f resolution;

	// What size is the current arena
	IntRect arena;

	// How big is each tile of the arena
	int tileSize;

	// Which directions is the player currently moving in
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;

	// How much health has the player got?
	int health;
	// What is the maximum health the player can have
	int maxHealth;

	// When was the player last hit
	Time lastHit;

	// Speed in pixels per second
	float speed;
public:

	Player();

	// Call this at the end of every game
	void resetPlayerStats();

	void spawn(IntRect _arena, Vector2f _resolution, int _tileSize, std::string _playerImage);

	// Handle the player getting hit by a zombie
	bool hit(Time _timeHit);

	// How long ago was the player last hit
	Time getLastHitTime();

	// Where is the player
	FloatRect getPosition();

	// Where is the center of the player
	Vector2f getCenter();

	// Which angle is the player facing
	float getRotation();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// How much health has the player currently got?
	int getHealth();

	// The next four functions move the player
	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	// Stop the player moving in a specific direction
	void stopLeft();

	void stopRight();

	void stopUp();

	void stopDown();

	// We will call this function once every frame
	void update(float _elapsedTime, Vector2i _mousePosition);

	// Give player a speed boost
	void upgradeSpeed();

	// Give the player some health
	void upgradeHealth();

	// Increase the maximum amount of health the player can have
	void increaseHealthLevel(int _amount);
};




