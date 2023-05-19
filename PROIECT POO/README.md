# Agentia imobiliara Vaslui
## Evidenta unei agentii imobiliare
### Clasele utilizate:

1. Locuinta 
2. Apartament
3. Casa
4. OfertaVanzareApartament
5. OfertaVanzareCasa
6. CerereCumparare
7. AgentieImobiliara
8. Persoana
9. Competente
10. Angajat
11. Calcul Taxe
12. Reducere
13. Factura
14. Computer
15. Masina
16. ObiecteInventar
17. DateAgentie

**Clasa Locuinta**
 - pentru memorarea caracteristicilor de baza ale unei locuinte(judet,localitate,strada,an constructie, suprafata, pret, numar camere, numar bai); 
 - este clasa de baza pentru clasele Apartament si Casa care o mostenesc.

**Clasa Apartament**
 - completeaza caracteristicile unei locuinte cu cele specifice unui apartament (bloc, scara, etaj, numar apartament, existenta liftului);

**Clasa Casa**
 - completeaza caracteristicile unei locuinte cu cele specifice unei case (numar, numar etaje, suprafata teren)

**Clasa OfertaVanzareApartament**
 - pentru memorarea unei oferte pentru un apartament;
 - memoreaza: proprietarul, numarul de telefon, apartamentul scos la vanzare.

**Clasa OfertaVanzareCasa**
 - pentru memorarea unei oferte pentru o casa;
 - memoreaza: proprietarul, numarul de telefon, apartamentul scos la vanzare.

**Clasa CerereCumparare**
 - pentru memorarea unei cereri de cumparare a unei proprietati;
 - memoreaza: client, numar de telefon, judet, localitate, numar camere, suprafata, tip imobil.

**Clasa AgentieImobiliara**
 - pentru memorarea datelor necesare functionarii unei agentii imobiliare;
 - date membre: cate un vector alocat dinamic pentru apartamente, case, cereri, angajati, facturi, dar si numarul de elemente al fiecaruia.

**Clasa Persoana**
 - pentru memorarea datelor unei persoane
 - date membre: nume, prenume, cnp, adresa

**Clasa Competente**
 - pentru memorarea ultimei scoli absolvite de un angajat
 - date membre: numele scolii, nivel studii (superioare, liceale, gimnaziale)

**Clasa Angajat**
 - un angajat este o persoana cu anumite studii (clasa mosteneste clasele Persoane, Competente)
 - date membre: salariu, functie, data_angajare

**Clasa CalculTaxe**
  - interfata

**Clasa Reducere**
  - clasa abstracte

**Clasa Factura**
  - mosteneste clasele CalculTaxe si Reducere
  - date membre: nr_factura, suma

**Clasa Computer**
  -  pentru memorarea calculatoarelor din gestiunea firmei

**Clasa Masina**
  - pentru memorarea masinilor din gestiunea firmei 

**Clasa ObiecteInventar**
 - clasa template

**Clasa DateAgentie**
 - clasa singleton
 - memoreaza datele de contact ale agentiei(nume, adresa, telefon, email)

 ## Functionalitati - etapa 1
   - capabila sa citeasca si sa retina o lista de apartamente, o lista de case, o lista de cereri
   - poate afisa ofertele disponibile pentru o anumita cerere
   - poate afisa casele si apartamentele care pot fi cumparate cu o anumita suma de bani
   - poate afisa profitul total al agentiei, dupa vanzarea tututor proprietatilor din portofoliu

## Functionalitati - etapa 2

### Mostenire
**1. Definiti minim doua ierarhii diferite de mostenire:** 
  - clasa Locuinta din care deriva clasele Apartament si Casa
  - clasa Angajat mosteneste clasele Persoana si Competente
  - clasa Factura mosteneste clasele CalculTaxe si Reducere

**2. Utilizati minim doi modificatori de acces diferiti pe clasa care se mosteneste (public/protected/private)**
  - class Angajat: protected Persoana, public Competente
  - class Factura: public CalculTaxe, public Reducere
  - class Apartament: public Locuinta
  - class Casa: public Locuinta

**3. Minim o clasa care sa foloseasca mostenire multipla**
  - class Angajat: protected Persoana, public Competente
  - class Factura: public CalculTaxe, public Reducere

**4. Apelati cel putin o data un constructor (cu parametri) dintr-o clasa de baza, folosind o lista de initializare in constructorul clasei copil.**
  - constructorii cu parametrii din clasele Apartament, Casa, Angajat

**5. Minim doua date membru si minim o metoda care sa aiba modificatorul de acces protected**
 - datele membru ale claselor Locuinta, Persoana,  Competente, Reducere, au modificatorul de acces protected (sunt clase de baza pentru alte clase derivate)
 - metoda get_dnastere() a clasei Persoana are modificatorul de acces protected

 
