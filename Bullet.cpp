#include "./Header/Bullet.h"
#include <Novice.h>

Bullet::Bullet(int speed, int radius) {
	posX_ = 0;
	posY = 0;
	bulletSpeed = speed;
	bulletRadius = radius;
	isShot = false;
}

void Bullet::Reset()
{
	isShot = false;
}

void Bullet::Update() {
	if (isShot == true) {
		posY += bulletSpeed;
	}
	if (posY <= 0) {
		isShot = false;
	}
}

void Bullet::Draw() {
	if (isShot == true) {
		Novice::DrawEllipse(posX_, posY, bulletRadius, bulletRadius, 0.0f, WHITE, kFillModeSolid);
	}
}