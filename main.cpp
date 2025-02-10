#include <Novice.h>
#include"Enemy.h"
#include"Player.h"
#include"Bullet.h"

const char kWindowTitle[] = "学籍番号";

//bool Enemy::isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Enemy* enemy[2];
	enemy[0] = new Enemy(320, 180);
	enemy[1] = new Enemy(480, 240);

	Player* player = new Player();

	enum Scene {
		TITLE,
		GAMESCENE,
		GAMECLEAR,
		GAMEOVER,
	};
	int scene = TITLE;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case TITLE:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = GAMESCENE;
			}
			
			break;
		case GAMESCENE:
			


			for (int i = 0; i < 2; i++) {
				enemy[i]->Update();
				float distX = static_cast<float> (enemy[i]->GetPosX_() - player->bullet_->posX_);
				float distY = static_cast<float> (enemy[i]->GetPosY_() - player->bullet_->posY_);
				float dist = (distX * distX) + (distY * distY);
				int radius = enemy[i]->GetRadius_() + enemy[i]->GetRadius_();
				if (dist <= radius * radius) {
					enemy[i]->isAlive=false;
				}

				if (enemy[i]->isAlive==false) {
					scene = GAMECLEAR;
				}

				float peX = static_cast<float> (enemy[i]->GetPosX_() - player->GetPosX_());
				float peY = static_cast<float> (enemy[i]->GetPosY_() - player->GetPosY_());
				float pe = (peX * peX) + (peY * peY);
				int peRadius = enemy[i]->GetRadius_() + enemy[i]->GetRadius_();
				if (pe <= peRadius * peRadius) {
					player->isAlive_=true;
				}
			}

			player->Update(keys, preKeys);

			
				
				if (player->isAlive_ == true) {
					scene = GAMEOVER;
				}

			break;
		case GAMECLEAR:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {	
				player->Reset();
				for (int i = 0; i < 2; i++)
				{
					enemy[i]->Reset();
				}
				
				scene = TITLE;
			}
			break;
		case GAMEOVER:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				player->Reset();
				for (int i = 0; i < 2; i++)
				{
					enemy[i]->Reset();
				}
				scene = TITLE;
			}
			break;
		}




		




		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene)
		{
		case TITLE:
			Novice::ScreenPrintf(600, 340, "Press Space To Start");

			break;
		case GAMESCENE:

			for (int i = 0; i < 2; i++)
			{
				enemy[i]->Draw();
			}

			player->Draw();
			

			break;
		case GAMECLEAR:
			Novice::ScreenPrintf(600, 340, "GameClear");
			Novice::ScreenPrintf(1100, 680, "Press Space To Title");
			break;
		case GAMEOVER:
			Novice::ScreenPrintf(600, 340, "GameOver");
			Novice::ScreenPrintf(1100, 680, "Press Space To Title");
			break;
		}

		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}