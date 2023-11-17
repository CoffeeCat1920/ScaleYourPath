#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "raylib.h"
#include "settings.h"

class Ball {
private:
  int x;
  int y;
public:
  Ball() {
    x = 0;
    y = 0;
  }
  void Spawn() {
    DrawCircle(BLOCK * x, BLOCK * y, (float)BLOCK, PLATFORM);
  }
};

#endif //!RIGIDBODY_H 
