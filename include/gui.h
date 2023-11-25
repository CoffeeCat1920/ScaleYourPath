#ifndef GUI_H
#define GUI_H

#include "raylib.h"
#include "raymath.h"
#include "settings.h"
#include "graph.h"
#include <vector>

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
    Vector2 vector;
    vector.x = BLOCK * ((int)box1->Output() - '0') + BLOCK;
    vector.y = BLOCK * (6-((int)box2->Output() - '0')) + BLOCK;
    return vector;
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
    
    //box:
    inputbox1->Update(x, y);
    DrawText("start", (BLOCK+5) * 8, (BLOCK) * 0.5, LINE_FONT_SIZE, PLATFORM);
    inputbox2->Update(x+3, y);
    DrawText("stop", (BLOCK+5) * 11, (BLOCK) * 0.5, LINE_FONT_SIZE, PLATFORM);

    //input_taking
    Vector2 start = inputbox1->Output(); 
    Vector2 end = inputbox2->Output();

    //drawing_line
    if (start.x <=6 && start.y <=6 && end.x <=6 &&  end.y <= 6 && start.x >=0 && start.y >=0 && end.x >=0 && end.y >=0) line->Draw(start, end);
    else if (start.x < 0 || start.y < 0 || end.x < 0 || end.y < 0) line->Draw(Vector2{0, 0}, Vector2{0, 0}); 
    else DrawText("Out of Range", BLOCK * 2, BLOCK * 0, BLOCK, ERROR);

  } 
};

#endif // !GUI_H
