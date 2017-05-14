// Maria Beatriz Zanardo
// Final Project

#include <string>
#include <unistd.h>
#include "gfxnew.h"
#include "paddle.h"

using namespace std;

int main() {
  float w = 900;
  float h = 600;
  float xc = 100, yc = 100;      
  int r = 10;                  
  float vx = 1, vy = 1;           
  float dt = 3;                 
  char c = ' ';
  char font1[] = "12x24";

  Paddle a, b;
  b.setPaddle (850, 350, 250);
  int xa, y1a, y2a, xb, y1b, y2b;
  int iscoreA = 0;
  int iscoreB = 0;
  const char* scoreA = "0";
  const char* scoreB = "0";
  string strA;
  string strB;

  gfx_open ( w, h, "Pong");
  gfx_changefont(font1);

  while (true) {
    gfx_color(255, 255, 255);
    gfx_text (430, 100, "Pong!");
    gfx_text (100, 200, "Instructions: player 1 moves left paddle with w & s keys.");
    gfx_text (200, 300, "player 2 moves right paddle with u & j keys.");
    gfx_text (320, 400, "Press enter to begin.");
    c = gfx_wait();
    if (c == 13) {
      break;
    }
  }
  
  while(true) {
    gfx_clear();
    a.display();
    b.display();
    gfx_fill_circle( xc, yc, r);
    gfx_flush();
    xc = xc + vx*dt;
    yc = yc + vy*dt;

    xa = a.getx();
    y1a = a.gety1();  
    y2a = a.gety2();

    xb = b.getx();
    y1b = b.gety1();  
    y2b = b.gety2();

    gfx_text (420, 50, "Score:"); 
    gfx_text (100, 50, scoreA); 
    gfx_text (700, 50, scoreB); 

    if( (xc <= xa + r) && (yc <= y1a) && (yc >= y2a) ) {  // left paddle     
      vx = -vx;
    }
    if( (xc >= xb - r) && (yc <= y1b) && (yc >= y2b) ) { // right paddle
      vx = -vx;
    }
    if(yc >= h - r)  // bottom wall
       vy = -vy;
    if(yc <= r)         // top wall
       vy = -vy;


    if (xc < -3*r) {  //into left wall
      iscoreB++;
      strB = to_string(iscoreB);
      scoreB = strB.c_str();
      gfx_text (350, 200, "Player 2 scored!");
      gfx_text (300, 250, "Press any key to continue.");
      c = gfx_wait();
      gfx_fill_circle( xc, yc, r);
      gfx_flush();
      vx = 1;
      vy = 1;
      xc = 400;
      yc = 400;
      xc = xc + vx*dt;
      yc = yc + vy*dt;
    }
    if (xc > w+r) {  //into right wall
      iscoreA++;
      strA = to_string(iscoreA);
      scoreA = strA.c_str();
      gfx_text (350, 200, "Player 1 scored!"); 
      gfx_text (300, 250, "Press any key to continue."); 
      c = gfx_wait();
      gfx_fill_circle( xc, yc, r);
      gfx_flush();
      vx = -1;
      vy = 1;
      xc = 400;
      yc = 400; 
      xc = xc + vx*dt;
      yc = yc + vy*dt;
    }

    gfx_flush();
    usleep(10000);
    if(gfx_event_waiting() != 0) {
      c = gfx_wait();
    }
    if (c == 'w') {
      a.move(30);
      a.display();
      gfx_flush();
      gfx_clear();
      c = ' ';
    }

    if (c == 's') {
      a.move(-30);
      a.display();
      gfx_flush();
      gfx_clear();
      c = ' ';
    }
    if (c == 'u') {
      b.move(30);
      b.display();
      gfx_flush();
      gfx_clear();
      c = ' ';
     }

    if (c == 'j') {
      b.move(-30);
      b.display();
      gfx_flush();
      gfx_clear();
      c = ' ';
    }
    if (c == 'q') {
      break;
    }
  }

  return 0;
}

