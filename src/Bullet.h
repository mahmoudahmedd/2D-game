#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet
{
private:
	// Where is the bullet?
	Vector2f position;

	// What each bullet looks like
	RectangleShape bulletShape;

	// Is this bullet currently whizzing through the air
	bool inFlight = false;

	// How fast does a bullet travel?
	float bulletSpeed = 1000;

	// What fraction of 1 pixel does the bullet travel, 
	// Horizontally and vertically each frame?
	// These values will be derived from m_BulletSpeed
	float bulletDistanceX;
	float bulletDistanceY;

	// Where is this bullet headed to?
	float xTarget;
	float yTarget;

	// Some boundaries so the bullet doesn't fly forever
	float maxX;
	float minX;
	float maxY;
	float minY;

// Public function prototypes go here
public:
	// The constructor
	Bullet();

	// Stop the bullet
	void stop();

	// Returns the value of m_InFlight
	bool isInFlight();

	// Launch a new bullet
	void shoot(float _startX, float _startY, float _xTarget, float _yTarget);

	// Tell the calling code where the bullet is in the world
	FloatRect getPosition();

	// Return the actual shape (for drawing)
	RectangleShape getShape();

	// Update the bullet each frame
	void update(float _elapsedTime);

};