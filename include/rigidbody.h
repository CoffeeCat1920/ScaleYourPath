#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "raylib.h"
#include "raymath.h"
#include "settings.h"

#include <cmath>
#include <iostream>

class Ball {
private:
  int radius;
  int bost;
  double speed;
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
    center.y = (y * (BLOCK));
    orintation = Vector2{0, 1};
  }
 
  void SetPosition(float x, float y) {
    center.x = x*BLOCK;
    center.y = y*BLOCK;
  }

  Vector2 Direction(Vector2 start, Vector2 end) {

    float a = end.y - start.y;
    float b = start.x - end.x;
    float c = end.x * start.y - start.x * end.y;

    if (start.y == end.y) {
      return Vector2{0, -1};
    }else if (start.x == end.x) {
      return Vector2{-1, 0};
    } 
    else {
      //direction of prependicular line
      Vector2 lineVector = Vector2{end.x - start.x, end.y - start.y};
      Vector2 prependicularLine = Vector2{lineVector.y, -lineVector.x};
      float scalerPrependicularLine = sqrt(pow(prependicularLine.x, 2) + sqrt(pow(prependicularLine.y, 2)));
      Vector2 unitPrependicularLine = Vector2{prependicularLine.x/scalerPrependicularLine, prependicularLine.y/scalerPrependicularLine};
      bool direction;
      
      //relative position
      float relativePosition = (center.x - start.x) * (end.y - start.y) - (center.y - start.y) * (end.x - start.x);
      
      //check direction
      if (relativePosition > 0) direction = true;
      else direction = false;

      if ((relativePosition > 0 && direction == 1)) {
        return unitPrependicularLine;
      } 
      else if ((relativePosition < 0 && direction == 0)){
        return Vector2{-unitPrependicularLine.x, -unitPrependicularLine.y}; 
      }

    }
    return ZERO;
  }

  float Distance(Vector2 start, Vector2 end) {

    Vector2 direction = Vector2Subtract(end, start);
    float t = Vector2DotProduct(Vector2Subtract(center, start), direction) / Vector2LengthSqr(direction);
    Vector2 projection = Vector2Add(start, Vector2Scale(direction, t));
    float distance = Vector2Length(Vector2Subtract(center, projection));

    return distance;
  }

  bool CheckCollision(Vector2 start1, Vector2 end1, Vector2 start2, Vector2 end2, Vector2 start3, Vector2 end3) {
    float distance1 = Distance(start1, end1);
    float distance2 = Distance(start2, end2);
    float distance3 = Distance(start3, end3);
    if (distance1<=radius) orintation = Direction(start1, end1);
    if (distance2<=radius) orintation = Direction(start2, end2);
    if (distance3<=radius) orintation = Direction(start3, end3);
    return false;
  }

  void Move() {
    center.x += speed * orintation.x * BLOCK;
    center.y += speed * orintation.y * BLOCK;
  }

  void Draw() {
    DrawCircle(center.x, center.y, radius, BALL);
  }

  Vector2 Position() {
    return center;
  }

  void Collide(Vector2 start1 = ZERO, Vector2 end1 = ZERO, Vector2 start2 = ZERO, Vector2 end2 = ZERO, Vector2 start3 = ZERO, Vector2 end3 = ZERO, bool isMoving = false) {

    if (isMoving && !CheckCollision(start1, end1, start2, end2, start3, end3)) {
      Move();
    } 
  }
  
  Vector2 ReturnPosition() {
    return center;
  }

};

#endif //!RIGIDBODY_H 
