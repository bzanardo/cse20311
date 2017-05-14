// Maria Beatriz Zanardo
// Interface for Lifeboard class

class Lifeboard {
  public:
    Lifeboard();
    ~Lifeboard();
    void setLifeboard(char [42][42]);
    void add(int,int);
    void remove(int, int);
    void print();
    void getArr(char [42][42]);
  private:
    char arr[42][42];
};
