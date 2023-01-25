#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "Enemy.h"

//静的 敵の数
int Enemy::enemyCount_;
//静的 敵の生存
bool Enemy::isAlive_ = true;

int main(void) {
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  //攻撃
  bool attack = true;

  //敵の配列
  Enemy* enemys[5];

  //インスタンス
  for (size_t i = 0; i < _countof(enemys); i++) {
    enemys[i] = new Enemy;
  }
  printf_s("敵の群れが現れた\n");
  std::cout << Enemy::enemyCount_ << std::endl;
  printf_s("\n");

  //攻撃boolがtrueなら
  if (attack) {
    //1体、生存boolをfalseに
    printf_s("敵を一体撃破\n\n");
    enemys[3]->isAlive_ = false;
  }

  //静的 生存boolがfalseなら
  if (Enemy::isAlive_ == false) {
    for (size_t i = 0; i < _countof(enemys); i++) {
      delete enemys[i];
    }
    printf_s("残り\n");
    std::cout << Enemy::enemyCount_ << std::endl;
  }
  else {
    printf_s("残り\n");
    std::cout << Enemy::enemyCount_ << std::endl;
    for (size_t i = 0; i < _countof(enemys); i++) {
      delete enemys[i];
    }
  }

  system("pause");
  return 0;
}
