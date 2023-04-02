#include <iostream>
#include <cmath>

using namespace std;

struct Complex
{ private:
  double re,im;
  public:
  Complex();
  Complex(double x,double y): re(x), im(y){};
  static Complex from_polar(double modulus,double angle);
  friend Complex operator+(Complex A, Complex B);
  friend Complex operator-(Complex A, Complex B);
  friend Complex operator* (Complex A, Complex B);
  friend Complex operator/ (Complex A, Complex B);
  friend bool operator== (Complex A, Complex B);
  friend bool operator!= (Complex A, Complex B);

  double getRe() {return re;}
  double getIm() {return im;}
  void setRe(double x) {re=x;}
  void setIm(double y) {im=y;}


};

Complex::Complex()
{ im=0;
  re=0;
}

static Complex from_polar(double modulus,double angle)
{Complex C;
 double Re,Im;
 Re=modulus*cos(angle);
 Im=modulus*sin(angle);
 C.setRe(Re);
 C.setIm(Im);
 return C;
}

Complex operator+(Complex A, Complex B)
{ Complex s;
  s.re=A.re+B.re;
  s.im=A.im+B.im;
  return s;

}

Complex operator-(Complex A, Complex B)
{ Complex s;
  s.re=A.re-B.re;
  s.im=A.im-B.im;
  return s;

}

Complex operator*(Complex A, Complex B)
{ Complex S;
  S.re=A.re*B.re-A.im*B.im;
  S.im=A.im*B.re+A.re*B.im;
  return S;
}

Complex operator/(Complex A, Complex B)
{ Complex S;
  S.re=(A.re*B.re+A.im*B.im)/(A.re*A.re+A.im*A.im);
  S.im=(A.re*B.im-B.re*A.im)/(A.re*A.re+A.im*A.im);
  return S;
}

bool operator== (Complex A, Complex B)
{ return A.re==B.re && A.im==B.im;

}
bool operator!= (Complex A, Complex B)
{ return A.re!=B.re || A.im!=B.im;

}

istream & operator>> (istream & in, Complex &C)
{   double x,y;
    in>>x>>y;
    C.setRe(x); C.setIm(y);
    return in;
}

ostream & operator<< (ostream &out, Complex &C)
{
    out<<C.getRe()<<" "<<C.getIm()<<"\n";
    return out;
}




int main()
{
    Complex c,d(1,2);
    /*
    cout<<c.re<<" "<<c.im<<"\n";
    cout<<d.re<<" "<<d.im<<"\n";
    Complex z=from_polar(2,0.5);
    cout<<z.re<<" "<<z.im<<"\n";
    cout<<z;
    */
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
