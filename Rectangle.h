#pragma once
#include "IShape.h"

class MyRectangle : public IShape{
public:
  void Size() override;
  void Draw() override;

  MyRectangle();
  ~MyRectangle();
private:
  float x_= 0;
  float y_ = 0;
  float size_ = 0;
};
