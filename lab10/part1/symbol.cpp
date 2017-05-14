// Maria Beatriz Zanardo
// Lab 10 Part 1

#include "gfx.h"

int main()
{
  const int xsize = 700, ysize = 500;
  char c;
  int x,y;

  gfx_open(xsize, ysize, "Symbolic Typewriter");
  
    while(true) {
      c = gfx_wait();
      x = gfx_xpos();
      y = gfx_ypos();

      if (c == 't') {
        gfx_color(0,200,100);
        gfx_line(x,y+25, x+22, y-12);
        gfx_line(x+22,y-12,x-22,y-12);
        gfx_line(x-22,y-12,x,y+25);
      }
      if (c == 'c') {
        gfx_color(255,255,255);
        gfx_circle(x,y,25);
      }  

      if (c == 1) {
        gfx_color(0,50,200);
        gfx_line(x+20,y+20, x-20, y+20);
        gfx_line(x-20,y+20,x-20,y-20);
        gfx_line(x-20,y-20,x+20,y-20);
        gfx_line(x+20,y-20,x+20,y+20);
      }

      if ( (c >= 51) && (c <= 57) ) {
        gfx_color(133,25,188);
        if (c == 51) {    
          gfx_line(x,y+25, x+22, y-12);
          gfx_line(x+22,y-12,x-22,y-12);
          gfx_line(x-22,y-12,x,y+25);
        }
        if (c == 52) {
          gfx_line(x+20,y+20, x-20, y+20);
          gfx_line(x-20,y+20,x-20,y-20);
          gfx_line(x-20,y-20,x+20,y-20);
          gfx_line(x+20,y-20,x+20,y+20);
        }
        if (c == 53) {
          gfx_line(x,y+25, x+24, y+8);
          gfx_line(x+24,y+8, x+15, y-20);
          gfx_line(x+15,y-20, x-15, y-20);
          gfx_line(x-15,y-20, x-24, y+8);
          gfx_line(x-24,y+8, x, y+25);
        }
        if (c == 54) {
          gfx_line(x-12,y+22, x+13, y+22);
          gfx_line(x+13,y+22, x+25, y);
          gfx_line(x+25,y, x+12, y-22);
          gfx_line(x+12,y-22, x-12, y-22);
          gfx_line(x-12,y-22, x-25, y);
          gfx_line(x-25,y, x-12, y+22);
        }
        if (c == 55) {
          gfx_line(x,y+25, x+20, y+16);
          gfx_line(x+20,y+16, x+24, y-6);
          gfx_line(x+24,y-6, x+11, y-23);
          gfx_line(x+11,y-23, x-11, y-23);
          gfx_line(x-11,y-23, x-24, y-6);
          gfx_line(x-24,y-6, x-20, y+16);
          gfx_line(x-20,y+16, x, y+25);
        }
        if (c == 56) {
          gfx_line(x-10,y+23, x+10, y+23);
          gfx_line(x+10,y+23, x+23, y+10);
          gfx_line(x+23,y+10, x+23, y-10);
          gfx_line(x+23,y-10, x+10, y-23);
          gfx_line(x+10,y-23, x-10, y-23);
          gfx_line(x-10,y-23, x-23, y-10);
          gfx_line(x-23,y-10, x-23, y+10);
          gfx_line(x-23,y+10, x-10, y+23);
        }
        if (c == 57) {
          gfx_line(x,y+25, x+16, y+19);
          gfx_line(x+16,y+19, x+25, y+4);
          gfx_line(x+25,y+4, x+22, y-12);
          gfx_line(x+22,y-12, x+9, y-23);
          gfx_line(x+9,y-23, x-9, y-23);
          gfx_line(x-9,y-23, x-22, y-13);
          gfx_line(x-22,y-13, x-25, y+4);
          gfx_line(x-25,y+4, x-16, y+19);
          gfx_line(x-16,y+19, x, y+25);
        }
      
      if(c == 'q') break;        
    }

  }





return 0;
}
