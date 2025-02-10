#include "Player.h"
#include <Novice.h>



Player::Player()
{
	bullet_ = new Bullet(-10, 5);
	posX_ = 640;
	posY_ = 700;
	speed_ = 8;
	radius_ = 16;
	isAlive_ = false;
}

void Player::Reset()
{
	posX_ = 640;
	posY_ = 700;
	isAlive_ = false;
	bullet_->posY_=-100;
}



void Player::Update(char* keys, char* preKeys)
{
	if (keys[DIK_A])
	{
		posX_ = posX_ - speed_;
	}
	if (keys[DIK_D])
	{
		posX_ = posX_ + speed_;
	}
	if (keys[DIK_W])
	{
		posY_ = posY_ - speed_;
	}
	if (keys[DIK_S])
	{
		posY_ = posY_ + speed_;
	}
	if (posX_ + 16 >= 1280) {
		posX_ = 1280 - 16;
	}
	if (posX_ - 16 <= 0) {
		posX_ = 0 + 16;
	}
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && bullet_->isShot_ == false) {
		bullet_->isShot_=true;
		bullet_->posX_ = posX_;
		bullet_->posY_ = posY_;
	}
	bullet_->Update();
}

void Player::Draw()
{
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	bullet_->Draw();
}