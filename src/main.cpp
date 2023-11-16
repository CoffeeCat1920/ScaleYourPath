#include "../include/raylib.h"

#include "../include/settings.h"
#include "../include/graph.h"
#include "../include/gui.h"

class Game {
private:
  Grid *grid = new Grid; 
  Line *line = new Line;
  InputBox *inputbox1 = new InputBox(); 
  InputBox *inputbox2 = new InputBox();
public:
  void Update() {
    inputbox1->Update(10, 1);
    inputbox2->Update(10, 2);
    float x1 = inputbox1->Output().x - '0';
    float y1 = inputbox1->Output().y - '0';
    float x2 = inputbox2->Output().x - '0'; 
    float y2 = inputbox2->Output().y - '0';
    line->Draw(x1, -y1, x2, -y2);
    grid->DrawGrid();
  }
};

int main () {
  InitWindow(BLOCK * BOARD + BORDER * BLOCK * 2 + BLOCK * 3, BLOCK * BOARD + BORDER * BLOCK, "Scale your Path");
  Game *game = new Game();
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BACKGROUND);
    game->Update();
    EndDrawing();
  }
  delete game;
  CloseWindow();
  return 0;
}
