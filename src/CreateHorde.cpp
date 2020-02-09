#include "Zombie.h"

Zombie* createHorde(int _numZombies, IntRect _arena)
{
	Zombie* zombies = new Zombie[_numZombies];

	int maxY = _arena.height - 20;
	int minY = _arena.top + 20;
	int maxX = _arena.width - 20;
	int minX = _arena.left + 20;

	for (int i = 0; i < _numZombies; i++)
	{

		// Which side should the zombie spawn
		srand((int)time(0) * i);
		int side = (rand() % 4);
		float x, y;

		switch (side)
		{
		case 0:
			// left
			x = minX;
			y = (rand() % maxY) + minY;
			break;

		case 1:
			// right
			x = maxX;
			y = (rand() % maxY) + minY;
			break;

		case 2:
			// top
			x = (rand() % maxX) + minX;
			y = minY;
			break;

		case 3:
			// bottom
			x = (rand() % maxX) + minX;
			y = maxY;
			break;
		}

		// Bloater, crawler or runner
		srand((int)time(0) * i * 2);
		int type = (rand() % 3);

		// Spawn the new zombie into the array
		zombies[i].spawn(x, y, type, i);

	}
	return zombies;
}