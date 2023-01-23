#include <windows.h>
#include <stdio.h>
#include "SceneManager.h"

int main(void){
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  SceneManager* sceneManager_ = SceneManager::GetInstance();

  while (true){
    char c = 'r';
    char Change = 'c';
    char End = 'e';
    char Reset = 'r';

    printf_s("Input [c] to Change Scene");

    scanf_s("%s", &c,1);


    if (c == End) {
      break;
    }

    if (c == Change){
      sceneManager_->Update();
    }

    sceneManager_->Draw();

    c = Reset;
  }

  system("pause");
  return 0;
}
