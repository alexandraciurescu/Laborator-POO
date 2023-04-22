#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class AgentieImobiliara;

class Locuinta
{ protected:
  char judet[21];
  char localitate[21];
  char strada[21];
  int an_constructie;
  double suprafata;
  int pret;
  int nr_camere;
  int nr_bai;
  public:
      Locuinta();
      Locuinta(char*cjudet, char*clocalitate, char*cstrada, int can_constructie,
               double csuprafata, int cpret, int cnr_camere, int cnr_bai);
      friend class AgentieImobiliara;

};

class OfertaVanzareApartament;

class Apartament:public Locuinta  ///apartamentul este o locuinta
{char bloc[10];
 char scara[5];
 int etaj;
 int nr_apartament;
 bool lift;
 public:
     Apartament();
     Apartament(char*cjudet, char*clocalitate, char*cstrada, int can_constructie,
               double csuprafata, int cpret, int cnr_camere, int cnr_bai,
               char* cbloc, char* cscara, int cetaj, int cnr_apartament, bool clift);
     Apartament(const Apartament& A);

     void Afisare();
     void Citire();
     Apartament& operator=(Apartament A);

     friend class OfertaVanzareApartament;

};

class Casa:public Locuinta ///casa este o locuinta
{char numar[5];
 int nr_etaje;
 double suprafata_teren;
 public:
     Casa();
     Casa(char*cjudet, char*clocalitate, char*cstrada, int can_constructie,
               double csuprafata, int cpret, int cnr_camere, int cnr_bai, char*cnumar,
               int cnr_etaje, double csuprafata_teren);
     void Afisare();
     void Citire();
};


class OfertaVanzareApartament
{char proprietar[21];
  char telefon[11];
  Apartament A;
  public:
      OfertaVanzareApartament();
      void Afisare();
      void Citire();

      friend class AgentieImobiliara;

};

class OfertaVanzareCasa
{char proprietar[21];
 char telefon[11];
 Casa C;
 public:
     OfertaVanzareCasa();
     void Afisare();
     void Citire();

     friend class AgentieImobiliara;
};

class CerereCumparare
{char client[21];
 char telefon[11];
 char judet[21];
 char localitate[21];
 int nr_camere;
 int suprafata;
 char tip_imobil; ///'c' pentru casa si 'a' pentru apartament
 public:
     CerereCumparare();
     void Afisare();
     void Citire();

     void setClient(char s[]){strcpy(client,s);}
     void setTelefon(char s[]){strcpy(telefon,s);}
     void setJudet(char s[]){strcpy(judet,s);}
     void setLocalitate(char s[]){strcpy(localitate,s);}
     void setNrCamere(int s) {nr_camere=s;}
     void setSuprafata(int s) {suprafata=s;}
     void setTipImobil(char s) {tip_imobil=s;}

     char* getClient(){return client;}
     char* getTelefon(){return telefon;}
     char* getJudet() {return judet;}
     char* getLocalitate(){return localitate;}
     int getNrCamere() {return nr_camere;}
     int getSuprafata() {return suprafata;}
     char getTipImobil(){return tip_imobil;}

     friend class AgentieImobiliara;

};

class AgentieImobiliara
{ OfertaVanzareApartament *vapart;
  int nr_apart;
  OfertaVanzareCasa *vcase;
  int nr_case;
  CerereCumparare *vcereri;
  int nr_cereri;

  public:
      AgentieImobiliara();
      AgentieImobiliara(const AgentieImobiliara& A);
      AgentieImobiliara(AgentieImobiliara&& A);
      ~AgentieImobiliara();

      OfertaVanzareApartament* getOVA(){return vapart;}
      OfertaVanzareCasa* getOVC(){return vcase;}
      CerereCumparare* getCC(){return vcereri;}
      int getNrOVA(){return nr_apart;}
      int getNrOVC(){return nr_case;}
      int getNrCC(){return nr_cereri;}

      void setOVA(OfertaVanzareApartament* p) {vapart=p;}
      void setOVC(OfertaVanzareCasa* p) {vcase=p;}
      void setOCC(CerereCumparare* p) {vcereri=p;}
      void setNrOVA(int x) {nr_apart=x;}
      void setNrOVC(int x) {nr_case=x;}
      void setNrCC(int x) {nr_cereri=x;}


