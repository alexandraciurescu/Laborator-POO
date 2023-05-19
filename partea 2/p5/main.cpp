#include <iostream>
#include <string>

using namespace std;

class Labelable
{ string label;
  public:
      string getlabel(){return label;}
      void setlabel(string l) {label=l;}

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
