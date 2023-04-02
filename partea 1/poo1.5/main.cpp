#include <iostream>

using namespace std;

void interschimba(int &a, int &b)
{int aux=a;
 a=b;
 b=aux;
}

int main()
{
    int a,b;
    cin>>a>>b;
    interschimba(a,b);
    cout<<a<<" "<<b;
    return 0;
}