      void AdaugareOVA();
      void AfisareApartamente();

      void AdaugareOVC();
      void AfisareCase();

      void AdaugareCC();
      void AfisareCereri();

      void OfertePtCerere();
      void OfertePretMaxS();

      void ProfitTotal();

      AgentieImobiliara& operator=(AgentieImobiliara& A);
      AgentieImobiliara& operator=(AgentieImobiliara&& A);



};


///-----------------------clasa Locuinta---------------------------------

Locuinta::Locuinta()
{ strcpy(judet,"");
  strcpy(localitate,"");
  strcpy(strada,"");
  an_constructie=0;
  suprafata=0;
  pret=0;
  nr_camere=1;
  nr_bai=1;
}

Locuinta::Locuinta(char*cjudet, char*clocalitate, char*cstrada, int can_constructie,
               double csuprafata, int cpret, int cnr_camere, int cnr_bai)
{strcpy(judet,cjudet);
  strcpy(localitate,clocalitate);
  strcpy(strada,cstrada);
  an_constructie=can_constructie;
  suprafata=csuprafata;
  pret=cpret;
  nr_camere=cnr_camere;
  nr_bai=cnr_bai;
}




///--------------------clasa Apartament--------------------------------------

Apartament::Apartament()
{strcpy(bloc,"");
 strcpy(scara,"");
 etaj=0;
 nr_apartament=0;
 lift=0;
}

Apartament::Apartament(const Apartament& A)
{strcpy(judet,A.judet);
 strcpy(localitate,A.localitate);
 strcpy(strada,A.strada);
 an_constructie=A.an_constructie;
 suprafata=A.suprafata;
 pret=A.pret;
 nr_camere=A.nr_camere;
 nr_bai=A.nr_bai;
 strcpy(bloc,A.bloc);
 strcpy(scara,A.scara);
 etaj=A.etaj;
 nr_apartament=A.nr_apartament;
 lift=A.lift;
}

void Apartament::Afisare()
{cout<<"Judet: "<<judet<<"\n";
 cout<<"Localitate: "<<localitate<<"\n";
 cout<<"Strada: "<<strada<<"\n";
 cout<<"An constructie: "<<an_constructie<<"\n";
 cout<<"Suprafata: "<<suprafata<<"\n";
 cout<<"Pret: "<<pret<<"\n";
 cout<<"Numar camere: "<<nr_camere<<"\n";
 cout<<"Numar bai: "<<nr_bai<<"\n";
 cout<<"Bloc: "<<bloc<<"\n";
 cout<<"Scara: "<<scara<<"\n";
 cout<<"Etaj: "<<etaj<<"\n";
 cout<<"Numar apartament: "<<nr_apartament<<"\n";
 cout<<"Lift: "<<lift<<"\n";
}

void Apartament::Citire()
{cout<<"Judet: "; cin>>judet;
 cout<<"Localitate: "; cin>>localitate;
 cout<<"Strada: "; cin>>strada;
 cout<<"An constructie: "; cin>>an_constructie;
 cout<<"Suprafata: "; cin>>suprafata;
 cout<<"Pret: "; cin>>pret;
 cout<<"Numar camere: "; cin>>nr_camere;
 cout<<"Numar bai: "; cin>>nr_bai;
 cout<<"Bloc: "; cin>>bloc;
 cout<<"Scara: "; cin>>scara;
 cout<<"Etaj: "; cin>>etaj;
 cout<<"Numar apartament: "; cin>>nr_apartament;
 cout<<"Lift: "; cin>>lift;

}

Apartament& Apartament::operator=(Apartament A)
{strcpy(judet,A.judet);
 strcpy(localitate,A.localitate);
 strcpy(strada,A.strada);
 an_constructie=A.an_constructie;
 suprafata=A.suprafata;
 pret=A.pret;
 nr_camere=A.nr_camere;
 nr_bai=A.nr_bai;
 strcpy(bloc,A.bloc);
 strcpy(scara,A.scara);
 etaj=A.etaj;
 nr_apartament=A.nr_apartament;
 lift=A.lift;
 return *this;
}

