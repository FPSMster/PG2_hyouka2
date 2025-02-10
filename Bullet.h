#pragma once
class Bullet
{
public:


	int posX_;
	int posY_;
	int speed_;
	int radius_;

	bool isShot_;

	Bullet(int speed, int radius);

	void Reset();

	void Update();
	void Draw();
};
