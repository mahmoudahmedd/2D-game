#include "player.h"
#include "TextureHolder.h"

Player::Player()
{
	this->speed = START_SPEED;
	this->health = START_HEALTH;
	this->maxHealth = START_HEALTH;
}

void Player::resetPlayerStats()
{
	this->speed = START_SPEED;
	this->health = START_HEALTH;
	this->maxHealth = START_HEALTH;
}

void Player::spawn(IntRect _arena, Vector2f _resolution, int _tileSize, std::string _playerImage)
{
	// Associate a texture with the sprite
	// !!Watch this space!!
	this->sprite = Sprite(TextureHolder::GetTexture("graphics/" + _playerImage));

	// Set the origin of the sprite to the centre, 
	// for smooth rotation
	this->sprite.setOrigin(25, 25);
	this->sprite.scale(0.15, 0.15);

	// Place the player in the middle of the arena
	this->position.x = _arena.width / 2;
	this->position.y = _arena.height / 2;

	// Copy the details of the arena to the player's m_Arena
	this->arena.left = _arena.left;
	this->arena.width = _arena.width;
	this->arena.top = _arena.top;
	this->arena.height = _arena.height;

	// Remember how big the tiles are in this arena
	this->tileSize = _tileSize;

	// Strore the resolution for future use
	this->resolution.x = _resolution.x;
	this->resolution.y = _resolution.y;

}

Time Player::getLastHitTime()
{
	return this->lastHit;
}

bool Player::hit(Time _timeHit)
{
	// 2 tenths of second
	if (_timeHit.asMilliseconds() - this->lastHit.asMilliseconds() > 200)
	{
		this->lastHit = _timeHit;
		this->health -= 10;
		return true;
	}
	else
	{
		return false;
	}

}

FloatRect Player::getPosition()
{
	return this->sprite.getGlobalBounds();
}

Vector2f Player::getCenter()
{
	return this->position;
}

float Player::getRotation()
{
	return this->sprite.getRotation();
}

Sprite Player::getSprite()
{
	return this->sprite;
}

int Player::getHealth()
{
	return this->health;
}

void Player::moveLeft()
{
	this->leftPressed = true;
}

void Player::moveRight()
{
	this->rightPressed = true;
}

void Player::moveUp()
{
	this->upPressed = true;
}

void Player::moveDown()
{
	this->downPressed = true;
}

void Player::stopLeft()
{
	this->leftPressed = false;
}

void Player::stopRight()
{
	this->rightPressed = false;
}

void Player::stopUp()
{
	this->upPressed = false;
}

void Player::stopDown()
{
	this->downPressed = false;
}

void Player::update(float _elapsedTime, Vector2i _mousePosition)
{

	if (this->upPressed)
	{
		this->position.y -= this->speed * _elapsedTime;
	}

	if (this->downPressed)
	{
		this->position.y += this->speed * _elapsedTime;
	}

	if (this->rightPressed)
	{
		this->position.x += this->speed * _elapsedTime;
	}

	if (this->leftPressed)
	{
		this->position.x -= this->speed * _elapsedTime;
	}

	this->sprite.setPosition(this->position);

	// Keep the player in the arena
	if (this->position.x > this->arena.width - this->tileSize)
	{
		this->position.x = this->arena.width - this->tileSize;
	}

	if (this->position.x < this->arena.left + this->tileSize)
	{
		this->position.x = this->arena.left + this->tileSize;
	}

	if (this->position.y > this->arena.height - this->tileSize)
	{
		this->position.y = this->arena.height - this->tileSize;
	}

	if (this->position.y < this->arena.top + this->tileSize)
	{
		this->position.y = this->arena.top + this->tileSize;
	}

	float xCoordinate = _mousePosition.x - this->resolution.x / 2;
	float yCoordinate = _mousePosition.y - this->resolution.y / 2;

	// Calculate the angle the player is facing
	float angle = (atan2(yCoordinate, xCoordinate) * 180) / 3.141;

	this->sprite.setRotation(angle + 30);
}

void Player::upgradeSpeed()
{
	// 20% speed upgrade
	this->speed += (START_SPEED * .2);
}

void Player::upgradeHealth()
{
	// 20% max health upgrade
	this->maxHealth += (START_HEALTH * .2);

}

void Player::increaseHealthLevel(int _amount)
{
	this->health += _amount;

	// But not beyond the maximum
	if (this->health > this->maxHealth)
	{
		this->health = this->maxHealth;
	}
}

