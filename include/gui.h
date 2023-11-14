#include "raylib.h"
#include "settings.h"

struct Vec {
  int x;
  int y;
};

class Box {
private:
  Rectangle textBox;
  bool onMouse = false;
  int letterCount = 0;
  char digit[2];
public:
  Box() {
    textBox.width = BLOCK;
    textBox.height = BLOCK;
    digit[1] = '\0';
  }
  void Draw(int x, int y) {
    textBox.x = x * BLOCK;
    textBox.y = y * BLOCK;
    if (CheckCollisionPointRec(GetMousePosition(), textBox)) onMouse = true;
    else onMouse = false;
    if (onMouse) {
      char key = GetCharPressed();
      while (key > 0) {
        if ((key>=32) && (key<=125) && letterCount<1) {
          digit[0] = key;
          letterCount++;
        }  
        key = GetCharPressed();
      }
      if (IsKeyPressed(KEY_BACKSPACE)) {
        digit[0] = 0;
        letterCount = 0;
      }
    }
    DrawRectangleRec(textBox, LINES);
    DrawText(digit, textBox.x + 20, textBox.y, BLOCK, BLACK);
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
  void Draw(int x, int y) {
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
