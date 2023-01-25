#include "Enemy.h"
#include <stdio.h>

void (Enemy::* Enemy::spfuncTable[])()
= {
  &Enemy::Approach,
  &Enemy::Fire,
  &Enemy::Secession
};

void Enemy::Update() {
  //現在シーンを呼び出す
  (this->*spfuncTable[phase_])();
}

void Enemy::Approach(){
  printf_s("敵は接近してきた\n");
  SetPhase(firePhase);
}

void Enemy::Fire(){
  printf_s("敵は射撃してきた\n");
  SetPhase(secessionPhase);
}

void Enemy::Secession(){
  printf_s("敵は離脱していった\n");
  isEnd_ = true;
}
