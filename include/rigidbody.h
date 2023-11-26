#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <iostream>

#include "raylib.h"
#include "raymath.h"
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

  bool CheckCollision(Vector2 start, Vector2 end) {
    
    Vector2 direction = Vector2Subtract(end, start);
    float t = Vector2DotProduct(Vector2Subtract(center, start), direction) / Vector2LengthSqr(direction);
    Vector2 projection = Vector2Add(start, Vector2Scale(direction, t));
    float distance = Vector2Length(Vector2Subtract(center, projection));

    if (distance < radius) {
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

    if (isMoving && !CheckCollision(start, end)) {
      Move();
    }

    if (IsKeyPressed(KEY_SPACE)) isMoving = !isMoving;

  }
};

#endif //!RIGIDBODY_H 
