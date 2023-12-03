#ifndef POINT_H 
#define POINT_H

#include "raylib.h"
#include "settings.h"

#include <iostream>

class Point {
private:
  float x, y;
  Rectangle pointRectangle; 
  Vector2 positionH;
  Vector2 positionV;
  bool contact = false;
public:
  Point() {
    positionH = Vector2{((float)GetRandomValue(0 , 6)*(BLOCK)), -(0.5*BLOCK)};
    positionV = Vector2{-(0.5*BLOCK), ((float)GetRandomValue(0, 7)*BLOCK)};
    pointRectangle.width = BLOCK;
    pointRectangle.height = BLOCK;
  }
  void Randomize() {
    positionH = Vector2{((float)GetRandomValue(0 , 6)*(BLOCK)), -(0.5*BLOCK)};
  }
  bool Collision(Vector2 center) {
    if (CheckCollisionCircleRec(center, (float)BLOCK/4, pointRectangle)) return true;
    return false;
  }
  bool Draw(Vector2 center) {
    contact = Collision(center);
    pointRectangle.x = positionH.x; 
    pointRectangle.y = positionH.y;
    if (contact) {
      Randomize();
      return true;
    }
    DrawRectangleRec(pointRectangle, POINT);
    return false;
  }
};

#endif //!POINT_H 
