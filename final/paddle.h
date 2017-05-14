// Maria Beatriz Zanardo
// Final Project

#include "gfxnew.h"

class Paddle {
  public:
    Paddle();
   ~Paddle();
    void setPaddle (int, int, int);
    void display();
    void move (double);
    int getx();
    int gety1();
    int gety2();
  private:
    int x;
    int y1;
    int y2;
};
