#include <string>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    /*string s;
    string t="exemplu";
    string p=t;
    string q(t);
    q.clear();
    cout<<s<<" "<<t<<" "<<p<<" "<<q.empty();
    cin>>q;
    cout<<q;
    int n;
    cin>>n;
    cin>>ws;
    std::getline(std::cin,s);
    cout<<s;
    //cout<<s.length();
    //cout<<s[0]<<" "<<s[100]<<"\n";
    //cout<<s.at(0)<<" "<<s.at(100);

    for(int i=0; i<s.length(); i++) cout<<s[i]<<" ";
    cout<<"\n";

    for(int i=0; i<s.length(); i++) cout<<s.at(i)<<" ";
    cout<<"\n";

    for(auto it=s.begin(); it!=s.end(); it++)
        {char caracter=*it;
         cout<<caracter<<" ";
        }

    /*string t="F";
    std::size_t pos{};
    int n=std::stoi(t,&pos,16);
    cout<<n;*/

    string text, cuv;
    std::getline(std::cin,text);
    cin>>cuv;

    std::size_t poz=text.find(cuv);
    if(poz==std::string::npos) cout<<"Nu";
    else cout<<poz;

    return 0;
}
