#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> a; /// int a[100];
    vector <double> v(10,2.5); /// vector de numere reale
    vector <double> t={2.5, 0, 3.1, -4.3, 1};
    vector <vector <int>> A; /// matrice
    for(auto it=t.begin(); it!=t.end(); it++)
        cout<<*it<<" ";
    cout<<"\n";

    vector <double>s(t); /// sau vector s=t;
    for(auto it=s.begin(); it!=s.end(); it++)
        cout<<*it<<" ";
    cout<<"\n";

    int n;
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
         cin>>v[i];
    for(auto it=v.begin(); it!=v.end(); it++)
        cout<<*it<<" ";
    cout<<"\n";
    for(auto it=v.rbegin(); it!=v.rend(); it++)
        cout<<*it<<" ";
    cout<<"\n";

    v.push_back(100);
    for(auto it=v.rbegin(); it!=v.rend(); it++)
        cout<<*it<<" ";
    cout<<"\n";

    int l=v.size();
    double suma=0;
    for(auto it=v.begin(); it!=v.end(); it++)
        suma=suma+*it;
    cout<<(double)suma/l;

    return 0;
}
