#ifndef GUI_H
#define GUI_H

#include "raylib.h"
#include "raymath.h"
#include "settings.h"
#include "graph.h"

#include <cstring>
#include <iostream>
#include <string>

class Button {

private:
  Rectangle box;
  Rectangle boundry;
  bool onMouse = false;
  bool isMoving = false;
  char buttonName[8] = "> Start";

public:
  Button() {
    box.width = BLOCK+20;
    box.height = BLOCK-50; 
    boundry.height = box.height + 5;
    boundry.width = box.width + 5;
  }
  void StopMoving() {
    isMoving = false;
  }
  bool Draw(int x, int y) {
    Color boundryCol = LINES;
    Color boxCol = PLATFORM;

    if (CheckCollisionPointRec(GetMousePosition(), box)) {
      boxCol = BACKGROUND;
      boundryCol = PLATFORM;
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        boxCol = RED;
        isMoving = !isMoving;
      }
    } 
    if (isMoving) strcpy(buttonName, "|| Stop");
    else strcpy(buttonName, "> Start");
    box.x = x * BLOCK;
    box.y = y * BLOCK + 20;
    
    boundry.x = box.x - 2;
    boundry.y = box.y - 2;

    DrawRectangleRec(boundry, boundryCol);
    DrawRectangleRec(box, boxCol);
    DrawText(buttonName, box.x+10, box.y+10, FONT_SIZE/4, boundryCol);
    return isMoving;
  }
};

class Score {
private:
  Vector2 positon;
  int score = 0;
public:
  Score(float x, float y) {
    positon.x = x * BLOCK;
    positon.y = y * BLOCK;
  }
  void IncreseScore(int amount) {
    score = score + amount;
  }
  void DecreseScore(int amount) {
    score = score - amount;
  }
  void Draw() {
    DrawText(TextFormat("Score: %d", score), (int)positon.x, (int)positon.y, FONT_SIZE, LINES);
  }
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

  Vector2 OldOutput() {
    Vector2 vector;
    vector.x = (int)box1->Output() - '0';
    vector.y = (int)box2->Output() - '0';
    return vector;
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
    DrawText("start", (BLOCK+5) * 8, (BLOCK) * 2, LINE_FONT_SIZE, PLATFORM);
    inputbox2->Update(x+3, y);
    DrawText("stop", (BLOCK+5) * 11, (BLOCK) * 2, LINE_FONT_SIZE, PLATFORM);

    //input_taking
    Vector2 start = inputbox1->Output(); 
    Vector2 end = inputbox2->Output();
    Vector2 ustart = inputbox1->OldOutput();
    Vector2 uend = inputbox2->OldOutput();

    
    //drawing_line
    if (ustart.x <=6 && ustart.y <=6 && uend.x <=6 &&  uend.y <= 6 && ustart.x >=0 && ustart.y >=0 && uend.x >=0 && uend.y >=0) line->Draw(start, end);
    else if (ustart.x < 0 || ustart.y < 0 || uend.x < 0 || uend.y < 0) line->Draw(Vector2{0, 0}, Vector2{0, 0}); 
    else DrawText("Out of Range", BLOCK * 2, BLOCK * 0, BLOCK, ERROR);
  } 
};

#endif // !GUI_H
