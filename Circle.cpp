#include "Circle.h"
#include <stdio.h>

void MyCircle::Size(){
  const float PI = 3.14159f;
  size_ = (x_ / 2 * y_ / 2) * PI;
}

void MyCircle::Draw() {
  printf("CircleSize:%2.1f\n", size_);
}

MyCircle::MyCircle(){
  x_ = 4.0f;
  y_ = 8.0f;
}

MyCircle::~MyCircle(){
}
