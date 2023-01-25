#include "SceneManager.h"
#include <stdio.h>

void SceneManager::Update(){
  int next = nowSceneNom_+1;

  if (next > gameClear_num) {
    next = title_num;
  }

  ChangeScene(next);
}

void SceneManager::Draw() {
  printf_s(
    "Scene : %s\n",
    sceneName);

  printf_s(
    "SceneNum : %d\n\n",
    nowSceneNom_);}

void SceneManager::ChangeScene(int nextSceneNom){
  nowSceneNom_ = nextSceneNom; 

  switch (nowSceneNom_) {
  case title_num:
    sceneName = "Title";
    break;

  case newGame_num:
    sceneName = "NewGame";
    break;

  case gamePlay_num:
    sceneName = "GamePlay";
    break;

  case gameClear_num:
    sceneName = "GameClear";
    break;

  default:
    nowSceneNom_ = title_num;
    sceneName = "Title";
    break;
  }
};

SceneManager::~SceneManager(){
}

SceneManager* SceneManager::GetInstance() {
  //関数内でstatic変数として宣言
  static SceneManager instance;
  return &instance;
}
