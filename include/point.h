#ifndef POINT_H 
#define POINT_H

#include "raylib.h"
#include "settings.h"

class Point {
private:
  float x, y;
  Rectangle pointRectangle; 
  Vector2 positionH;
  Vector2 positionV;
  bool contact = false;
  Vector2 center;
public:
  Point(Vector2 center) {
    positionH = Vector2{((float)GetRandomValue(0 , 6)*(BLOCK)), -(0.5*BLOCK)};
    positionV = Vector2{-(0.5*BLOCK), ((float)GetRandomValue(0, 7)*BLOCK)};
    pointRectangle.width = BLOCK;
    pointRectangle.height = BLOCK;
    this->center = center; 
  }
  bool Collision() {
    if (CheckCollisionCircleRec(center, BLOCK/4, pointRectangle)) return true;
    return false;
  }
  void Draw() {
    contact = Collision();
    if (contact) { 
      pointRectangle.x = positionV.x; 
      pointRectangle.y = positionV.y;
    } else {
      pointRectangle.x = positionH.x; 
      pointRectangle.y = positionH.y;
    }
    DrawRectangleRec(pointRectangle, POINT);
  }
};

#endif //!POINT_H 
