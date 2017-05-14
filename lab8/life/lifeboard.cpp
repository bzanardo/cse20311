// Maria Beatriz Zanardo
// Implementation for Lifeboard class

#include "lifeboard.h"
#include <iostream>

using namespace std;

Lifeboard::Lifeboard()
{
  for (int i = 0; i != 42; i++) {
    for (int j = 0; j != 42; j++) {
      arr[i][j] = ' '; 
      arr[i][0] = '|';
      arr[i][41] = '|';
      arr[0][j] = '-';
      arr[41][j] = '-';
    }
  }       
}

Lifeboard::~Lifeboard() {}

void Lifeboard::print()
{
  for (int i = 0; i != 42; i++) {
    for (int j = 0; j != 42; j++) {
      cout << arr[i][j];  
    }
    cout << endl;
  }
}

void Lifeboard::setLifeboard(char array[42][42])
{
  for (int i = 0; i != 42; i++) {
    for (int j = 0; j != 42; j++) {
      arr[i][j] = array[i][j];
    }
  }
}

void Lifeboard::add(int c, int r) 
{
  arr[r][c] = 'X';
}

void Lifeboard::remove(int c, int r)
{
  arr[r][c] = ' ';
}

void Lifeboard::getArr( char temp[42][42])
{
  for (int i = 0; i != 42; i++) {
    for (int j = 0; j != 42; j++) {
      temp[i][j] = arr[i][j];
    }
  }
}
