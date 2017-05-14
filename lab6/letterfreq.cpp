// Maria Beatriz Zanardo
// Lab 6, Part 2

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <array>
#include <string>
#include <vector>

using namespace std;

int main() {

  array<int,28> frequency = {};	
  // frequency[0-25] represent the letters of the alphabet in order. frequency[26]
  // represents white space (not including lines) and frequency[27] punctuation.
 
  string filename;
  string filestring;
  vector <string> filevector;

  cout << "Please enter the file name: ";
  cin  >> filename;

  fstream ifs(filename);

  if (!ifs) {
    cout << "Error opening file." << endl;
    return 1;
  }

  while (!ifs.eof()) {
    getline(ifs, filestring);
    filevector.push_back (filestring);
  }  
  
  int total = 0;
  int lines = 0;

  for (auto it1 = filevector.begin(); it1 != filevector.end(); it1++, lines++){
    for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
      int num = 0;
      total++;
      *it2 = tolower(*it2);
      if (isspace(*it2) != 0) {
        frequency[27] = frequency[27] + 1;
      }

      if (ispunct(*it2) != 0) {
        frequency[26] = frequency[26] + 1;
      }

      else {
        num = *it2 - 97;  // Converts between ASCII number to 0-25 letter numbering system.
        frequency[num]++;
      }
    }
  }

  double tletters = 0;

  for (int i = 0; i <= 25; i++) {
    tletters = tletters + frequency[i];
  }  

  double twhite = frequency[27] + lines;
  double tchar = tletters + twhite + frequency[26];
  double spaceper = (twhite/tchar) * 100;

  char k;
  int j = 0;

  for (int i = 0; i <= 25; i++) {
    k = 97 + i;  // Conversion from ASCII to regular letter. 
    cout << setw(3) << k << ": " << setw(3) << frequency[i] << setw(3);
    j++;
    if (j % 6 == 0) {
      cout << endl;
    }
  }

  cout << endl;
  cout << "there were: " << tletters << " letters." << endl;
  cout << "there were: " << tchar << " characters." << endl;
  cout << "there were: " << twhite << " white space characters." << endl;
  cout << "space percentage: " << setprecision(3) << spaceper << "%" <<  endl;

return 0;
} 

