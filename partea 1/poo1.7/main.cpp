#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int *a=new int[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    sort(&a[0],&a[n]);
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    delete[] a;
    return 0;
}
