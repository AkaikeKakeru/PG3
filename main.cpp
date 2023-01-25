#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "Enemy.h"

int Enemy::enemyCount_;

int main(void) {
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  Enemy* enemy1 = new Enemy;
  Enemy* enemy2 = new Enemy;
  Enemy* enemy3 = new Enemy;

  std::cout << Enemy::enemyCount_ << std::endl;
  delete enemy1;
  std::cout << Enemy::enemyCount_ << std::endl;
  delete enemy2;
  delete enemy3;
  std::cout << Enemy::enemyCount_ << std::endl;

  //ループ
  while (true) {
    return 0;
  }

  system("pause");
  return 0;
}
