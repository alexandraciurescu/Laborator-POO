#include <iostream>
#include <cstdio>

using namespace std;

class MyFile
{ private:
  FILE* f;
  public:
  MyFile(const char nume_fisier[]);
  ~MyFile() {fclose(f);}
  void write(int n);
  private:
    MyFile(const MyFile&){};
    void operator=(const MyFile&)=delete;

};

MyFile::MyFile(const char nume_fisier[])
{f=fopen(nume_fisier,"w");
}

void MyFile::write(int n)
{fprintf(f,"%d\n",n);
}

int main()
{
    MyFile f("fisier.txt");
    //MyFile g(f);
    MyFile g=f;

    return 0;
}
