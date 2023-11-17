#ifndef GUI_H
#define GUI_H

#include "raylib.h"
#include "settings.h"

struct Vec {
  int x;
  int y;
};

class Box {
private:
  Rectangle boundry;
  Rectangle box;
  bool onMouse = true;
  bool emptyBox = true;
  int letterCount = 0;
  char digit[2];
  Color boxCol;
public:
  Box() {
    boundry.width = FONT_SIZE + 2;
    boundry.height = FONT_SIZE + 2;
    box.width = boundry.width - 5;
    box.height = boundry.height - 5;
    digit[0] = 0;
    digit[1] = '\0';
  }
  void Draw(int x, int y) {
    boundry.x = x * BLOCK;
    boundry.y = y * BLOCK;
    box.x = boundry.x + 2.5;
    box.y = boundry.y + 2.5;
    if (CheckCollisionPointRec(GetMousePosition(), boundry)) onMouse = true;
    else onMouse = false;
    if (onMouse) {
      boxCol = PLATFORM;
      char key = GetCharPressed();
      while (key > 0) {
        if ((key>=32) && (key<=125) && letterCount<1) {
          digit[0] = key;
          letterCount++;
          emptyBox = false;
        }  
        key = GetCharPressed();
      }
      if (IsKeyPressed(KEY_BACKSPACE)) {
        digit[0] = 0;
        letterCount = 0;
        emptyBox = true;
      }
    }
    else {
      boxCol = LINES;
    }
    DrawRectangleRec(boundry, boxCol);
    DrawRectangleRec(box, BACKGROUND);
    DrawText(digit, boundry.x + 20, boundry.y, FONT_SIZE, boxCol);
    if (emptyBox && onMouse) DrawText("_", boundry.x + 20, boundry.y, FONT_SIZE, boxCol);
  }
  char Output() {
    return digit[0];
  }
};

class InputBox {
private:
  Box *box1 = new Box();
  Box *box2 = new Box();
public:
  ~ InputBox() {
    delete  box1;
    delete  box2;
  }
  void Update(int x, int y) {
    box1->Draw(x, y);
    box2->Draw(x+1, y);
  }
  Vec Output() {
    Vec vec;
    vec.x = (int)box1->Output();
    vec.y = (int)box2->Output();
    return vec;
  } 
};

#endif // !GUI_H
