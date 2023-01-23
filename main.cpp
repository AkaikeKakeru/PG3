#include <windows.h>
#include <stdio.h>
#include "SceneManager.h"

int main(void){
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  SceneManager* sceneManager_ = SceneManager::GetInstance();

  while (true){
    const char* c = "a";
    const char* C = "c";
    const char* E = "e";

    printf_s("Input [c] to Change Scene");


    if (c == E) {
      break;
    }

    if (c == C){
      c = "a";
      sceneManager_->Update();
    }

    sceneManager_->Draw();
    //scanf_s("%s", &c);
  }

  system("pause");
  return 0;
}
