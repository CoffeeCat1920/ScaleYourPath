#include "../include/raylib.h"

#include "../include/rigidbody.h"
#include "../include/settings.h"
#include "../include/graph.h"
#include "../include/gui.h"
#include "../include/point.h"

#include <iostream>


class Game {
private:
  Grid *grid = new Grid(); 
  Ball *ball = new Ball(4, 1);
  Button *startButton = new Button;
  VectorBox *line1 = new VectorBox(8, 3); 
  VectorBox *line2 = new VectorBox(8, 3); 
  VectorBox *line3 = new VectorBox(8, 5);
  Score *score = new Score(8.5, 5);
  Point *point = new Point();
public:
  ~Game() {
    delete grid;
    delete line1;
    delete ball;
    delete score;
    delete point;
  }
  void Update() {

    //draw_grid
    grid->Draw();

    //draw_line
    line1->Draw();
    
    //ui
    bool isMoving = startButton->Draw(10, 1);
    score->Draw();

    ball->Lowest();

     //point
    if (point->Draw(ball->ReturnPosition())) {
      score->IncreseScore(5+(ball->Lowest()/BLOCK));
      startButton->StopMoving();
      ball->SetPosition(4, 1);
    }
    if (ball->Position().y < 0 || ball->Position().x < 0) {
      score->DecreseScore(5+(ball->Lowest()/BLOCK));
      startButton->StopMoving();
      ball->SetPosition(4, 1);
    }

    //ball
    ball->Draw();
    ball->Collide(line1->inputbox1->Output(), line1->inputbox2->Output(), line2->inputbox1->Output(), line2->inputbox2->Output(), line3->inputbox1->Output(), line3->inputbox2->Output(), isMoving);
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
