#include <iostream>
#include <vector>

using namespace std;

class Product
{ protected:
    double price;
  public:
      Product(double pret){price=pret;}
      virtual ~Product(){}
      virtual double get_price(){return price;}

};

class PerishableProduct: public Product
{bool expire;
 public:
     PerishableProduct(double pret,bool e):Product(pret){expire=e;}
     void setexpire(bool data){expire=data;}
     bool getexpire(){return expire;}
     double get_price(){if(expire==1) return price-0.1*price;
                        else return price;}

};

class ProductOnSale: public Product
{ double sale;
  public:
      ProductOnSale(double p, double s):Product(p){sale=s;}
      void setsale(double sale1) {sale=sale1;}
      double getsale(){return sale;}
      double get_price(){return price-(sale/100)*price;}

};

class PerishableProductOnSale: public PerishableProduct, public ProductOnSale
{public:
    PerishableProductOnSale(double p,bool e, double s):PerishableProduct(p,e),ProductOnSale(p,s){}
    double get_price(){if(getexpire()==1) return get_price()-((getsale()+10)/100)*get_price();
                       else return get_price()-(getsale()/100)*get_price();}

};

int main()
{
    vector <Product*> v;
    Product p(20);
    PerishableProduct pp(100,1);
    ProductOnSale pos(30,20);
    //PerishableProductOnSale ppos(100,1,50);
    v.push_back(&p);
    v.push_back(&pp);
    v.push_back(&pos);
    //v.push_back(&ppos);
    for(auto it=v.begin(); it!=v.end(); it++)
        cout<<(*it)->get_price()<<"\n";


    for(auto it=v.begin(); it!=v.end(); it++)
        delete *it;
    return 0;



}
