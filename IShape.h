#pragma once

class IShape {
public:
  virtual void Size() = 0;
  virtual void Draw() = 0;


  IShape() = default;
  virtual ~IShape() = default;
};
