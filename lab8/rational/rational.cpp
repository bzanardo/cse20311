#include<cmath>
#include"rational.h"
#include<iostream>

using namespace std;

Rational::Rational()
{ 
  numer = 1;
  denom = 1;
}

Rational::Rational(int n, int d)
{ 
  numer = n;
  denom = d;
}
void Rational::setRational (int n, int d)
{
  setNumer(n);
  setDenom(d);
}

Rational::~Rational() {}

int Rational:: getNumer()
{ 
  return (numer);
}

int Rational:: getDenom()
{ 
  return (denom);
}

void Rational:: setNumer(int n)
{ 
  numer = n;
}

void Rational::setDenom(int d)
{ 
  denom = d;
}


void Rational::print()
{ 
  cout << numer << "/" << denom << endl;
}

Rational Rational::add(Rational A)
{ 
  int a = A.getNumer();
  int b = A.getDenom();
  int c = numer;
  int d = denom;

  int N = (c*b) + (a*d);
  int D = (d*b);

  Rational r(N,D);

  return (r);
}

Rational Rational::subtract(Rational A)
{
  int a = A.getNumer();
  int b = A.getDenom();
  int c = numer;
  int d = denom;

  int N = (c*b) - (a*d);
  int D = (d*b);

  Rational r(N,D);

  return (r);
}

Rational Rational::multiply(Rational A)
{
  int a = A.getNumer();
  int b = A.getDenom();
  int c = numer;
  int d = denom;

  int N = (a*c);
  int D = (d*b);

  Rational p(N,D);

  return (p);
}

Rational Rational::divide(Rational A)
{
  int a = A.getNumer();
  int b = A.getDenom();
  int c = numer;
  int d = denom;

  int N = (c*b);
  int D = (d*a);

  Rational q(N,D);

  return (q);
}

Rational Rational::operator+(Rational A)
{
  return Rational ( ((numer * A.denom) + (A.numer * denom)) , (denom * A.denom ) );
}  

Rational Rational::operator-(Rational A)
{
  return Rational ( ((numer * A.denom) - (A.numer * denom)) , (denom * A.denom ) );
}

Rational Rational::operator*(Rational A)
{
  return Rational ( (numer * A.numer) , (denom * A.denom) );
}

Rational Rational::operator/(Rational A)
{
  return Rational ( (numer * A.denom) , (denom * A.numer) );
}

ostream& operator<< (ostream &s, Rational &A)
{
  s << A.numer << "/" << A.denom;
  
  return s;
}

istream& operator>> (istream &s, Rational &A)
{
  int x, y;
  cout << "Enter the numerator and denominator: ";
  s >> x >> y;
  A.setRational(x, y);

  return s;
}
