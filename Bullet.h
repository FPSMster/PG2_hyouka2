#pragma once
class Bullet
{
private:


	int posX_;
	int posY;
	int bulletSpeed;
	int bulletRadius;
	bool isShot;

public:

	Bullet(int speed, int radius);

	void Reset();

	void Update();
	void Draw();
};
