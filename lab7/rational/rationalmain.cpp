#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s, d, p, q;

  cout << "*** display a and b ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print();  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
     cout << "*** compute s as the math sum of a and b, and display s ***\n";
     s = a.add(b);
     s.print();

  // subtract a and b
     cout << "*** compute d as the math difference of a and b, and display d ***\n";
     d = a.subtract(b);
     d.print();

// multiply a and b
     cout << "*** compute p as the product of a and b, and display p ***\n";
     p = a.multiply(b);
     p.print();

// divide a by b
     cout << "*** compute q as the quotient of a and b, and display p ***\n";
     q = a.divide(b);
     q.print();
return 0;
}
