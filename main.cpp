#include <windows.h>
#include <stdio.h>
#include "SceneManager.h"

int main(void) {
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  //シーンマネージャーのインスタンス
  SceneManager* sceneManager_ = SceneManager::GetInstance();

  char input[2] = "r";
  const char Change[2] = "c";
  const char Reset[2] = "r";

  printf_s("c を入力するとシーン切り替え\n");
  printf_s("それ以外は終了\n\n");

  //最初のシーン表示
  sceneManager_->Draw();

  //ループ
  while (true) {

    //入力を受け付ける
    scanf_s("%s", input, 2);

    //cなら切り替え
    if (strcmp(input, Change) == 0) {
      sceneManager_->Update();
    }
    //それ以外は終了
    else{
      return 0;
    }

    //現在シーンを表示
    sceneManager_->Draw();

    //Inputをcではなくする
    for (size_t i = 0; i < sizeof(input); i++) {
      input[i] = Reset[i];
    }
  }

  system("pause");
  return 0;
}
