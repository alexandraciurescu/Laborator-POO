#include <iostream>

using namespace std;

void interschimba(int *a, int *b)
{int aux;
 aux=*a;
 *a=*b;
 *b=aux;
}

int main()
{
    int x=1,y=2;
    interschimba(&x,&y);
    cout<<x<<" "<<y;
    return 0;
}
