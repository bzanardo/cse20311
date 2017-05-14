// Maria Beatriz Zanardo
#include "gfx.h"
#include <cmath>

#define PI 3.14159265

int abs (int);
void triangle (int, int, int, int, int, int);
void square (int, int, int);
void sierpinski (int, int, int, int, int, int);
void ShrinkingSquares (int, int, int);
void CircularLace (int, int, int);
void snowflake (int, int, int);
void tree (int, int, int, double);
void fern (double, double, double, double);
void SpiralSquares (int, int, double, double);

int main() {

  int x1, y1, x2, y2, x3, y3, xk, yk, lk, xs, ys, xc, yc, r, xt, yt, lt, xf, yf, lf;
  double theta, theta2, theta3, ls, xj, yj, lj;

  gfx_open(800, 800, "Fractals");

  char c;
  while (c != 'q') {
    c = gfx_wait();
    gfx_clear();
    switch (c) {
      case '1':  // Sierpinski Triangle
        x1 = 100;
        y1 = 100;
        x2 = 700;
        y2 = 100;
        x3 = 400;
        y3 = 700;  
        sierpinski(x1, y1, x2, y2, x3, y3);
        c = gfx_wait();
      break;

      case '2':  // Shrinking Squares
        xk = 400;
        yk = 400;
        lk = 200;
        ShrinkingSquares(xk,yk,lk);
      break;

      case '3':  // Spiral Squares
       theta3 = 0;
       xs = 400;
       ys = 400;
       ls = 1;
       SpiralSquares(xs, ys, ls, theta3);
      break;

      case '4':  // Circular Lace
       xc = 400;
       yc = 400;
       r = 250;
       CircularLace(xc, yc, r);
      break;

      case '5':  // Snowflake
       lf = 250;
       xf = 400;
       yf = 400;
       snowflake(xf, yf, lf);
      break;

      case '6':  // Tree
       theta = PI/2;
       xt = 400;
       yt = 750;
       lt = 200;
       tree(xt, yt, lt, theta);
      break;

      case '7':  // Fern
       theta2 = PI/2;
       xj = 400;
       yj = 750;
       lj = 400;
       fern(xj, yj, lj, theta2);
      break;

      /*case '8':  // Spiral of spirals
       // (set up variables)
       ...
       drawSpirals(...);
      break; */
    }
  }
  return 0;
}
int abs (int n)
{
  int m;
  if (n < 0) {
    m = -n;
  }
  else {
    m = n;
  }
  return(n);
}
void triangle (int x1, int y1, int x2, int y2, int x3, int y3) 
{
  gfx_color(255,255,255);
  gfx_line(x1,y1, x2, y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x1,y1);
}
void square (int x, int y, int l)
{
  gfx_line(x-(l/2), y-(l/2), x+(l/2), y-(l/2));
  gfx_line(x+(l/2), y-(l/2), x+(l/2), y+(l/2));
  gfx_line(x+(l/2), y+(l/2), x-(l/2), y+(l/2));
  gfx_line(x-(l/2), y+(l/2), x-(l/2), y-(l/2));
}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{ 
  if( abs(x2-x1) < 5) return;
  triangle( x1, y1, x2, y2, x3, y3 );
  sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
  sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
  sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

void ShrinkingSquares (int x, int y, int l)
{
  if (l < 5) return;
  square (x, y, l);
  ShrinkingSquares(x+(l/2), y+(l/2), l/2);                      
  ShrinkingSquares(x+(l/2), y-(l/2), l/2);
  ShrinkingSquares(x-(l/2), y+(l/2), l/2);
  ShrinkingSquares(x-(l/2), y-(l/2), l/2);
}

void CircularLace (int xc, int yc, int r)
{
  if (r < 1) return;
  gfx_circle(xc, yc, r);

  CircularLace(xc + (r*cos(0)), yc + (r*sin(0)), r/3);
  CircularLace(xc + (r*cos(PI/3)), yc + (r*sin(PI/3)), r/3);
  CircularLace(xc + (r*cos(2*PI/3)), yc + (r*sin(2*PI/3)), r/3);
  CircularLace(xc + (r*cos(PI)), yc + (r*sin(PI)), r/3);
  CircularLace(xc + (r*cos(4*PI/3)), yc + (r*sin(4*PI/3)), r/3);
  CircularLace(xc + (r*cos(5*PI/3)), yc + (r*sin(5*PI/3)), r/3);
}

void snowflake (int x, int y, int l2)
{
  if (l2 < 1) return;
  gfx_line(x, y, x + (l2*cos(PI/6)), y + (l2*sin(PI/6)) );
  gfx_line(x, y, x + (l2*cos(17*PI/30)), y + (l2*sin(17*PI/30)) );
  gfx_line(x, y, x + (l2*cos(29*PI/30)), y + (l2*sin(29*PI/30)) );
  gfx_line(x, y, x + (l2*cos(41*PI/30)), y + (l2*sin(41*PI/30)) );
  gfx_line(x, y, x + (l2*cos(53*PI/30)), y + (l2*sin(53*PI/30)) );

  snowflake(x + (l2*cos(PI/6)), y + (l2*sin(PI/6)), l2/3);
  snowflake(x + (l2*cos(17*PI/30)), y + (l2*sin(17*PI/30)), l2/3);
  snowflake(x + (l2*cos(29*PI/30)), y + (l2*sin(29*PI/30)), l2/3);
  snowflake(x + (l2*cos(41*PI/30)), y + (l2*sin(41*PI/30)), l2/3);
  snowflake(x + (l2*cos(53*PI/30)), y + (l2*sin(53*PI/30)), l2/3);
}

void tree (int x, int y, int l, double theta)
{
  if (l < 0.5) return;
  int xf = x + (l*cos(theta));
  int yf = y - (l*sin(theta));
  gfx_line(x, y, xf, yf);   
  gfx_line(xf, yf, xf + (l*0.6)*cos(theta - (PI/6)), yf - (l*0.6)*sin(theta - (PI/6)) );
  gfx_line(xf, yf, xf + (l*0.6)*cos(theta + (PI/6)), yf - (l*0.6)*sin(theta + (PI/6)) );
  
  tree( xf + (l*0.6)*cos(theta - (PI/6)), yf - (l*0.6)*sin(theta - (PI/6)), l*0.6, theta-(PI/6)); 
  tree( xf + (l*0.6)*cos(theta + (PI/6)), yf - (l*0.6)*sin(theta + (PI/6)), l*0.6, theta + (PI/6)); 
}

void fern (double x, double y, double l, double theta)
{
  if (l < 10) return;
  double xf = x + (l*cos(theta));
  double yf = y - (l*sin(theta));
  gfx_line(x, y, xf, yf);
  gfx_line(xf, yf , xf + (l*0.33)*cos(theta - (PI/5)), yf - (l*0.33)*sin(theta - (PI/5)) );
  gfx_line(xf, yf, xf + (l*0.33)*cos(theta + (PI/5)), yf - (l*0.33)*sin(theta + (PI/5)) );
  gfx_line(xf + (l/4)*cos(theta), yf + (l/4)*sin(theta /*- (PI/5)*/), xf + (l*0.33)*cos(theta - (PI/5)), yf + (l/4) - (l*0.33)*sin(theta - (PI/5)) );
  gfx_line(xf - (l/4)*cos(theta), yf + (l/4)*sin(theta /*+ (PI/5)*/), xf + (l*0.33)*cos(theta + (PI/5)), yf + (l/4) - (l*0.33)*sin(theta + (PI/5)) );
  gfx_line(xf + (l/2)*cos(theta), yf + (l/2)*sin(theta /*- (PI/5)*/), xf + (l*0.33)*cos(theta - (PI/5)), yf + (l/2) - (l*0.33)*sin(theta - (PI/5)) );
  gfx_line(xf - (l/2)*cos(theta), yf + (l/2)*sin(theta /*+ (PI/5)*/), xf + (l*0.33)*cos(theta + (PI/5)), yf + (l/2) - (l*0.33)*sin(theta + (PI/5)) );
  gfx_line(xf + (3*l/4)*cos(theta), yf + (3*l/4)*sin(theta /*- (PI/5)*/), xf + (l*0.33)*cos(theta - (PI/5)), yf + (3*l/4) - (l*0.33)*sin(theta - (PI/5)) );
  gfx_line(xf - (3*l/4)*cos(theta), yf + (3*l/4)*sin(theta /*+ (PI/5)*/), xf + (l*0.33)*cos(theta + (PI/5)), yf + (3*l/4) - (l*0.33)*sin(theta + (PI/5)) );

  theta = theta - (PI/5);
  fern (xf, yf, l*0.33, (theta) );
  //fern (xf, yf, l*0.33, (-theta) );
  //fern (xf, yf + (l/4), l*0.33, (theta) );
  //fern (xf, yf + (l/4), l*0.33, (-theta) );
  //fern (xf, yf + (, l*0.33, (theta - (PI/5)) );
}

void SpiralSquares (int x, int y, double l, double theta)
{
  if ( l > 200) return;
  square(x, y, l);
  SpiralSquares ( x + 2*l*cos(theta), y - 2*l*sin(theta), l*1.2, theta + (PI/3) ); 

}
