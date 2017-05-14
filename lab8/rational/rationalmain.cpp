#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b, s, d, p, q;

  cout << "\nGetting values for b:" << endl;
  cin >> b;

  cout << "*** display a and b ***\n";
  cout << a << endl;
  cout << b << endl;

  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a + b; 
  cout << s << endl;

  cout << "*** compute d as the math difference of a and b, and display d ***\n";
  d = a - b;
  cout << d << endl;

  cout << "*** compute p as the product of a and b, and display p ***\n";
  p = a*b;
  cout << p << endl;

  cout << "*** compute q as the quotient of a and b, and display p ***\n";
  q = a/b;
  cout << q << endl;
return 0;
}
