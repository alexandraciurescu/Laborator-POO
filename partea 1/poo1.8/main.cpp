#include <iostream>
#include <cmath>

using namespace std;

struct Complex
{ double re,im;
  Complex();
  Complex(double x,double y): re(x), im(y){};
  static Complex from_polar(double modulus,double angle);
  Complex operator+(Complex a);
  Complex operator-(Complex a);
  Complex operator* (Complex A);
  Complex operator/ (Complex A);
  bool operator== (Complex A);
  bool operator!= (Complex A);

};

Complex::Complex()
{ im=0;
  re=0;
}

static Complex from_polar(double modulus,double angle)
{Complex C;
 C.re=modulus*cos(angle);
 C.im=modulus*sin(angle);
 return C;
}

Complex Complex::operator+(Complex a)
{ Complex s;
  s.re=a.re+re;
  s.im=a.im+im;
  return s;

}

Complex Complex::operator-(Complex a)
{ Complex s;
  s.re=this->re-a.re;
  s.im=this->im-a.im;
  return s;

}

Complex Complex::operator*(Complex A)
{ Complex S;
  S.re=A.re*re-A.im*im;
  S.im=A.im*re+A.re*im;
  return S;
}

Complex Complex::operator/(Complex A)
{ Complex S;
  S.re=(A.re*re+A.im*im)/(A.re*A.re+A.im*A.im);
  S.im=(A.re*im-re*A.im)/(A.re*A.re+A.im*A.im);
  return S;
}

bool Complex::operator== (Complex A)
{ return A.re==re && A.im==im;

}
bool Complex::operator!= (Complex A)
{ return A.re!=re || A.im!=im;

}

ostream &operator<<(ostream &out, const Complex &c)
{ out<<c.re<<" "<<c.im<<"\n";

}

istream &operator>>(istream &in, Complex &c)
{
    in>>c.re>>c.im;
}




int main()
{
    Complex c,d(1,2);
    cout<<c.re<<" "<<c.im<<"\n";
    cout<<d.re<<" "<<d.im<<"\n";
    Complex z=from_polar(2,0.5);
    cout<<z.re<<" "<<z.im<<"\n";
    cout<<c;
    cin>>d;
    cout<<d;
    //operatori aritmetici
    Complex A,B,S;
    cin>>A>>B;
    S=A+B;
    cout<<S;
    S=A-B;
    cout<<S;
    S=A*B;
    cout<<S;
    S=A/B;
    cout<<S;
    if(A==B) cout<<"Egale";
    if(A!=B) cout<<"Diferite";
    return 0;
}
