#pragma once

class Enemy {
public:
  enum PhaseEnum {
    approachPhase,//接近
    firePhase,//射撃
    secessionPhase//離脱
  };

public:
  void Update();

  //フェーズセット
  void SetPhase(size_t phase) { phase_ = phase; }
  //終了取得
  bool GetIsEnd() const { return isEnd_; }

private:
  size_t phase_ = 0;
  bool isEnd_ = false;

  static void (Enemy::* spfuncTable[])();
  void Approach();//接近
  void Fire();//射撃
  void Secession();//離脱
};
