#include <iostream>
#include <cmath>

using namespace std;

int absolute_value(int n)
{
    return abs(n);
}

double absolute_value(double n)
{
    return abs(n);
}

double absolute_value(double re, double im)
{
    return sqrt(re*re+im*im);
}

double absolute_value(double x, double y, double z)
{
    return sqrt(x*x+y*y+z*z);
}


int main()
{
    cout<<absolute_value(-6)<<"\n";
    cout<<absolute_value(-2.5)<<"\n";
    cout<<absolute_value(-2,8)<<"\n";
    cout<<absolute_value(1,2,3)<<"\n";
    return 0;
}
