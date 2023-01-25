#pragma once

class Enemy{
protected:
public:
  static int enemyCount_;
  Enemy() { enemyCount_++; };
  ~Enemy() { enemyCount_--; };
};
