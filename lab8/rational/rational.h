#include<iostream>
using namespace std;

class Rational {
 friend ostream& operator<< (ostream &, Rational &);
 friend istream& operator>> (istream &, Rational &);
  public:
    Rational();
    Rational(int, int);
    void setRational (int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
    void print();
    Rational add(Rational);
    Rational subtract(Rational);
    Rational multiply(Rational);
    Rational divide(Rational);
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
  private:
    int numer;
    int denom;
};
