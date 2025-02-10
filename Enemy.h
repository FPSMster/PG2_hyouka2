#pragma once
class Enemy
{
private:

	int posX_;
	int posY_;
	int speed_;
	int radius_;
	static int isAlive;

public:

	Enemy(int posX, int posY);

	void Reset();

	void Update();
	void Draw();

};