Apartament::Apartament(char*cjudet, char*clocalitate, char*cstrada, int can_constructie,
               double csuprafata, int cpret, int cnr_camere, int cnr_bai,char*cbloc,
               char* cscara, int cetaj, int cnr_apartament, bool clift):Locuinta(cjudet,
                    clocalitate,cstrada,can_constructie, csuprafata, cpret, cnr_camere,cnr_bai)
{strcpy(bloc,cbloc);
 strcpy(scara,cscara);
 etaj=cetaj;
 nr_apartament=cnr_apartament;
 lift=clift;
}





///-----------------------clasa Casa-----------------------------------------

Casa::Casa()
{strcpy(numar,"");
 nr_etaje=0;
 suprafata_teren=0;
}

Casa::Casa(char*cjudet, char*clocalitate, char*cstrada, int can_constructie,
               double csuprafata, int cpret, int cnr_camere, int cnr_bai, char*cnumar,
               int cnr_etaje, double csuprafata_teren):Locuinta(cjudet,
                    clocalitate,cstrada,can_constructie, csuprafata, cpret, cnr_camere,cnr_bai)
{strcpy(numar,cnumar);
 nr_etaje=cnr_etaje;
 suprafata_teren=csuprafata_teren;
}

void Casa::Afisare()
{cout<<"Judet: "<<judet<<"\n";
 cout<<"Localitate: "<<localitate<<"\n";
 cout<<"Strada: "<<strada<<"\n";
 cout<<"An constructie: "<<an_constructie<<"\n";
 cout<<"Suprafata: "<<suprafata<<"\n";
 cout<<"Pret: "<<pret<<"\n";
 cout<<"Numar camere: "<<nr_camere<<"\n";
 cout<<"Numar bai: "<<nr_bai<<"\n";
 cout<<"Numar: "<<numar<<"\n";
 cout<<"Numar etaje: "<<nr_etaje<<"\n";
 cout<<"Suprafata teren: "<<suprafata_teren<<"\n";
}

void Casa::Citire()
{cout<<"Judet: "; cin>>judet;
 cout<<"Localitate: "; cin>>localitate;
 cout<<"Strada: "; cin>>strada;
 cout<<"An constructie: "; cin>>an_constructie;
 cout<<"Suprafata: "; cin>>suprafata;
 cout<<"Pret: "; cin>>pret;
 cout<<"Numar camere: "; cin>>nr_camere;
 cout<<"Numar bai: "; cin>>nr_bai;
 cout<<"Numar: "; cin>>numar;
 cout<<"Numar etaje: "; cin>>nr_etaje;
 cout<<"Suprafata teren: "; cin>>suprafata_teren;
}



///---------------------clasa OfertaVanzareApartament-----------------------

OfertaVanzareApartament::OfertaVanzareApartament()
{strcpy(proprietar,"Ciurescu");
 strcpy(telefon,"07");
}

void OfertaVanzareApartament::Afisare()
{ cout<<"Proprietar: "<<proprietar<<"\n";
  cout<<"Telefon: "<<telefon<<"\n";
  A.Afisare();
}

void OfertaVanzareApartament::Citire()
{cout<<"Proprietar: "; cin>>proprietar;
 cout<<"Telefon: "; cin>>telefon;
 A.Citire();

}
///-------------------clasa OfertaVanzareCasa-----------------------------
OfertaVanzareCasa::OfertaVanzareCasa()
{strcpy(proprietar,"");
 strcpy(telefon,"");
}

void OfertaVanzareCasa::Afisare()
{ cout<<"Proprietar: "<<proprietar<<"\n";
  cout<<"Telefon: "<<telefon<<"\n";
  C.Afisare();
}

void OfertaVanzareCasa::Citire()
{cout<<"Proprietar: "; cin>>proprietar;
 cout<<"Telefon: "; cin>>telefon;
 C.Citire();
}

///------------------------------clasa CerereCumparare-----------------------------
CerereCumparare::CerereCumparare()
{strcpy(client,"");
 strcpy(telefon,"");
 strcpy(judet,"");
 strcpy(localitate,"");
 nr_camere=0;
 suprafata=0;
 tip_imobil=0;
}

