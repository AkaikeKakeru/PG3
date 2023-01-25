#pragma once
#include "IShape.h"

class MyCircle : public IShape {
public:
  void Size() override;
  void Draw() override;

  MyCircle();
  ~MyCircle();
private:
  float x_= 0;
  float y_ = 0;
  float size_ = 0;
};
