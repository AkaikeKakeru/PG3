#include <windows.h>
#include <stdio.h>
#include "Enemy.h"

int main(void){
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  Enemy* enemy = new Enemy;

  while(true){
    enemy->Update();

    if (enemy->GetIsEnd()) {
     return 0;
    }
  }

  delete enemy;
  system("pause");
  return 0;
}
