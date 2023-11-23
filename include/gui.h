#ifndef GUI_H
#define GUI_H

#include "raylib.h"
#include "settings.h"
#include "graph.h"

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
  Line *line = new Line;
public:
  ~ InputBox() {
    delete  box1;
    delete  box2;
  }
  void Update(int x, int y) {
    box1->Draw(x, y);
    box2->Draw(x+1, y);
  }

  Vector2 Output() {
    Vector2 vec;
    vec.y = ((int)box2->Output()) - '0';
    vec.x = ((int)box1->Output()) - '0';
    return vec;
  } 

};

class VectorBox {
private:
  Line *line = new Line();
  int x;
  int y;
public:
  InputBox *inputbox1 = new InputBox(); 
  InputBox *inputbox2 = new InputBox();
  VectorBox(int x, int y) {
    this->x = x;
    this->y = y;
  }
  void Draw() {
    
    //box1:
    inputbox1->Update(x, y);
    DrawText("start", (BLOCK+5) * 8, (BLOCK) * 0.5, LINE_FONT_SIZE, PLATFORM);
    inputbox2->Update(x+3, y);
    DrawText("stop", (BLOCK+5) * 11, (BLOCK) * 0.5, LINE_FONT_SIZE, PLATFORM);

    //input_taking
    float x1 = inputbox1->Output().x;
    float y1 = inputbox1->Output().y;
    float x2 = inputbox2->Output().x; 
    float y2 = inputbox2->Output().y;

    //drawing_line
    if (x1 <=6 && x2 <=6 && y1 <=6 && y2 <= 6 && x1 >=0 && x2 >=0 && y1 >=0 && y2 >=0) line->Draw(Vector2{x1, -y1}, Vector2{x2, -y2});
    else if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) line->Draw(Vector2{0, 0}, Vector2{0, 0}); 
    else DrawText("Out of Range", BLOCK * 2, BLOCK * 0, BLOCK, ERROR);

  } 
};

#endif // !GUI_H
