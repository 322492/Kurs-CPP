//Kamil Tasarz, 322492

#include <bits/stdc++.h>
#include <math.h>
#include <stdexcept>
#include "wyrazenia.hpp"
using namespace std;

liczba::liczba(double a)
{
    this->a = a;
}

double liczba::oblicz()
{
    return a;
}

string liczba::zapis()
{
    return to_string(a);
}

int liczba::priorytet(){
    return 1;
}

int stala::priorytet(){
    return 1;
}

pi::pi()
{
}

double pi::oblicz()
{
    return M_PI;
}

string pi::zapis()
{
    return "pi";
}

e::e()
{
}

double e::oblicz()
{
    return M_E;
}

string e::zapis()
{
    return "e";
}

fi::fi()
{
}

double fi::oblicz()
{
    return 1.618033988749895;
}

string fi::zapis()
{
    return "fi";
}

vector<pair<string, double>> zmienna::zmienne;

zmienna::zmienna(string z)
{
    this->z = z;
}

double zmienna::oblicz()
{
    for (int i = 0; i < zmienne.size(); i++)
    {
        if (zmienne[i].first == z)
            return zmienne[i].second;
    }

    throw invalid_argument("Brak zmiennej w zbiorze zmiennych!");
}

string zmienna::zapis()
{
    return z;
}

int zmienna::priorytet(){
    return 1;
}

void zmienna::dodaj_zmienna(string n, double x)
{
    for (int i = 0; i < zmienne.size(); i++)
    {
        if (zmienne[i].first == n)
        {
            zmienne[i].second = x;
            // cout << "nadpisano zmienną " + n; //mozna odkomentowac, gdyby chacialo sie otrzymywac taki komunikat
            return;
        }
    }

    zmienne.push_back({n, x});
}

void zmienna::usun_zmienna(string n)
{
    for (auto it = zmienne.begin(); it != zmienne.end(); it++)
    {
        if ((*it).first == n)
        {
            it = zmienne.erase(it);
            return;
        }
    }
}

//operator1arg

int operator1arg::priorytet(){
    return 3;
}

Sin::Sin(wyrazenie *w)
{
    this->w = w;
}

double Sin::oblicz()
{
    return std::sin(w->oblicz());
}

string Sin::zapis()
{
    return "sin(" + w->zapis() + ")";
}

Cos::Cos(wyrazenie *w)
{
    this->w = w;
}

double Cos::oblicz()
{
    return std::cos(w->oblicz());
}

string Cos::zapis()
{
    return "cos(" + w->zapis() + ")";
}

Exp::Exp(wyrazenie *w)
{
    this->w = w;
}

double Exp::oblicz()
{
    return std::exp(w->oblicz());
}

string Exp::zapis()
{
    return "exp(" + w->zapis() + ")";
}

ln::ln(wyrazenie *w)
{
    this->w = w;
}

double ln::oblicz()
{
    double liczba = w->oblicz();
    if (liczba <= 0.0)
        throw invalid_argument("Niedodatnia liczba logarytmowana!");
    else
        return std::log(liczba);
}

string ln::zapis()
{
    return "ln(" + w->zapis() + ")";
}

bezwgl::bezwgl(wyrazenie *w)
{
    this->w = w;
}

double bezwgl::oblicz()
{
    return std::abs(w->oblicz());
}

string bezwgl::zapis()
{
    return "|" + w->zapis() + "|";
}

przeciw::przeciw(wyrazenie *w)
{
    this->w = w;
}

double przeciw::oblicz()
{
    return -w->oblicz();
}

string przeciw::zapis()
{
    return "(-1)" + w->zapis();
}

odwrot::odwrot(wyrazenie *w)
{
    this->w = w;
}

double odwrot::oblicz()
{
    double p = w->oblicz();
    if (p == 0.0)
        throw invalid_argument("Nie istnieje liczba odwrotna do 0!");

    return 1.0 / p;
}

