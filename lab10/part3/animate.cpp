// Maria Beatriz Zanardo
// Lab 10, Part3

#include <unistd.h>
#include <cmath>
#include "gfx.h"

#define PI 3.14159265 

int main () {
  int win_wd = 700, win_ht = 600;
  float xc = 350;
  float yc = 300;
  int radius = 200;
  char c = ' ';
  int x1, x2, y1, y2, x3, x4, y3, y4, x5, x6, y5, y6;
  double theta = 0;

  gfx_open (win_wd, win_ht, "Animate");
  gfx_clear_color(172, 232, 247);
  gfx_clear(); 

  while (c != 'q') {
    gfx_flush();
    gfx_clear();
    gfx_color(255,0,0);   
    gfx_circle(xc, yc, radius);
    gfx_line(0,500, 700, 500);

    x1 = xc - cos(theta)*radius;
    x2 = xc + cos(theta)*radius;
    y1 = yc - sin(theta)*radius;
    y2 = yc + sin(theta)*radius;
 
    x3 = xc - cos(theta + (PI/3))*radius;
    x4 = xc + cos(theta + (PI/3))*radius;
    y3 = yc - sin(theta + (PI/3))*radius;
    y4 = yc + sin(theta + (PI/3))*radius;

    x5 = xc - cos(theta + (2*PI/3))*radius;
    x6 = xc + cos(theta + (2*PI/3))*radius;
    y5 = yc - sin(theta + (2*PI/3))*radius;
    y6 = yc + sin(theta + (2*PI/3))*radius;

    gfx_line(x1,y1,x2,y2);
    gfx_line(x3,y3,x4,y4);
    gfx_line(x5,y5,x6,y6);
    gfx_flush();
    theta = theta + (PI/6);
    usleep(300000);

    if(gfx_event_waiting()) {
      c = gfx_wait();
      while (!gfx_event_waiting()) {
        gfx_flush();
        gfx_clear();
        gfx_circle(xc, yc, radius);
        gfx_line(0,500, 700, 500);

        int x1 = xc - cos(theta)*radius;
        int x2 = xc + cos(theta)*radius;
        int y1 = yc - sin(theta)*radius;
        int y2 = yc + sin(theta)*radius;
 
        int x3 = xc - cos(theta + (PI/3))*radius;
        int x4 = xc + cos(theta + (PI/3))*radius;
        int y3 = yc - sin(theta + (PI/3))*radius;
        int y4 = yc + sin(theta + (PI/3))*radius;

        int x5 = xc - cos(theta + (2*PI/3))*radius;
        int x6 = xc + cos(theta + (2*PI/3))*radius;
        int y5 = yc - sin(theta + (2*PI/3))*radius;
        int y6 = yc + sin(theta + (2*PI/3))*radius;

        gfx_line(x1,y1,x2,y2);
        gfx_line(x3,y3,x4,y4);
        gfx_line(x5,y5,x6,y6);

        theta = theta - (PI/6);
        usleep(300000);
        if (c == 'q') {
          break;
        }
      }
    }
  }
return 0;
}
