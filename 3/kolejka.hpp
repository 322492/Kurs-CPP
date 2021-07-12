#include <bits/stdc++.h>
using namespace std;

class kolejka
{
private:
    int ile;
    int pojemnosc;
    int pocz;
    string *kol;

public:
    kolejka(int rozm);
    kolejka();
    kolejka(initializer_list<string> lista);
    kolejka(const kolejka &k); //konstrukotr kopiujacy
    kolejka(kolejka &&); //konstrukotr przenoszacy
    kolejka& operator=(const kolejka & k); //przypisanie kopiujace
    kolejka& operator=(kolejka && k); //przypisanie przenoszace
    ~kolejka();
    void wloz(string s);
    string wyciagnij();
    string naprzodzie();
    int rozmiar();

    //pomocnicze, sluzace do obslugi uzytkownika
    void wypisz();

};