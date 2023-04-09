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

Clasa Locuinta
 - pentru memorarea caracteristicilor de baza ale unei locuinte(judet,localitate,strada,an constructie, suprafata, pret, numar camere, numar bai); 
 - este clasa de baza pentru clasele Apartament si Casa care o mostenesc.

Clasa Apartament
 - completeaza caracteristicile unei locuinte cu cele specifice unui apartament (bloc, scara, etaj, numar apartament, existenta liftului);

Clasa Casa
 - completeaza caracteristicile unei locuinte cu cele specifice unei case (numar, numar etaje, suprafata teren)

Clasa OfertaVanzareApartament
 - pentru memorarea unei oferte pentru un apartament;
 - memoreaza: proprietarul, numarul de telefon, apartamentul scos la vanzare.

 Clasa OfertaVanzareCasa
 - pentru memorarea unei oferte pentru o casa;
 - memoreaza: proprietarul, numarul de telefon, apartamentul scos la vanzare.

 Clasa CerereCumparare
 - pentru memorarea unei cereri de cumparare a unei proprietati;
 - memoreaza: client, numar de telefon, judet, localitate, numar camere, suprafata, tip imobil.

 Clasa AgentieImobiliara
 - pentru memorarea datelor necesare functionarii unei agentii imobiliare;
 - date membre: cate un vector alocat dinamic pentru apartamente, case, respectiv cereri, dar si numarul de elemente al fiecaruia.

 ### Functionalitati
   - capabila sa citeasca si sa retina o lista de apartamente, o lista de case, o lista de cereri
   - poate afisa ofertele disponibile pentru o anumita cerere
   - poate afisa casele si apartamentele care pot fi cumparate cu o anumita suma de bani
   - poate afisa profitul total al agentiei, dupa vanzarea tututor proprietatilor din portofoliu
