// Interface for State class

#include<string>
using namespace std;

class State {
  public:
    State();
    State(string, string, string, int, int, int);
    ~State();
    void setStatename(string);
    void setAbr(string);
    void setCapital(string);
    void setPopulation(int);
    void setYear(int);
    void setCongress(int);
    string getStatename();
    string getAbr();
    string getCapital();
    int getPopulation();
    int getYear();
    int getCongress();
  private:
    string statename;
    string abr;
    string capital;
    int population;
    int year;
    int congress;
};

