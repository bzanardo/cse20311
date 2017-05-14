// Maria Beatriz Zanardo

#include <iostream>
#include "lifeboard.h"
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

using namespace std;

void check (char arr[42][42], char temp[42][42]);

int main (int argc, char *argv[]) 
{
  Lifeboard a;
  string option;
  char arr[42][42];
  char temp[42][42];
   
  cout << "Instructions: please enter a command folowed by a coordinate. The coordinates range from 1 to 40 (0 not included)." << endl;
  if (argc == 1) {
    while(option != "q") {
      cout << "Please choose one of the following commands: "<< endl;
      cout << "a: add a new live cell." << endl;
      cout << "r: remove a cell." << endl;
      cout << "n: advance the simulation to the next iteration." << endl;
      cout << "q: quit." << endl;
      cout << "p: play game continuously." << endl;
      cin >> option;

      if (option == "a") {
        int r, c;
        cin >> c >> r;
        a.add(c,r); // (row, column)
        a.print();
      }

      if (option == "r") {
        int r, c;
        cin >> c >> r;
        a.remove(c,r); // (row, column)
        a.print();
      } 
   
      if (option == "n") {
        a.getArr(arr);
        a.getArr(temp);
        check(arr, temp);
        a.setLifeboard(arr);
        a.print(); 
      }

      if (option == "p") {
        int i = 1;
        while (i = 1) {
          a.getArr(arr);
          a.getArr(temp);
          check(arr, temp);
          a.setLifeboard(arr);
          a.print();
          usleep(80000);
          system("clear");
        }
      }

    }
  }
else {
  ifstream ifs(argv[1]);
  ifs >> option;
  while (option != "p"){
    if (option == "a") {
      int r, c;
      ifs >> r; 
      ifs >> c;
      a.add(r,c); // (row, column)
      a.print();
    }
    if (option == "r") {
      int r, c;
      ifs >> r; 
      ifs >> c;
      a.remove(r,c); // (row, column)
      a.print();
    }
    ifs >> option;
  }
  if (option == "p") {
    int i = 1;
    while (i = 1) {
      a.getArr(arr);
      a.getArr(temp);
      check(arr, temp);
      a.setLifeboard(arr);
      a.print();
      usleep(80000);
      system("clear");
    }
  }   
} 
return 0;
}

void check (char arr[42][42], char temp[42][42])
{
  int living;
  for (int i = 1; i != 41; i++) {
    for (int j = 1; j != 41; j++) {
      living = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if ( arr[i+k][j+l] == 'X') {
            living++;
          }
        }
      }
      if (arr[i][j] == 'X') {  //  This statement is used so that the cell 
			       //  itself doesn't count as a living neighbor.
        living--;
      }
      if (living > 3) {
        temp[i][j] = ' ';
      }
      if (living == 3) {
        temp[i][j] = 'X';
      }
      if (living < 2) {
        temp[i][j] = ' ';
      }

    }
  }

  for (int i = 0; i != 41; i++) {
    for (int j = 0; j != 41; j++) {
      arr[i][j] = temp[i][j];
    }
  }
}    
