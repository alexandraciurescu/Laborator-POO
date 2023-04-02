#include <iostream>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    for(i=1; i<=n; i++)
        if(i%3==0 && i%5!=0)
          cout<<"Fizz"<<"\n";
        else if(i%3!=0 && i%5==0)
            cout<<"Buzz"<<"\n";
             else if(i%3==0 && i%5==0)
                cout<<"FizzBuzz"<<"\n";
                   else cout<<i<<"\n";
    return 0;
}
