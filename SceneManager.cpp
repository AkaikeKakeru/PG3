#include "SceneManager.h"

SceneManager* SceneManager::GetInstance() {
  //関数内でstatic変数として宣言
  static SceneManager instance;
  return &instance;
}