void CerereCumparare::Afisare()
{cout<<"Client: "<<client<<"\n";
 cout<<"Telefon: "<<telefon<<"\n";
 cout<<"Judet: "<<judet<<"\n";
 cout<<"Localitate: "<<localitate<<"\n";
 cout<<"Numar camere: "<<nr_camere<<"\n";
 cout<<"Suprafata: "<<suprafata<<"\n";
 cout<<"Tip imobil: "<<tip_imobil<<"\n";
}

void CerereCumparare::Citire()
{cout<<"Client: "; cin>>client;
 cout<<"Telefon: "; cin>>telefon;
 cout<<"Judet: "; cin>>judet;
 cout<<"Localitate: "; cin>>localitate;
 cout<<"Numar camere: "; cin>>nr_camere;
 cout<<"Suprafata: "; cin>>suprafata;
 cout<<"Tip imobil(c pentru casa, a pentru apartament): "; cin>>tip_imobil;
}

istream& operator>>(istream& in,CerereCumparare& C)
{char client[21],telefon[11],judet[21],localitate[21];
 int nr_camere,suprafata;
 char tip_imobil;
 cout<<"Client: "; in>>client;
 cout<<"Telefon: "; in>>telefon;
 cout<<"Judet: "; in>>judet;
 cout<<"Localitate: "; in>>localitate;
 cout<<"Numar camere: "; in>>nr_camere;
 cout<<"Suprafata: "; in>>suprafata;
 cout<<"Tip imobil(c pentru casa, a pentru apartament): "; in>>tip_imobil;

 C.setClient(client);
 C.setTelefon(telefon);
 C.setJudet(judet);
 C.setLocalitate(localitate);
 C.setNrCamere(nr_camere);
 C.setSuprafata(suprafata);
 C.setTipImobil(tip_imobil);

 return in;
}

ostream& operator<<(ostream& out,CerereCumparare&C)
{out<<"Client: "<<C.getClient()<<"\n";
 out<<"Telefon: "<<C.getTelefon()<<"\n";
 out<<"Judet: "<<C.getJudet()<<"\n";
 out<<"Localitate: "<<C.getLocalitate()<<"\n";
 out<<"Numar camere: "<<C.getNrCamere()<<"\n";
 out<<"Suprafata: "<<C.getSuprafata()<<"\n";
 out<<"Tip imobil: "<<C.getTipImobil()<<"\n";

 return out;

}

///----------------------clasa AgentieImobiliara------------------------

AgentieImobiliara::AgentieImobiliara()
{ vapart=NULL;
  vcase=NULL;
  vcereri=NULL;
  nr_apart=nr_case=nr_cereri=0;
}

AgentieImobiliara::AgentieImobiliara(const AgentieImobiliara& A)
{nr_apart=A.nr_apart;
 nr_case=A.nr_case;
 nr_cereri=A.nr_cereri;
 vapart=new OfertaVanzareApartament[nr_apart];
 vcase=new OfertaVanzareCasa[nr_case];
 vcereri=new CerereCumparare[nr_cereri];
 for(int i=0; i<nr_apart; i++)
    vapart[i]=A.vapart[i];
 for(int i=0; i<nr_case; i++)
    vcase[i]=A.vcase[i];
 for(int i=0; i<nr_cereri; i++)
    vcereri[i]=A.vcereri[i];


}

AgentieImobiliara::AgentieImobiliara(AgentieImobiliara&& A)
{nr_apart=A.nr_apart;
 nr_case=A.nr_case;
 nr_cereri=A.nr_cereri;
 vapart=new OfertaVanzareApartament[nr_apart];
 vcase=new OfertaVanzareCasa[nr_case];
 vcereri=new CerereCumparare[nr_cereri];
 for(int i=0; i<nr_apart; i++)
    vapart[i]=A.vapart[i];
 for(int i=0; i<nr_case; i++)
    vcase[i]=A.vcase[i];
 for(int i=0; i<nr_cereri; i++)
    vcereri[i]=A.vcereri[i];
 if(A.nr_apart!=0) {delete[] A.vapart; A.nr_apart=0;}
 if(A.nr_case!=0) {delete[] A.vcase; A.nr_case=0;}
 if(A.nr_cereri!=0) {delete[] A.vcereri; A.nr_cereri=0;}
}

