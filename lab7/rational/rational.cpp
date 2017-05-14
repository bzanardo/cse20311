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
  
  int N = (a*d) + (c*b);
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


