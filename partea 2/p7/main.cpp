#include <bits/stdc++.h>
#include <exception>

using namespace std;


class IntVector
{private:
    int size;
    int *data;
  public:
      IntVector();
      IntVector(int k,int x);
      IntVector(const IntVector& v); /// constructor de copiere
      IntVector(IntVector&& v);      /// constructor  de mutare obiect
      ~IntVector();

      IntVector& operator=(IntVector& v);  /// pentru copiere obiect
      IntVector& operator=(IntVector&& v); /// pentru mutare obiect
      int operator[](int i) ;
      void PushBack(int x);

      int getSize() {return size;}
      int* getData() {return data;}
      void setSize(int n) {size=n;}
      void setData(int *d) {data=d;}
      int getelement(int i) {return data[i];}

};

IntVector::IntVector()
{  data=NULL;
   size=0;
}

IntVector::IntVector(int k,int x=0)
{data=new int[k];
 size=k;
 for(int i=0; i<size; i++)
    data[i]=x;
}

IntVector::IntVector(const IntVector &v)
{size=v.size;
 data=new int[size];
 for(int i=0; i<size; i++)
    data[i]=v.data[i];
}

IntVector::IntVector(IntVector&& v)
{size=v.size;
 data=new int[size];
 for(int i=0; i<size; i++)
    data[i]=v.data[i];
 delete[] v.data;
 v.size=0;
}

IntVector::~IntVector()
{delete[] data;
 size=0;
}

ostream & operator<<(ostream &out, IntVector &v)
{ int n=v.getSize();
  int *a=v.getData();
  if(n==0) out<<"Vector vid\n";
  for(int i=0; i<n; i++)
     out<<a[i]<<" ";
  out<<"\n";
  return out;
}

istream & operator>>(istream &in, IntVector &v)
{   if (v.getSize()>0)
      delete[]v.getData();
    int n;
    int *d;
    in>>n;
    d=new int[n];
    for(int i=0; i<n; i++)
      in>>d[i];
    v.setSize(n);
    v.setData(d);
    return in;
}

IntVector& IntVector::operator=(IntVector& v)
{delete[]data; ///eliberam spatiul de memorie alocat obiectului curent
 size=v.size;
 data=new int[size];
 for(int i=0; i<size; i++)
    data[i]=v.data[i];
  return *this;
}

IntVector& IntVector::operator=(IntVector&& v) /// muta obiectul v
{delete[]data; ///eliberam spatiul de memorie alocat obiectului curent
 size=v.size;
 data=new int[size];
 for(int i=0; i<size; i++)
    data[i]=v.data[i];
 delete[] v.data; /// eliberam spatiul de memorie alocat obiectului v
 v.size=0; /// iar size trebuie sa fie 0
 return *this;
}


void IntVector::PushBack(int x)
{int *a=new int[size+1];
 for(int i=0; i<size; i++)
    a[i]=data[i];
 a[size]=x;
 size++;
 delete[] data;
 data=a;
}

int IntVector::operator[](int i)
{   try
       {   if (i<0 || i>(size-1)) throw (out_of_range) "5";
            else
           return data[i];}
    catch (out_of_range x)
      {cout<<"Range error";
       exit(EXIT_FAILURE);
      }

}


int main()
{
    IntVector v(10,5); /// constructor cu parametri
    cout<<v;
    IntVector a(v); /// constructor de copiere
    cout<<a;
    IntVector b=a; /// copiere
    cout<<b;
    b.PushBack(100);
    cout<<b;
    cout<<v[4]<<" ";cout<<v[34];

    return 0;
}



