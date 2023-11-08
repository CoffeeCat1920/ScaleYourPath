#include <iostream>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "../include/settings.h"
#include "../include/graph.h"
#include "../include/gui.h"

using namespace std;

void Gameloop() {
  ClearBackground(BACKGROUND);
  Grid *graph = new Grid; 
  Line *line = new Line;
  graph->DrawGrid();
  line->Draw(0, 0, 4, -2);
}

int main () {
  InitWindow(BLOCK * BOARD + BORDER * BLOCK, BLOCK * BOARD + BORDER * BLOCK, "Scale your Path");
  SetTargetFPS(60);
  
  while (!WindowShouldClose()) {
    BeginDrawing();
      Gameloop();
    EndDrawing();
  }
  
  CloseWindow();

  return 0;
}
