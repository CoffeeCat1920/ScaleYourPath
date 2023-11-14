#include <iostream>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "../include/settings.h"
#include "../include/graph.h"
#include "../include/gui.h"

using namespace std;

int main () {
  InitWindow(BLOCK * BOARD + BORDER * BLOCK * 2 + BLOCK, BLOCK * BOARD + BORDER * BLOCK, "Scale your Path");

  Grid *grid = new Grid; 
  Line *line = new Line;
  InputBox *box1 = new InputBox(); 
  InputBox *box2 = new InputBox();

  SetTargetFPS(60);
  
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BACKGROUND);
    box1->Draw(8, 2);
    box2->Draw(8, 4);
    line->Draw(0, 0, box1->Output().x, -box1->Output().y);
    grid->DrawGrid();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
