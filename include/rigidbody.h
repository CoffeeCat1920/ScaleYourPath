#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <iostream>

#include "raylib.h"
#include "settings.h"

class Ball {
private:
  int radius;
  bool isMoving = false;
  int onScreen = true;
  Vector2 mousecenter;
  Vector2 center;
public:

  Ball(int x, int y) {
    radius = BLOCK/4;
    center.x = x * BLOCK;
    center.y = y * BLOCK;
  }

  bool CheckCollision(Vector2 start1, Vector2 end1) {

    start1.y = start1.y + 6;
    end1.y = end1.y + 6;

    start1 = Vector2{BLOCK * start1.x + BLOCK, BLOCK * start1.y + BLOCK};
    end1 =  Vector2{BLOCK * end1.x + BLOCK,BLOCK * end1.y + BLOCK};

    if (CheckCollisionPointLine(Vector2{(center.x), (center.y)}, start1, end1, 1)) {
      return true;
    }
    
    return false;

  }

  void Move() {
    center.y += 0.06 * BLOCK;
  }

  void Draw() {
    DrawCircle(center.x, center.y, radius, BALL);
  }

  void Collide(Vector2 start, Vector2 end) {

    std::cout << isMoving << std::endl;

    if (isMoving && !CheckCollision(start, end)) {
      Move();
    }

    if (IsKeyPressed(KEY_SPACE)) isMoving = !isMoving;

  }
};

#endif //!RIGIDBODY_H 
