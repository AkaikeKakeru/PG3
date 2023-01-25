#include "Rectangle.h"
#include <stdio.h>

void MyRectangle::Size(){
  size_ = x_ * y_;
}

void MyRectangle::Draw(){
  printf("RectangleSize:%2.1f\n", size_);
}

MyRectangle::MyRectangle(){
  x_ = 4.0f;
  y_ = 8.0f;
}

MyRectangle::~MyRectangle(){
}
