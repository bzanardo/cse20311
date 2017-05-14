// Maria Beatriz Zanardo
// Final Project

#include "paddle.h"
#include "gfxnew.h"

Paddle::Paddle()
{
  x = 50;
  y2 = 250;
  y1 = 350;
}

Paddle::~Paddle() {}

void Paddle::setPaddle (int x2, int y3, int y4)
{
  x = x2;
  y1 = y3;
  y2 = y4;
} 

void Paddle::display() {
  gfx_line(x, y1, x, y2);
}

void Paddle::move (double v)
{
  y2 = y2 - v;
  y1 = y1 - v;
 
}

int Paddle::getx()
{
  return (x);
}

int Paddle::gety1()
{
  return (y1);
}

int Paddle::gety2()
{
  return (y2);
}
