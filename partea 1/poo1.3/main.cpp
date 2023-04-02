#include <iostream>

using namespace std;

int main()
{
    int n;
    do
    {
        cout<<"Dati numarul: ";
        cin>>n;
    }
    while(n%2==1 || n<=0);
    cout<<n/2;
    return 0;
}
