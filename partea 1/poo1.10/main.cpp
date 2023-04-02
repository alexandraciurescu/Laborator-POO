#include <iostream>

using namespace std;

struct Achizitie
{int id;
 double valoare;
};

struct ReferintaAchizitie
{const int id;
 Achizitie& achizitie;
 ReferintaAchizitie(Achizitie& x): id(x.id), achizitie(x){};
};

int main()
{
    Achizitie x;
    x.id=100;
    x.valoare=5;
    ReferintaAchizitie r(x);
    cout<<r.id<<" "<<r.achizitie.id<<" "<<r.achizitie.valoare;

    return 0;
}
