#include "./Header/Enemy.h"
#include <Novice.h>

Enemy::Enemy(int posX, int posY)
{
	posX_ = posX;
	posY_ = posY;
	speed_ = 10;
	radius_ = 16;
	isAlive = true;
}

void Enemy::Reset()
{
	speed_ = 10;
	isAlive = true;
}

void Enemy::Update()
{

	if (isAlive == 1) {
		posX_ += speed_;

		if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
			speed_ *= -1;
		}
	}


}

void Enemy::Draw()
{
	if (isAlive == 1) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}


}