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
      body[0] = (char)64;
      DrawText(body, BLOCK, BLOCK, BLOCK, BLACK);
      DrawLineEx(Vector2{BLOCK * i + BLOCK, 0 + BLOCK}, Vector2{BLOCK * i + BLOCK, BLOCK * BOARD + BLOCK}, 1, LINES); 
    }
  }
};
class Line {
  public:
  void Graph(Vector2 start, Vector2 end) {
    DrawLineEx(start, end, 2, PLATFORM);    
  }
  void Draw(float start1, float start2, float end1, float end2) {
    start2 = start2 + 6;
    end2 = end2 + 6;
    Graph(Vector2{BLOCK * start1 + BLOCK, BLOCK * start2 + BLOCK}, Vector2{BLOCK * end1 + BLOCK,BLOCK * end2 + BLOCK});
  }
};
#endif
