#include <iostream>

using namespace std;



class IntList
{ private:
    class Node
     { public:
       int info;
       Node* urm;
     };
    Node* prim;
 public:
     IntList();
     IntList(int n, int v[]);
     IntList(const IntList& L);
     IntList(IntList&& L);
     ~IntList();

     IntList& operator=(const IntList& L);
     IntList& Concatenare(const IntList& L1, const IntList& L2);

     void AddFirst(int x);
     void AddLast(int x);
     void AfisareLista();


};

IntList::IntList()
{
    prim=NULL;
}

IntList::IntList(int n, int v[])
{prim=NULL;
 for(int i=0; i<n; i++)
    AddLast(v[i]);

}

IntList::IntList(const IntList& L)
{ prim=NULL;
  Node *p=L.prim;
  while(p!=NULL)
    {AddLast(p->info); p=p->urm;}
}

IntList::IntList(IntList&& L)
{ prim=NULL;
  Node *p=L.prim;
  while(p!=NULL)
    {AddLast(p->info); p=p->urm;}

  Node *q=L.prim;
  while(L.prim!=NULL)
    { q=L.prim;
      L.prim=(L.prim)->urm;
      delete q;
    }

}

IntList::~IntList()
{Node *p=prim;
 while(prim!=NULL)
    { p=prim;
      prim=prim->urm;
      delete p;
    }

}

IntList& IntList::operator=(const IntList& L)
{prim=NULL;
  Node *p=L.prim;
  while(p!=NULL)
    {AddLast(p->info); p=p->urm;}
  return *this;
}

IntList& IntList::Concatenare(const IntList& L1, const IntList& L2)
{IntList L;
 Node *p;
 for(p=L1.prim; p!=0; p=p->urm)
    AddLast(p->info);
 for(p=L2.prim; p!=0; p=p->urm)
    AddLast(p->info);
 return L;
}

void IntList::AddFirst(int x)
{Node *p= new Node;
 p->info=x;
 p->urm=prim;
 prim=p;
}

void IntList::AddLast(int x)
{Node *p=new Node;
 p->info=x;
 p->urm=NULL;
 if(prim==NULL)
    prim=p;
 else
    {Node *q=prim;
     while(q->urm!=NULL) q=q->urm;
     q->urm=p;
    }

}

void IntList::AfisareLista()
{
    if(prim==0) cout<<"Lista vida";
    else
        {Node *p=prim;
         while(p!=NULL)
           {cout<<p->info<<" ";
            p=p->urm;
           }
        }
    cout<<"\n";
}




int main()
{   IntList L;
    L.AddFirst(3);
    L.AddFirst(2);
    L.AddFirst(1);
    L.AfisareLista();

    int a[]={1,2,3,4};
    IntList l(4,a);
    l.AfisareLista();

    IntList c(l);
    c.AfisareLista();

    IntList d;
    d=c;
    d.AfisareLista();

    IntList s;
    s.Concatenare(c,L);
    s.AfisareLista();

    return 0;
}
