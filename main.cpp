#include <windows.h>
#include <stdio.h>
#include "SceneManager.h"

int main(void){
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  SceneManager* sceneManager_ = SceneManager::GetInstance();

  while (true){


    sceneManager_->Draw();
  }

  system("pause");
  return 0;
}
