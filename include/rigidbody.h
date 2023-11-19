#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <iostream>

#include "raylib.h"
#include "settings.h"

class Ball {
private:
  bool isMouse = false;
  Vector2 mousePosition;
  int onScreen = true;
  Vector2 position;
public:
  Ball(int x, int y) {
    position.x = x;
    position.y = y;
  }
  void Move() {
    position.y += 0.06;
  }
  void Draw(Vector2 p1, Vector2 p2) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) isMouse = true;
    DrawCircle(BLOCK * position.x, BLOCK * position.y, BLOCK/4, BALL);
    if (!(CheckCollisionPointLine(position, p1, p2, 1)) && isMouse) {
      Move();
      std::cout << p1.x << ", " << p1.y << " " << p2.x << ", " << p2.y << std::endl;
    }
  }
};

#endif //!RIGIDBODY_H 
