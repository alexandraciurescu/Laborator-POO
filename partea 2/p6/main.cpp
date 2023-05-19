#include <iostream>

using namespace std;

class Labelable
{ string label;
  public:
      string getlabel(){return label;}
      void setlabel(string l) {label=l;}

};

class Shape{
    public:
    virtual double compute_perimeter() const = 0;
    virtual double compute_area() const = 0;
};

class Triangle: public Shape, public Labelable
{ double baza,h;
  public:
      Triangle() {baza=h=0;}
      Triangle(double b, double h1) {baza=b; h=h1;}
      double compute_perimeter() const {return 3*baza;}
      double compute_area()const {return (baza*h)/2;}
};

class Rectangle: public Shape,public Labelable
{double l,L;
 public:
     Rectangle() {l=L=0;}
     Rectangle(double l1,double L1) {l=l1; L=L1;}
     double compute_perimeter() const {return 2*l+2*L;}
     double compute_area()const {return l*L;}
};

class Circle: public Shape,public Labelable
{double raza;
 public:
     Circle() {raza=0;}
     Circle(double r) {raza=r;}
     double compute_perimeter() const {return 2*3.14*raza;}
     double compute_area()const {return 3.14*raza*raza;}
};

void print_shape_size(Shape& shape)
{
  cout << "Figura geometrica are perimetrul "
<< shape.compute_perimeter()
<< " si aria "
<< shape.compute_area()
<< endl;
}

int main()
{
    Triangle t(5,4);
    Rectangle r(3,6);
    Circle c(4);
    c.setlabel("cerc");
    cout<<c.getlabel();
    return 0;
}
