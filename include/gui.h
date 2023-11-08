#include "raygui.h"
#include "raylib.h"

class InputBox{
  public:
  void Draw() {
    char Text[4] = {'T', 'E', 'X', 'T'}; 
    Rectangle bound = Rectangle{0, 0, (float)100, (float)100};
    GuiTextBox(bound, Text, 12, true);                
  }
};
