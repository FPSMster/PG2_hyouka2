#pragma once
class Enemy
{
private:

	int posX_;
	int posY_;
	int speed_;
	int radius_;
	

public:

	bool isAlive;

	int GetPosX_() { return posX_; };
	int GetPosY_() { return posY_; };
	int GetSpeed_() { return speed_; };
	int GetRadius_() { return radius_; };
	

	Enemy(int posX, int posY);

	void Reset();

	void Update();
	void Draw();

};
