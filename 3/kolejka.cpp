#include <bits/stdc++.h>
#include <stdexcept>
#include "kolejka.hpp"
using namespace std;

kolejka::kolejka(int rozm)
{
    this->pojemnosc = rozm;
    this->kol = new string[rozm];
    this->ile = 0;
    this->pocz = 0;
}

kolejka::kolejka() : kolejka(1) {}

kolejka::kolejka(initializer_list<string> lista)
{
    this->pojemnosc = lista.size();
    this->ile = lista.size();
    this->kol = new string[pojemnosc];
    this->pocz = 0;
    for (auto elem : lista)
    {
        kol[pocz] = elem;
        pocz++;
    }
}

kolejka::kolejka(const kolejka &k)
{ //konstruktor kopiujacy
    this->pojemnosc = k.pojemnosc;
    this->kol = new string[this->pojemnosc];
    for (int i = 0; i < pojemnosc; i++)
    {
        this->kol[i] = k.kol[i];
    }
    this->ile = k.ile;
    this->pocz = k.pocz;
}

kolejka::kolejka(kolejka &&k)
{ //konstruktor przenoszacy
    this->pojemnosc = k.pojemnosc;
    this->kol = new string[this->pojemnosc];
    for (int i = 0; i < pojemnosc; i++)
    {
        this->kol[i] = k.kol[i];
    }
    this->ile = k.ile;
    this->pocz = k.pocz;
}

kolejka &kolejka::operator=(const kolejka &k)
{ //przypisanie kopiujace
    if (&k == this)
        return *this;
    this->~kolejka();
    this->pojemnosc = k.pojemnosc;
    this->kol = new string[this->pojemnosc];
    for (int i = 0; i < pojemnosc; i++)
    {
        this->kol[i] = k.kol[i];
    }
    this->ile = k.ile;
    this->pocz = k.pocz;
    return *this;
}

kolejka &kolejka::operator=(kolejka &&k)
{ //przypisanie przenoszace
    if (&k == this)
        return *this;
    this->~kolejka();
    this->pojemnosc = k.pojemnosc;
    this->kol = new string[this->pojemnosc];
    for (int i = 0; i < pojemnosc; i++)
    {
        this->kol[i] = k.kol[i];
    }
    this->ile = k.ile;
    this->pocz = k.pocz;
    return *this;
}

kolejka::~kolejka()
{
    delete[] kol;
}

void kolejka::wloz(string s)
{
    if (ile == pojemnosc)
        throw range_error("kolejka jest pelna");

    kol[(pocz + ile) % pojemnosc] = s;
    ile++;
}

string kolejka::wyciagnij()
{
    if (ile == 0)
        throw range_error("kolejka jest pusta");

    string wyn = kol[pocz];
    pocz = (pocz + 1) % pojemnosc;
    ile--;

    return wyn;
}
string kolejka::naprzodzie()
{
    if (ile == 0)
        throw range_error("kolejka jest pusta");

    return kol[pocz];
}

int kolejka::rozmiar()
{
    return ile;
}

void kolejka::wypisz()
{
    cout << "kolejka to: ";
    for (int i = 0; i < ile; i++)
    {
        cout << kol[(pocz + i) % pojemnosc] << ", ";
    }
    cout << "\n";
}