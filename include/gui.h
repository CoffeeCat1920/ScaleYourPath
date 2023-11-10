#include <iostream>
#include <string>

#include "raylib.h"
#include "settings.h"

class TextBox {
  public:
  int x, y;
  TextBox(){
    x=0;
    y=0;
  } 
  TextBox(int x, int y) {
    this->x = x;
    this->y = y;
  }
  bool OnMouse(Rectangle rec) {
    if (CheckCollisionPointRec(GetMousePosition(), rec)) return true;
    else return false;
  }
  int key=GetCharPressed();
  char keystr[2] = {(char)key, '\0'};
  void Draw() {
    Rectangle rec = {BLOCK * (float)x, BLOCK * (float)y, BLOCK, BLOCK}; 
    DrawRectangleRec(rec, RAYWHITE);
    DrawText(keystr, BLOCK * (float)x, BLOCK * (float)y, BLOCK, BLACK);
  }
};

class InputBox {
  public:
  int x, y;
  InputBox(int x, int y) {
    this->x = x;
    this->y = y;
  }
  void Draw() {
    for (int i = 1; i<=2; i++) {
      TextBox *box = new TextBox(x+i, y); 
      box->Draw();
    }
  }
};
