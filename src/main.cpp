#include "../include/raylib.h"

#include "../include/rigidbody.h"
#include "../include/settings.h"
#include "../include/graph.h"
#include "../include/gui.h"

#include <iostream>

class Game {
private:
  Grid *grid = new Grid(); 
  Ball *ball = new Ball(4, 1);
  Button *startButton = new Button;
  VectorBox *line1 = new VectorBox(8, 1); 
  VectorBox *line2 = new VectorBox(8, 3); 
  VectorBox *line3 = new VectorBox(8, 5);
  Score *score = new Score(8, 6);
public:
  ~Game() {
    delete grid;
    delete line1;
    delete ball;
  }
  void Update() {

    //draw_grid
    grid->Draw();

    //draw_line
    line1->Draw();
    line2->Draw();
    line3->Draw();

    //ui
    startButton->Draw(1, 0);
    score->Draw();

    //ball
    ball->Draw();
    ball->Collide(line1->inputbox1->Output(), line1->inputbox2->Output(), line2->inputbox1->Output(), line2->inputbox2->Output(), line3->inputbox1->Output(), line3->inputbox2->Output());
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
