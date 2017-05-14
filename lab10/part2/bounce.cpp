// Maria Beatriz Zanardo
// Lab 10, Part 2
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include "gfx.h"

int main() {
  int win_wd = 600, win_ht = 500;  
  float xc = 100, yc = 100;        
  int rad = 20;                    
  float vx = 10, vy = 10;            
  float dt = 1;               
  char c = ' ';

  gfx_open (win_wd, win_ht, "Moving Ball");

  while(c != 'q') {
    gfx_clear();
    gfx_color(255,255,255);

    gfx_circle(xc, yc, rad);
    gfx_flush();
    xc = xc + vx*dt;
    yc = yc + vy*dt;

    if (xc == win_wd-rad) {  //right wall
      xc++;
      yc++;
    } 
    if ((xc >= win_wd-rad) && (yc >= win_ht-rad)) { //right bottom corner
      xc= xc + 5;
    }
    if(xc >= win_wd-rad)       // right wall
       vx = -vx;
    else if(xc <= rad)         // left wall
       vx = -vx;
    else if(yc >= win_ht-rad)  // bottom wall
       vy = -vy;
    else if(yc <= rad)         // top wall
       vy = -vy;

    gfx_flush();
    usleep(1000);
    if(gfx_event_waiting()) {
      c = gfx_wait();
      xc = gfx_xpos();
      yc = gfx_ypos();
      srand(time(NULL));
      vx = rand() % 20 - 10;
      vy = rand() % 20 - 10;
    }
  }

  return 0;
}

