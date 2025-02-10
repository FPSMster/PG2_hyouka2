#pragma once
#include "Bullet.h"

class Player
{
public:

	int posX_;
	int posY_;
	int speed_;
	int radius_;

	bool isAlive;

	Bullet* bullet_;

	Player();

	void Reset();

	void Update(char* keys, char* preKeys);

	void Draw();

};
