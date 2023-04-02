#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

class MyFile
{ private:
  FILE* f;
  public:
  MyFile(const char nume_fisier[]);
  MyFile(MyFile&& other); //constructor de mutare
  ~MyFile() {if(f!=NULL) fclose(f);}
  void operator=(MyFile&& other);
  void write(int n);
  private:
    MyFile(const MyFile&){}; //constructor de copiere
    void operator=(const MyFile&)=delete;


};

MyFile::MyFile(const char nume_fisier[])
{f=fopen(nume_fisier,"w");
}

void MyFile::write(int n)
{ if(f!=NULL)
    fprintf(f,"%d\n",n);
}

MyFile::MyFile(MyFile&& other)
{f=other;
 other=NULL;
}

void MyFile::operator=(MyFile&& other)
{f=other;
 other=NULL;
}



int main()
{
    MyFile file1("fisier1.out"),file2("fisier2.out");
    MyFile file3(move(file1));
    file1=move(file2);
    return 0;
}
