#include "../include/raylib.h"

#include "../include/rigidbody.h"
#include "../include/settings.h"
#include "../include/graph.h"
#include "../include/gui.h"
#include <iostream>

class Game {
private:
  Grid *grid = new Grid(); 
  Line *line = new Line();
  Ball *ball = new Ball(4, 1);
  InputBox *inputbox1 = new InputBox(); 
  InputBox *inputbox2 = new InputBox();
public:
  ~Game() {
    delete grid;
    delete line;
    delete inputbox1;
    delete inputbox2;
    delete ball;
  }
  void Update() {

    //box
    inputbox1->Update(8, 1);
    DrawText("start", (BLOCK+5) * 8, (BLOCK) * 0.5, LINE_FONT_SIZE, PLATFORM);
    inputbox2->Update(11, 1);
    DrawText("stop", (BLOCK+5) * 11, (BLOCK) * 0.5, LINE_FONT_SIZE, PLATFORM);

    //input_taking
    float x1 = inputbox1->Output().x - '0';
    float y1 = inputbox1->Output().y - '0';
    float x2 = inputbox2->Output().x - '0'; 
    float y2 = inputbox2->Output().y - '0';

    //drawing_line
    if (x1 <=6 && x2 <=6 && y1 <=6 && y2 <= 6 && x1 >=0 && x2 >=0 && y1 >=0 && y2 >=0) line->Draw(x1, -y1, x2, -y2);
    else if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) line->Draw(0, 0, 0, 0); 
    else DrawText("Out of Range", BLOCK * 2, BLOCK * 0, BLOCK, ERROR);

    //draw_grid
    grid->DrawGrid();

    //drawing_ball
    ball->Draw(Vector2 {BLOCK * x1 + BLOCK, BLOCK * (y1+6) + BLOCK}, Vector2{BLOCK * x2 + BLOCK, BLOCK * (y2+6) + BLOCK});
  }
};

int main () {
  InitWindow(BLOCK * BOARD + BORDER * BLOCK * 4, BLOCK * BOARD + BORDER * BLOCK, "Scale your Path");
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
