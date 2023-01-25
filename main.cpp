#include <windows.h>
#include <stdio.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main(void){
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  IShape* iShape[2];

  for (size_t i = 0; i < 2; i++) {
    if (i == 0) {
      iShape[i] = new MyCircle();
    }
    else{
      iShape[i] = new MyRectangle();
    }
  }

  for (size_t i = 0; i < 2; i++) {
    iShape[i]->Size();
    iShape[i]->Draw();
  }

  for (size_t i = 0; i < 2; i++) {
    delete iShape[i];
  }

  system("pause");
  return 0;
}
