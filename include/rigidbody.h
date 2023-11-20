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
  Vector2 mousePosition;
  Vector2 position;
public:

  Ball(int x, int y) {
    position.x = x;
    position.y = y;
    radius = BLOCK/4;
  }

  bool Collision(Vector2 start, Vector2 end) {

    start.y = start.y + 6;
    end.y = end.y + 6;

    start = Vector2{BLOCK * start.x + BLOCK, BLOCK * start.y + BLOCK};
    end =  Vector2{BLOCK * end.x + BLOCK,BLOCK * end.y + BLOCK};
    
    return true;

  }

  void Move() {
    position.y += 0.06;
  }

  void Draw(Vector2 start, Vector2 end) {

    DrawCircle(BLOCK * position.x, BLOCK * position.y, radius, BALL);

    if (isMoving) {
      Move();
    }

    if (IsKeyPressed(KEY_SPACE)) isMoving = !isMoving;

  }
};

#endif //!RIGIDBODY_H 
