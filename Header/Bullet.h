#pragma once
class Bullet
{
public:

	int posX_;
	int posY;
	int bulletSpeed;
	int bulletRadius;
	bool isShot;

	Bullet(int speed, int radius);

	void Reset();

	void Update();
	void Draw();
};
