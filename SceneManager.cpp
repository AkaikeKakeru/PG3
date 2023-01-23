#include "SceneManager.h"
#include <stdio.h>

void SceneManager::Update(){
  char c = 0;
  scanf_s("%c" ,)
}

void SceneManager::Draw() {
    printf_s("SceneNum : %d\nPress SPACE to Change Screen", nowSceneNom_);
}

SceneManager* SceneManager::GetInstance() {
  //関数内でstatic変数として宣言
  static SceneManager instance;
  return &instance;
}
