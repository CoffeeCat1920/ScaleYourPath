#include "raylib.h"
#include "settings.h"

class TextBox {
  public:
  int x, y;
  char key;
  TextBox(){
    x=0;
    y=0;
  } 
  TextBox(int x, int y) {
    key = '_';
    this->x = x;
    this->y = y;
  }
  bool OnMouse(Rectangle rec) {
    if (CheckCollisionPointRec(GetMousePosition(), rec)) return true;
    else return false;
  }
  void Draw() {
    Rectangle rec = {BLOCK * (float)x, BLOCK * (float)y, BLOCK, BLOCK}; 
    DrawRectangleRec(rec, RAYWHITE);
    if (OnMouse(rec)) {
      if (GetCharPressed()!=0) {
        key = GetCharPressed();
      }
      else {
        key = '_';
      }
      text(key);
    }
  }
  void text(char key) {
    char keystr[2] = {(char)key, '\0'};
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
