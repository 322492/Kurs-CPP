//Kamil Tasarz, 322492

#include <bits/stdc++.h>
using namespace std;

class wyrazenie
{
public:
    wyrazenie() = default;
    virtual double oblicz() = 0;
    virtual string zapis() = 0;
    virtual int priorytet() = 0;

    //zablokowanie opcji kopiowania i przenoszenia wyrazen
    wyrazenie(const wyrazenie&) = delete;            // konstruktor kopijący
    wyrazenie(wyrazenie&&) = delete;                 // konstruktor przenoszący
    wyrazenie &operator=(const wyrazenie&) = delete; // przypisanie kopijące
    wyrazenie &operator=(wyrazenie&&) = delete;      // przypisanie przenoszące
};

/*
hierarchia priorytetów:
10. dodaj
9. odejmij
7. mnoz
6. dziel
3. logarytm, modulo, potega, operator1arg
1. liczba, stala, zmienna
*/

class liczba : public wyrazenie
{
private:
    double a;

public:
    liczba(double a);
    double oblicz();
    string zapis();
    int priorytet();
};

class stala : public wyrazenie
{
public:
    virtual double oblicz() = 0;
    virtual string zapis() = 0;
    int priorytet();
};

class pi : public stala
{
public:
    pi();
    double oblicz();
    string zapis();
};

class e : public stala
{
public:
    e();
    double oblicz();
    string zapis();
};

class fi : public stala
{
public:
    fi();
    double oblicz();
    string zapis();
};

class zmienna : public wyrazenie
{
private:
    string z;

protected:
    static vector<pair<string, double>> zmienne;

public:
    zmienna(string z);
    double oblicz();
    string zapis();
    int priorytet();

    static void dodaj_zmienna(string s, double x); //jesli zmienna o takiej nazwie juz istnieje to zostanie zmieniona jej wartosc, mozna tak tez modyfikowac zmienne
    static void usun_zmienna(string s);
};

//operator1arg

class operator1arg : public wyrazenie
{
protected:
    wyrazenie *w;

public:
    virtual double oblicz() = 0;
    virtual string zapis() = 0;
    int priorytet();
};

class Sin : public operator1arg
{
public:
    Sin(wyrazenie *w);
    double oblicz();
    string zapis();
};

class Cos : public operator1arg
{
public:
    Cos(wyrazenie *w);
    double oblicz();
    string zapis();
};

class Exp : public operator1arg
{
public:
    Exp(wyrazenie *w);
    double oblicz();
    string zapis();
};

class ln : public operator1arg
{
public:
    ln(wyrazenie *w);
    double oblicz();
    string zapis();
};

class bezwgl : public operator1arg
{
public:
    bezwgl(wyrazenie *w);
    double oblicz();
    string zapis();
};

class przeciw : public operator1arg
{
public:
    przeciw(wyrazenie *w);
    double oblicz();
    string zapis();
};

class odwrot : public operator1arg
{
public:
    odwrot(wyrazenie *w);
    double oblicz();
    string zapis();
};

//operator2arg

class operator2arg : public wyrazenie
{
private:
protected:
    wyrazenie *L, *P;

public:
    virtual double oblicz() = 0;
    string zapis() = 0;
    string zapis(string znak);
    virtual int priorytet() = 0;
};

class dodaj : public operator2arg
{
public:
    dodaj(wyrazenie *wl, wyrazenie *wp);
    double oblicz();
    string zapis();
    int priorytet();
};

class odejmij : public operator2arg
{
public:
    odejmij(wyrazenie *wl, wyrazenie *wp);
    double oblicz();
    string zapis();
    int priorytet();
};

class mnoz : public operator2arg
{
public:
    mnoz(wyrazenie *wl, wyrazenie *wp);
    double oblicz();
    string zapis();
    int priorytet();
};

class dziel : public operator2arg
{
public:
    dziel(wyrazenie *wl, wyrazenie *wp);
    double oblicz();
    string zapis();
    int priorytet();
};
class logarytm : public operator2arg
{
public:
    logarytm(wyrazenie *podstawa, wyrazenie *liczba);
    double oblicz();
    string zapis();
    int priorytet();
};

class modulo : public operator2arg
{
public:
    modulo(wyrazenie *liczba, wyrazenie *mod);
    double oblicz();
    string zapis();
    int priorytet();
};

class potega : public operator2arg
{
public:
    potega(wyrazenie *a, wyrazenie *b);
    double oblicz();
    string zapis();
    int priorytet();
};