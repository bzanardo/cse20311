// Maria Beatriz Zanardo
// Lab 6, Part 1

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void searchword(string, list<string> &);
void newfile(string, list<string> &);
void display(list<string> &);
void orderA (string, list<string> &);

int main ()
{
  int option;
  list<string> listsayings;
  string filename;
  string strsayings;

  cout << "Please enter the file name: ";
  cin  >> filename;

  fstream ifs(filename);

  if (!ifs) {
    cout << "Error opening file." << endl;
    return 1;
  }

  listsayings.push_back (strsayings);

  while (!ifs.eof()) {
    getline (ifs, strsayings);
    orderA (strsayings, listsayings);
  }

  listsayings.pop_front();
  listsayings.pop_front();

  while (option != 6) {
    cout << endl;
    cout << "Choose one of the following options:" << endl;
    cout << " 1: Show all sayings." << endl;
    cout << " 2: Enter a new saying." << endl;
    cout << " 3: List sayings containing a certain word." << endl;
    cout << " 4: Save all sayings in a new text file." << endl;
    cout << " 5: Delete a saying." << endl;
    cout << " 6: Quit." << endl;
    cout << "Your choice: ";
    cin >> option;
    cout << endl;

    if ((option < 1) || (option > 6)) {
      cout << "Invalid option." << endl;
    }

    if (option == 1) {
      display(listsayings);
    }

    if (option == 2) {
      string newPhrase;
      cin.ignore();
      cout << "Enter a saying: ";
      getline(cin, newPhrase);
      orderA (newPhrase, listsayings);
    }

    if (option == 3) {
      string searchPhrase;
      cout << "Enter word: ";
      cin >> searchPhrase;
      searchword(searchPhrase, listsayings);
    }

    if (option == 4) {
      string newfilename;
      cout << "Enter new file name: ";
      cin >> newfilename;
      newfile (newfilename, listsayings);
    }

    if (option == 5) {
      display(listsayings);
      unsigned int num;
      cout << "Please enter the number of the saying you wish to delete: ";
      cin >> num;
      if ( (num <= 0) || (num > listsayings.size()) ) {
        cout << "Invalid option." << endl;
      }
      if ( (num <= 0) || (num > listsayings.size()) ) {
        cout << "Invalid option." << endl;
      }
      else {
        auto it = listsayings.begin();
	advance (it, num - 1);
        listsayings.erase (it);
        display(listsayings);
      } 
    }
  }

return 0;
}

void searchword(string a, list<string> &l)
{
  int i = 0;    // Counter for number of times the given word appears in vector.
  for (auto it = l.begin(); it != l.end(); it++) {
    int location;
    location = it->find(a);
    if (location >= 0) {
      cout << *it << endl;
      i++;
    }
  }
    if (i == 0) {
      cout << "There are no sayings containing this word." << endl;
    }
}

void newfile (string filename, list<string> &l)
{
  ofstream ofs;
  ofs.open (filename);

      for (auto it = l.begin(); it != l.end(); it++) {
        ofs << *it << " " << "\n";
      }

  ofs.close();
}

void display (list<string> &l)
{ 
  int n = 1;

  for (auto it = l.begin(); it != l.end(); it++, n++) {
    cout << " " << n << ". " << *it;
    cout << endl;
  }
}

void orderA (string newstr, list<string> &l) 
{
  auto it = l.begin();
    while ( (newstr.compare(*it) > 0) && (it != l.end()) ) {
      it++;
    }
    l.insert(it, newstr);
}
  
