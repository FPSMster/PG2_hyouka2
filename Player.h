#pragma once
#include "Bullet.h"

class Player
{
private:

	int posX_;
	int posY_;
	int speed_;
	int radius_;

	

public:
	bool isAlive_;

	int GetPosX_() { return posX_; };
	int GetPosY_() { return posY_; };
	int GetSpeed_() { return speed_; };
	int GetRadius_() { return radius_; };
	

	Bullet* bullet_;

	Player();

	void Reset();

	void Update(char* keys, char* preKeys);

	void Draw();

};
