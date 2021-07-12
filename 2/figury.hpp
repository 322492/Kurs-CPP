#include <bits/stdc++.h>

class punkt
{
private:
    double x, y;

public:
    punkt();
    punkt(double a, double b);
    punkt(const punkt &p); //konstruktor kopiujacy
    punkt& operator=(const punkt& p); //przypisanie kopiujace
    void obrot(punkt p, double kat);
    void przesun_x(double dx);
    void przesun_y(double dy);
    double wsp_x();
    double wsp_y();
    double odleglosc(punkt p);
};

class odcinek
{
private:
    punkt a, b;

public:
    odcinek(punkt a, punkt b);
    odcinek(const odcinek &pp); //konstruktor kopiujacy
    odcinek& operator=(const odcinek& pp); //przypisanie kopiujace
    void przesun(double dx, double dy);
    void obrot(punkt p, double kat);
    punkt wsp_a();
    punkt wsp_b();
    punkt srodek();
    double dlugosc();
};

class trojkat
{
private:
    punkt a, b, c;

public:
    trojkat(punkt a, punkt b, punkt c);
    trojkat(const trojkat &t); //konstruktor kopiujacy
    trojkat& operator=(const trojkat& p); //przypisanie kopiujace
    void przesun(double dx, double dy);
    void obrot(punkt p, double kat);
    punkt wsp_a();
    punkt wsp_b();
    punkt wsp_c();
    double pole();
    double obwod();
    punkt srodek();
    bool czy_w_srodku(punkt p);
};

double odleglosc(punkt a, punkt b);