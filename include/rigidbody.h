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
    center.x = x * BLOCK;
    center.y = y * BLOCK;
    radius = BLOCK/4;
  }

  bool Collision(Vector2 start, Vector2 end) {

    start.y = start.y + 6;
    end.y = end.y + 6;

    start = Vector2{BLOCK * start.x + BLOCK, BLOCK * start.y + BLOCK};
    end =  Vector2{BLOCK * end.x + BLOCK,BLOCK * end.y + BLOCK};

    if (CheckCollisionPointLine(Vector2{center.x+radius, center.y}, start, end, 1)) return true;
    if (CheckCollisionPointLine(Vector2{center.x-radius, center.y}, start, end, 1)) return true;
    if (CheckCollisionPointLine(Vector2{center.x, center.y+radius}, start, end, 1)) return true;
    if (CheckCollisionPointLine(Vector2{center.x, center.y-radius}, start, end, 1)) return true;

    return false;

  }

  void Move() {
    center.y += 0.06 * BLOCK;
  }

  void Draw(Vector2 start, Vector2 end) {

    DrawCircle(center.x, center.y, radius, BALL);

    if (isMoving && !Collision(start, end)) {
      Move();
    }

    if (IsKeyPressed(KEY_SPACE)) isMoving = !isMoving;

  }
};

#endif //!RIGIDBODY_H 
