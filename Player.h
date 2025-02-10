#pragma once
#include "./Header/Bullet.h"

class Player
{
private:

	int posX_;
	int posY_;
	int speed_;
	int radius_;

	bool isAlive;

public:

	Bullet* bullet_;

	Player();

	void Reset();

	void Update(char* keys, char* preKeys);

	void Draw();

};