AgentieImobiliara::~AgentieImobiliara()
{ if(nr_apart!=0) {delete[] vapart; nr_apart=0;}
  if(nr_case!=0) {delete[] vcase; nr_case=0;}
  if(nr_cereri!=0) {delete[] vcereri; nr_cereri=0;}
}

void AgentieImobiliara::AdaugareOVA()
{OfertaVanzareApartament A;
 A.Citire();
 OfertaVanzareApartament* a=new OfertaVanzareApartament[nr_apart+1];
 for(int i=0; i<nr_apart; i++)
    a[i]=vapart[i];
 nr_apart++;
 a[nr_apart-1]=A;
 if(nr_apart!=0) delete[] vapart;
 vapart=a;
}

void AgentieImobiliara::AfisareApartamente()
{cout<<"\n"<<"LISTA APARTAMENTELOR DISPONIBILE\n";
 for(int i=0; i<nr_apart; i++)
   {vapart[i].Afisare(); cout<<"\n";}
}


void AgentieImobiliara::AdaugareOVC()
{OfertaVanzareCasa A;
 A.Citire();
 OfertaVanzareCasa* a=new OfertaVanzareCasa[nr_case+1];
 for(int i=0; i<nr_case; i++)
    a[i]=vcase[i];
 nr_case++;
 a[nr_case-1]=A;
 if(nr_case!=0) delete[] vcase;
 vcase=a;
}

void AgentieImobiliara::AfisareCase()
{cout<<"\nLISTA CASELOR DISPONIBILE\n";
 for(int i=0; i<nr_case; i++)
   {vcase[i].Afisare(); cout<<"\n";}
}

void AgentieImobiliara::AdaugareCC()
{CerereCumparare A;
 cin>>A;
 CerereCumparare* a=new CerereCumparare[nr_cereri+1];
 for(int i=0; i<nr_cereri; i++)
    a[i]=vcereri[i];
 nr_cereri++;
 a[nr_cereri-1]=A;
 if(nr_cereri!=0) delete[] vcereri;
 vcereri=a;
}

void AgentieImobiliara::AfisareCereri()
{cout<<"\nLISTA CERERILOR DISPONIBILE\n";
 for(int i=0; i<nr_cereri; i++)
   {cout<<vcereri[i]; cout<<"\n";}
}

void AgentieImobiliara::OfertePtCerere()
{ char nume[21];
  char tel[11];
  cout<<"Nume client: "; cin>>nume;
  cout<<"Telefon client: "; cin>>tel;

  int p=-1;
  for(int i=0; i<nr_cereri; i++)
    if(strcmp(nume,vcereri[i].getClient())==0 && strcmp(tel,vcereri[i].getTelefon())==0)
       {p=i;
        break;
       }
  if(p==-1) {cout<<"Nu exista cereri pentru datele introduse\n"; return;}
  if(vcereri[p].getTipImobil()=='a')
       {cout<<"Lista apartamente disponibile:\n";
        for(int i=0; i<nr_apart; i++)
            if(strcmp(vapart[i].A.judet,vcereri[p].getJudet())==0 &&
               strcmp(vapart[i].A.localitate,vcereri[p].getLocalitate())==0&&
               vapart[i].A.nr_camere==vcereri[p].getNrCamere() &&
               abs(vapart[i].A.suprafata-vcereri[p].getSuprafata())<10)
               vapart[i].A.Afisare();
       }
  else
       {cout<<"Lista case disponibile:\n";
        for(int i=0; i<nr_case; i++)
            if(strcmp(vcase[i].C.judet,vcereri[p].getJudet())==0 &&
               strcmp(vcase[i].C.localitate,vcereri[p].getLocalitate())==0&&
               vcase[i].C.nr_camere==vcereri[p].getNrCamere() &&
               abs(vcase[i].C.suprafata-vcereri[p].getSuprafata())<10)
               vcase[i].C.Afisare();
       }
}

