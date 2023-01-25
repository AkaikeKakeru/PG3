#pragma once

class Enemy{
protected:
public:
  static int enemyCount_;
  static bool isAlive_;

  Enemy() {
    enemyCount_++;
    isAlive_ = true;
  };

  ~Enemy() { enemyCount_--; };
};