### Interfete si metode virtuale
**1. Definiti si extindeti (mosteniti) minim o interfata (clasa fara date membru, doar metode pur virtuale si un destructor virtual) care sa aiba minim doua metode** 
- interfata: clasa CalculTaxe care are care are 2 metode pur virtuale si un destructor virtual
- clasa CalculTaxe este mostenita de clasa Factura

**2. Definiti si extindeti (mosteniti) minim o clasa de baza abstracta (clasa care poate avea date membru, dar are cel putin o metoda pur virtuala)**
- clasa de baza abstracta: clasa Reducere ce are o metoda pur virtuala
- clasa abstracat Reducere este clasa de baza pentru clasa derivata Factura

**3. Cel putin o situatie in care sa fie nevoie de si sa se apeleze destructorul virtual**
  - destructorul clasei AgentieImobiliara

**4. Definiti cel putin 2 metode virtuale care sa fie suprascrise in clasele mostenitoare**
  - metodele virtuale tva() si taxenotarile() din clasa de baza CalculTaxe sunt suprascrise in clasa mostenitoare Factura
  - metoda virtuala pret_redus() din clasa de baza Reducere este suprascrisa in clasa mostenitoare Factura

### Polimorfism la executie
**1. Identificati minim 2 locuri in care sa aiba loc polimorfism la executie (dynamic dispatch) in proiectul vostru (e.g. apelul unor metode virtuale prin intermediul unor pointeri/referinte catre clasa de baza).**
- functia void AfisareTaxeNotariale(CalculTaxe &T) apelata de metoda AfisareTaxe() a clasei AgentieImobiliara
  (se apeleaza pentru obiecte de tip Factura, clasa mostenitoare a clasei CalculTaxe)

**2. Identificati minim 2 instante de upcasting in codul vostru**
- in functia TestUpcasting()

**3. Realizarea downcasting-ului in cel putin o situatie**
- in functia TestDowncasting()

### Exceptii
**1. Definiti minim un tip de exceptie custom, care sa extinda clasa exception din biblioteca standard.**
- clasa MyException cu metoda what()

**2. Aruncati exceptii in minim 2 functii/metode diferite (folositi tipuri de exceptii definite de voi sau cele din biblioteca standard).**
- in constructorul de copiere al clasei AgentieImobiliara (bad_alloc)
- functia TestMyException()

**3. Implementati minim un bloc try...catch care sa prinda o exceptie aruncata de voi (cu mentiunea explicita a tipului acesteia) si sa o trateze intr-un fel (in functie de specificul erorii).**
- in functia main, la meniu daca se citeste un numar natural mai mare decat ultima optiune (iesire fortata daca optiunea nu exista)

**4. Implementati minim un bloc try...catch care sa prinda o exceptie, sa o proceseze si sa re-arunce un alt tip de exceptie din blocul catch.**
- in metoda main, la meniu, daca se citeste un numar real pentru optiune (eroare numar real) vom prelua doar partea intreaga si o aruncam in excpetia pentru numar intreg

### Variabile si metode statice
**1. Definiti o variabila membru statica in cel putin o clasa**
- variabila Count in clasa Angajat

**2. Implementati cel putin doua metode statice in clasele voastre**
- functiile statice AfisareNrAngajati() si ResetareNrAngajati() din clasa Angajat


## Functionalitati - etapa 3

### Programare generica
**1. Utilizati minim o clasa sablon (template) definita de voi. Trebuie sa fie parametrizata de cel putin un tip de date generic (cel putin un typename), care sa fie folosit in mod util in interiorul clasei (e.g. pentru a defini un atribut, o metoda etc.).**
- clasa sablon ObiecteInventar pentru memorarea obiectelor de inventar ale agentiei (calculatoare si masini) 
- clasa este parametrizata de un tip generic T (am folosit clasele Computer si Masina)

**2. Definiti si apelati minim o functie sablon (poate fi functie libera sau metoda a unei clase care nu este neaparat generica). Trebuie sa fie parametrizata de cel putin un tip de date generic (cel putin un typename), care sa fie folosit in definirea functiei (e.g. parametru, tip de date returnat).**
- functia libera maxim

**3. Definiti cel putin o implementare specializata pentru clasa sablon sau functia sablon (nu neaparat pentru ambele).**
- -FUNCTIE SABLON SPECIALIZATA maxim - pentru clasa Computer compararea se va face dupa nr_inventar, nu dupa pret

### Design patterns
**1. Identificati minim 2 object-oriented design patterns diferite in clasele implementate de voi.**
- clasa Singleton DateAgentie (se poate declara un singur obiect de tip DateAgentie)

### Biblioteca standard
**1. Utilizarea a minim doua tipuri de date container diferite din STL**
- clasa vector in clase template ObiecteInventar
- clasa string in clasele Computer, Masina, Persoana, Competente...

**2. Utilizarea a minim doua functii utilitare diferite din biblioteca standard (functii libere, nu metode).**
- functia utilitara **sort** in clasa ObiecteInventar in cadrul metodei SortareObiecte
- functia utilitara **max_element** care este apelata de metoda ObiectPretMaxim din clasa ObiecteInventar 






