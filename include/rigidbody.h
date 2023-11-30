#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "raylib.h"
#include "raymath.h"
#include "settings.h"
#include <cmath>

class Ball {
private:
  int radius;
  int bost;
  double speed;
  bool isMoving = false;
  bool onScreen = true;
  Vector2 mousecenter;
  Vector2 center;
  Vector2 orintation;
public:

  Ball(int x, int y) {
    bost = 1;
    radius = BLOCK/4;
    speed = 0.02;
    center.x = x * BLOCK;
    center.y = y * BLOCK;
    orintation = Vector2{0, 1};
  }

  bool CheckCollision(Vector2 start1, Vector2 end1, Vector2 start2, Vector2 end2, Vector2 start3, Vector2 end3) {
    return false;
  }

  void Move() {
    center.x += speed * orintation.x * BLOCK;
    center.y += speed * orintation.y * BLOCK;
  }

  void Draw() {
    DrawCircle(center.x, center.y, radius, BALL);
  }

  void Collide(Vector2 start1 = ZERO, Vector2 end1 = ZERO, Vector2 start2 = ZERO, Vector2 end2 = ZERO, Vector2 start3 = ZERO, Vector2 end3 = ZERO) {

    if (isMoving && !CheckCollision(start1, end1, start2, end2, start3, end3)) {
      Move();
    }
    if (IsKeyPressed(KEY_SPACE)) isMoving = !isMoving;

  }
};

#endif //!RIGIDBODY_H 