string odwrot::zapis()
{
    return "(" + w->zapis() + ")^(-1)";
}

//operator2arg

string operator2arg::zapis(string znak)
{
    //cout<<L->priorytet()<<" "<<this->priorytet()<<" "<<P->priorytet()<<"\n"; //tylko do testow
    if (L->priorytet() > this->priorytet() && P->priorytet() > this->priorytet())
        return "(" + L->zapis() + ")" + znak + "(" + P->zapis() + ")";
    else if (L->priorytet() > priorytet())
    {
        return "(" + L->zapis() + ")" + znak + P->zapis();
    }
    else if (P->priorytet() > priorytet())
    {
        return L->zapis() + znak + "(" + P->zapis() + ")";
    }
    else
        return L->zapis() + znak + P->zapis();
}

dodaj::dodaj(wyrazenie *wl, wyrazenie *wp)
{
    L = wl;
    P = wp;
}
double dodaj::oblicz()
{
    return L->oblicz() + P->oblicz();
}
string dodaj::zapis()
{
    return operator2arg::zapis("+");
}
int dodaj::priorytet(){
    return 10;
}

odejmij::odejmij(wyrazenie *wl, wyrazenie *wp)
{
    L = wl;
    P = wp;
}
double odejmij::oblicz()
{
    return L->oblicz() - P->oblicz();
}
string odejmij::zapis()
{
    return operator2arg::zapis("-");
}
int odejmij::priorytet(){
    return 9;
}

mnoz::mnoz(wyrazenie *wl, wyrazenie *wp)
{
    L = wl;
    P = wp;
}
double mnoz::oblicz()
{
    return L->oblicz() * P->oblicz();
}
string mnoz::zapis()
{
    return operator2arg::zapis("*");
}
int mnoz::priorytet(){
    return 7;
}

dziel::dziel(wyrazenie *wl, wyrazenie *wp)
{
    L = wl;
    P = wp;
}
double dziel::oblicz()
{
    double p = P->oblicz();
    if (p == 0.0)
        throw invalid_argument("Dzielenie przez 0!");
    else
        return L->oblicz() / P->oblicz();
}
string dziel::zapis()
{
    return operator2arg::zapis("/");
}

int dziel::priorytet(){
    return 6;
}

logarytm::logarytm(wyrazenie *podstawa, wyrazenie *liczba)
{
    L = podstawa;
    P = liczba;
}
double logarytm::oblicz()
{
    double podstawa = L->oblicz();
    double liczba = P->oblicz();
    if (podstawa <= 0.0 || podstawa == 1.0)
        throw invalid_argument("Niepoprawna podstawa logarytmu!");
    else if (liczba <= 0.0)
        throw invalid_argument("Niepoprawna liczba logarytmowana!");
    else
        return log(P->oblicz()) / log(L->oblicz());
}
string logarytm::zapis()
{
    return "log_(" + L->zapis() + ") (" + P->zapis() + ")";
}

int logarytm::priorytet(){
    return 3;
}

modulo::modulo(wyrazenie *liczba, wyrazenie *mod)
{
    L = liczba;
    P = mod;
}
double modulo::oblicz()
{
    //operacje modulo chce przeprowadzac tylko na liczbach calkowitych, tak jak jest to w C++
    int a = (int)L->oblicz();
    int b = (int)P->oblicz();
    if (b == 0)
        throw invalid_argument("Modulowanie przez 0!");
    else
        return (double)(a % b);
}
string modulo::zapis()
{
    return "(" + L->zapis() + " mod " + P->zapis() + ")";
}

int modulo::priorytet(){
    return 3;
}

potega::potega(wyrazenie *a, wyrazenie *b)
{
    L = a;
    P = b;
}
double potega::oblicz()
{
    return pow(L->oblicz(), P->oblicz());
}
string potega::zapis()
{
    return L->zapis() + "^" + P->zapis();
}

int potega::priorytet(){
    return 3;
}