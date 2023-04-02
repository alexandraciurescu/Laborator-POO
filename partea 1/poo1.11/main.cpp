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

};

MyFile::MyFile(const char nume_fisier[])
{f=fopen(nume_fisier,"w");
}

void MyFile::write(int n)
{fprintf(f,"%d\n",n);
}

int main()
{
    MyFile fis("afisare.out");
    fis.write(100);
    fis.write(88);
    fis.write(1);
    return 0;
}
