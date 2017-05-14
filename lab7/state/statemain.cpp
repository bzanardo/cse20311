// Driver to test State class
// Maria Beatriz Zanardo

#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;

#include "state.h"

void display (list<State> &);
void display2 (list<State> &, int);
void minp (list<State> &, int);
void minc (list<State> &, int);
void year (list<State> &, int);

int main()
{
  ifstream ifs;
  string infilename;
  string ab, name, cap, pop_s, yr_s, con_s;
  int pop, yr, con, option;
  list<State> states;
  State sts;

  cout << "Enter data file name: ";
  cin >> infilename;
  ifs.open(infilename);
  if (!ifs) {
    cout << "Invalid file name: " << infilename << endl;
    return 1;
  }

  char c = ifs.peek();
  while (c != EOF) {
    getline (ifs, ab, ',');
    getline (ifs, name, ',');
    getline (ifs, cap, ',');
    getline (ifs, pop_s, ',');
    getline (ifs, yr_s, ',');
    getline (ifs, con_s, '\n');
    pop = stoi (pop_s);
    yr = stoi (yr_s);
    con = stoi (con_s);
    sts = State(ab, name, cap, pop, yr, con);
    states.push_back(sts);
    c = ifs.peek();
  }

  while (option != 6) {
    cout << "Please choose one of the following options: " << endl;
    cout << " 1. Display all state names and abbreviations." << endl;
    cout << " 2. Display all the information of a given state." << endl;
    cout << " 3. Display all states with a minimum population." << endl;
    cout << " 4. Display all states with a minimum number of congress representatives." << endl;
    cout << " 5. Display all states that became states in a certain year." << endl;
    cout << " 6. Exit." << endl;
    cout << "Your choice: ";
    cin >> option;
    cout << endl;
  
    if ((option < 1) || (option > 6)) {
      cout << "Invalid option." << endl;
    }

    if (option == 1) {
      display(states);
    }

    if (option == 2) {
      int num;
      display(states);
      cout << "Please enter the number of the state: ";
      cin >> num;
      if ((num > 50) || (num < 0)) {
        cout << "Invalid option." << endl;
      }
      else { 
      display2 (states, num);
      }
    }

    if (option == 3) {
      int p;
      cout << "Please enter minimum population: ";
      cin >> p;
      if (p <= 0) {
        cout << "Invalid input." << endl;
      }
      else {
        minp (states, p);
      }
    }

    if (option == 4) {
      int c;
      cout << "Please enter minimum number of congress representatives: ";
      cin >> c;
      if (c <= 0) {
        cout << "Invalid input." << endl;
      }
      else {
        minc (states, c);
      }
    }

    if (option == 5) {
      int y;
      cout << "Please enter a year: ";
      cin >> y;
      if (y <= 0) {
        cout << "Invalid input." << endl;
      }
      else {
        year (states, y);
      }
    }
  }  

return 0;
}

void display (list<State> &s)
{
  int n = 1;

  for (auto it = s.begin(); it != s.end(); ++it) {
    cout << n << ". " << "(" <<  it->getAbr() << ") ";
    cout << it->getStatename() << endl;
    //cout << "Capital: " << it->getCapital() << endl;
    //cout << "Population: " << it->getPopulation() << endl;
    //cout << "Year it became a state: " << it->getYear() << endl;
    //cout << "Number of congress representatives: " << it->getCongress() << endl;
    n++;
    cout << endl;
    }
}

void display2 (list<State> &s, int n)
{
  auto it = s.begin();
  advance (it, n - 1);
  cout << "(" <<  it->getAbr() << ") ";
  cout << it->getStatename() << endl;  
  cout << "Capital: " << it->getCapital() << endl;
  cout << "Population: " << it->getPopulation() << endl;
  cout << "Year it became a state: " << it->getYear() << endl;
  cout << "Number of congress representatives: " << it->getCongress() << endl; 
  cout << endl;
}

void minp (list<State> &s, int p)
{
  int i = 0;
  for (auto it = s.begin(); it != s.end(); ++it) {
    int pop = it->getPopulation();
    if (pop >= p) {
      cout << "(" <<  it->getAbr() << ") ";
      cout << it->getStatename() << endl;
      cout << "Population: " << it->getPopulation() << endl;
      cout << endl;
      i++;
    } 
  }
  if (i == 0) {
    cout << "There aren't any states with this population." << endl;
  }
}

void minc (list<State> &s, int c)
{
  int i = 0;
  for (auto it = s.begin(); it != s.end(); ++it) {
    int con = it->getCongress();
    if (con >= c) {
      cout << "(" <<  it->getAbr() << ") ";
      cout << it->getStatename() << endl;
      cout << "Number of congress representatives: " << it->getCongress() << endl;
      cout << endl;
      i++;
    }
  }
  if (i == 0) {
    cout << "There aren't any states with this number of congress representatives." << endl;
  }
}

void year (list<State> &s, int y)
{
  int i = 0;
  for (auto it = s.begin(); it != s.end(); ++it) {
    int year = it->getYear();
    if (year == y) {
      cout << "(" <<  it->getAbr() << ") ";
      cout << it->getStatename() << endl;
      cout << "Year it became a state: " << it->getYear() << endl;
      cout << endl;
      i++;
    }
  }
  if (i == 0) {
    cout << "No states became states this year." << endl;
  }

} 
