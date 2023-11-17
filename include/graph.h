#ifndef GRAPH_H
#define GRAPH_H

#include "raylib.h"
#include "settings.h"

class Grid {
private:
  char body[2];
public:
  Grid() {
    body[0] = ' ';
    body[1] = '\0';
  }
  void DrawGrid() { 
    for (float i = 0; i<=BOARD; i++) {
      DrawLineEx(Vector2{0 + BLOCK, BLOCK * i + BLOCK}, Vector2{BLOCK * BOARD + BLOCK, BLOCK * i + BLOCK}, 1, LINES); 
      DrawLineEx(Vector2{BLOCK * i + BLOCK, 0 + BLOCK}, Vector2{BLOCK * i + BLOCK, BLOCK * BOARD + BLOCK}, 1, LINES); 
    }
    for (float i = BOARD; i>=0; i--) {
      body[0] = i + '0';
      if (i!=0) DrawText(body, BLOCK-30, (BLOCK - 1) * (7-i), LINE_FONT_SIZE, BLACK);
    } 
    for (float i = 0; i<=BOARD; i++) {
      body[0] = i + '0';
      DrawText(body, (BLOCK+5) * (i+0.7), BLOCK * 7, LINE_FONT_SIZE, BLACK);
    } 
  }
};
class Line {
  public:
  void Graph(Vector2 start, Vector2 end) {
    DrawLineEx(start, end, 5, PLATFORM);    
  }
  void Draw(float start1, float start2, float end1, float end2) {
    start2 = start2 + 6;
    end2 = end2 + 6;
    Graph(Vector2{BLOCK * start1 + BLOCK, BLOCK * start2 + BLOCK}, Vector2{BLOCK * end1 + BLOCK,BLOCK * end2 + BLOCK});
  }
};

#endif //GRAPH_H!
