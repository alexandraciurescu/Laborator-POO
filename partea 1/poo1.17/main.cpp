#include <iostream>
#include <cstring>

using namespace std;
class String
{ private:
    char *sir;
    int size;
 public:
     String();
     String(char s[]);
     String(String& s);
     String(String&& s);
     ~String();
     String &operator=(String& s);
     String &operator=(String&& s);

     friend String operator+(String &s, String &t);
     int getSize() {return size;}
     char* getSir() {return sir;}
     void AddChar(char c);
     bool Find(char subsir[]);


};

String::String()
{ sir=NULL;
  size=0;
}

String::String(char s[])
{ size=strlen(s);
  sir=new char[size];
  strcpy(sir,s);
}

String::String(String &s)
{if(&s!=this)
  {size=s.size;
   sir=new char[size];
   strcpy(sir,s.sir);
  }
}

String::String(String&& s)
{if(&s!=this)
  {size=s.size;
   sir=new char[size];
   strcpy(sir,s.sir);
   delete[] s.sir;
   s.size=0;
  }

}


String::~String()
{
    delete[] sir;
    size=0;
}

String& String::operator=(String &s)
{
    if(this!=&s)
      {delete[] sir;
       size=s.size;
       sir=new char[size];
       strcpy(sir,s.sir);
      }
    return *this;
}

String& String::operator=(String&& s)
{
    if(this!=&s)
      {delete[] sir;
       size=s.size;
       sir=new char[size];
       strcpy(sir,s.sir);
       delete[] s.sir;
       s.size=0;
      }
    return *this;
}

String operator+(String &s, String &t)
{ ///concatenare s cu t
  String nou;
  nou.size=s.size+t.size;
  nou.sir=new char[nou.size];
  strcpy(nou.sir,s.sir);
  strcat(nou.sir,t.sir);
  return nou;
}



void String::AddChar(char c)
{ char s[size];
  strcpy(s,sir);
  delete[] sir;
  sir=new char[size+1];
  strcpy(sir,s);
  sir[size]=c;
  size++;
  sir[size]=NULL;
}

bool String::Find(char subsir[])
{ if(strstr(sir,subsir)!=NULL)
   return 1;
  else return 0;

}

int main()
{
    String s("Un sir de caractere");
    cout<<s.getSir()<<"\n";

    String t(s);
    cout<<t.getSir()<<"\n";

    String w;
    w=t;
    cout<<w.getSir()<<"\n";

    s.AddChar('x');
    cout<<s.getSir()<<"\n";

    String t2=s+w;
    cout<<t2.getSir()<<"\n";

    cout<<t.Find("car");
    return 0;
}