void AgentieImobiliara::OfertePretMaxS()
{int S;
 cout<<"De ce suma de bani dispuneti?"; cin>>S;
 cout<<"/nApartamente disponibile:\n";
 for(int i=0; i<nr_apart; i++)
    if(vapart[i].A.pret<=S)
     vapart[i].A.Afisare();
 cout<<"/nCase disponibile:\n";
 for(int i=0; i<nr_case; i++)
    if(vcase[i].C.pret<=S)
     vcase[i].C.Afisare();
}

void AgentieImobiliara::ProfitTotal()
{double profit=0;
 int i;
 for(i=0; i<nr_apart; i++)
    profit=profit+0.03*vapart[i].A.pret;
 for(i=0; i<nr_case; i++)
    profit=profit+0.03*vcase[i].C.pret;
 cout<<"\nProfitul agentiei daca vinde toate proprietatile este: "<<profit<<"\n";
}

AgentieImobiliara& AgentieImobiliara::operator=(AgentieImobiliara& A)
{nr_apart=A.nr_apart;
 nr_case=A.nr_case;
 nr_cereri=A.nr_cereri;
 vapart=new OfertaVanzareApartament[nr_apart];
 vcase=new OfertaVanzareCasa[nr_case];
 vcereri=new CerereCumparare[nr_cereri];
 for(int i=0; i<nr_apart; i++)
    vapart[i]=A.vapart[i];
 for(int i=0; i<nr_case; i++)
    vcase[i]=A.vcase[i];
 for(int i=0; i<nr_cereri; i++)
    vcereri[i]=A.vcereri[i];
 return *this;
}

AgentieImobiliara& AgentieImobiliara::operator=(AgentieImobiliara&& A)
{if(this!=&A)
  {nr_apart=A.nr_apart;
  nr_case=A.nr_case;
  nr_cereri=A.nr_cereri;
  vapart=new OfertaVanzareApartament[nr_apart];
  vcase=new OfertaVanzareCasa[nr_case];
  vcereri=new CerereCumparare[nr_cereri];
  for(int i=0; i<nr_apart; i++)
     vapart[i]=A.vapart[i];
  for(int i=0; i<nr_case; i++)
     vcase[i]=A.vcase[i];
  for(int i=0; i<nr_cereri; i++)
     vcereri[i]=A.vcereri[i];
   }
 if(A.nr_apart!=0) {delete[] A.vapart; A.nr_apart=0;}
 if(A.nr_case!=0) {delete[] A.vcase; A.nr_case=0;}
 if(A.nr_cereri!=0) {delete[] A.vcereri; A.nr_cereri=0;}
 return *this;
}


int main()
{  AgentieImobiliara A;
  int opt;
  char ch;
  do
   {cout<<"1. Adaugare Oferta Apartament\n";
    cout<<"2. Adaugare Oferta Casa\n";
    cout<<"3. Adaugare Cerere Cumparare\n\n";
    cout<<"4. Afisare Apartamente\n";
    cout<<"5. Afisare Case\n";
    cout<<"6. Afisare Cereri Cumparare\n\n";
    cout<<"7. Afisare Oferte pentru cererea ....\n";
    cout<<"8. Ce se poate cumpara cu maxim S lei?\n";
    cout<<"9. Care este profitul total al agentiei?\n\n";
    cout<<"10. Iesire\n\n";

    cout<<"Alegeti o optiune: "; cin>>opt;

    switch (opt)
       { case 1: A.AdaugareOVA(); break;
         case 2: A.AdaugareOVC(); break;
         case 3: A.AdaugareCC(); break;
         case 4: A.AfisareApartamente(); break;
         case 5: A.AfisareCase(); break;
         case 6: A.AfisareCereri(); break;
         case 7: A.OfertePtCerere(); break;
         case 8: A.OfertePretMaxS(); break;
         case 9: A.ProfitTotal(); break;
         default: break;
       }
      if(opt!=10) { cout<<"Apasati tasta 'c' pentru a continua...."; cin>>ch;}
    }
    while(opt<10);


    return 0;
}
