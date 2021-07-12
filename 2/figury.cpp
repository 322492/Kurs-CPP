#include <bits/stdc++.h>
#include <math.h>
#include "figury.hpp"
#include <stdexcept>

using namespace std;

double odleglosc(punkt a, punkt b)
{
    double dx = a.wsp_x() - b.wsp_x();
    double dy = a.wsp_y() - b.wsp_y();
    return sqrt(dx * dx + dy * dy);
}
punkt::punkt()
{
    this->x = 0, this->y = 0;
}
punkt::punkt(double a, double b)
{
    this->x = a, this->y = b;
}
punkt::punkt(const punkt &p) //konstruktor kopiujacy punkt
{
    memcpy(this, &p, sizeof(punkt));
}
punkt &punkt::operator=(const punkt &p) //przypisanie kopiujace
{
    memcpy(this, &p, sizeof(punkt));
    return *this;
}
void punkt::obrot(punkt p, double kat) //obrot wokol punkt p o kat podany w radianach
{
    double xn, yn;
    xn = yn = 0.0;
    xn = p.wsp_x() + (this->x - p.wsp_x()) * cos(kat) - (this->y - p.wsp_y()) * sin(kat);
    yn = p.wsp_y() + (this->x - p.wsp_x()) * sin(kat) + (this->y - p.wsp_y()) * cos(kat);
    this->x = xn;
    this->y = yn;
}
void punkt::przesun_x(double dx)
{
    this->x += dx;
}
void punkt::przesun_y(double dy)
{
    this->y += dy;
}
double punkt::odleglosc(punkt p)
{
    double dx = this->x - p.wsp_x();
    double dy = this->y - p.wsp_y();
    return sqrt(dx * dx + dy * dy);
}
double punkt::wsp_x() { return this->x; }
double punkt::wsp_y() { return this->y; }

odcinek::odcinek(punkt a, punkt b)
{
    if (a.wsp_x() == b.wsp_x() && a.wsp_y() == b.wsp_y())
        throw invalid_argument("nie można utworzyć odcinka o długości 0");

    this->a = a;
    this->b = b;
}
odcinek::odcinek(const odcinek &pp) //konstruktor kopiujacy punkt
{
    memcpy(this, &pp, sizeof(odcinek));
}
odcinek &odcinek::operator=(const odcinek &p) //przypisanie kopiujace
{
    memcpy(this, &p, sizeof(odcinek));
    return *this;
}
void odcinek::przesun(double dx, double dy)
{
    this->a.przesun_x(dx);
    this->a.przesun_y(dy);
    this->b.przesun_x(dx);
    this->b.przesun_y(dy);
}
void odcinek::obrot(punkt p, double kat)
{
    this->a.obrot(p, kat);
    this->b.obrot(p, kat);
}
punkt odcinek::srodek()
{
    punkt s = punkt();
    s.przesun_x((this->a.wsp_x() + this->b.wsp_x()) / 2.0);
    s.przesun_y((this->a.wsp_y() + this->b.wsp_y()) / 2.0);
    return s;
}
punkt odcinek::wsp_a()
{
    return this->a;
}
punkt odcinek::wsp_b()
{
    return this->b;
}
double odcinek::dlugosc()
{
    return this->a.odleglosc(this->b);
}
double trojkat::pole()
{
    double P = ((this->b.wsp_x() - this->a.wsp_x()) * (this->c.wsp_y() - this->a.wsp_y()) - (this->c.wsp_x() - this->a.wsp_x()) * (this->b.wsp_y() - this->a.wsp_y())) / 2.0;
    return abs(P);
}
double area(punkt a, punkt b, punkt c)
{
    double P = ((b.wsp_x() - a.wsp_x()) * (c.wsp_y() - a.wsp_y()) - (c.wsp_x() - a.wsp_x()) * (b.wsp_y() - a.wsp_y())) / 2.0;
    return abs(P);
}
double trojkat::obwod()
{
    return this->a.odleglosc(this->b) + this->b.odleglosc(this->c) + this->c.odleglosc(this->a);
}
punkt trojkat::srodek()
{
    punkt s = punkt();
    s.przesun_x((this->a.wsp_x() + this->b.wsp_x() + this->c.wsp_x()) / 3.0);
    s.przesun_y((this->a.wsp_y() + this->b.wsp_y() + this->c.wsp_y()) / 3.0);
    return s;
}
bool trojkat::czy_w_srodku(punkt p)
{
    double P = area(this->a, this->b, this->c);
    double p1 = area(p, this->b, this->c);
    double p2 = area(this->a, p, this->c);
    double p3 = area(this->a, this->b, p);
    if (P == p1 + p2 + p3)
        return true;
    return false;
}
bool czy_rozlaczne(trojkat A, trojkat B)
{
    if (A.czy_w_srodku(B.wsp_a()) || A.czy_w_srodku(B.wsp_b()) || A.czy_w_srodku(B.wsp_c()) || B.czy_w_srodku(A.wsp_a()) || B.czy_w_srodku(A.wsp_b()) || B.czy_w_srodku(A.wsp_c()))
        return false;
    return true;
}
bool czy_zawiera(trojkat A, trojkat B)
{
    if ((A.czy_w_srodku(B.wsp_a()) && A.czy_w_srodku(B.wsp_b()) && A.czy_w_srodku(B.wsp_c())) || (B.czy_w_srodku(A.wsp_a()) && B.czy_w_srodku(A.wsp_b()) && B.czy_w_srodku(A.wsp_c())))
        return true;
    return false;
}
trojkat::trojkat(punkt a, punkt b, punkt c)
{
    double P = area(a, b, c);
    if (P == 0)
        throw invalid_argument("nie można utworzyć trojkata o polu 0");

    this->a = a;
    this->b = b;
    this->c = c;
}
trojkat::trojkat(const trojkat &t) //konstruktor kopiujacy punkt
{
    memcpy(this, &t, sizeof(odcinek));
}
trojkat &trojkat::operator=(const trojkat &p) //przypisanie kopiujace
{
    memcpy(this, &p, sizeof(trojkat));
    return *this;
}
void trojkat::przesun(double dx, double dy)
{
    this->a.przesun_x(dx);
    this->a.przesun_y(dy);
    this->b.przesun_x(dx);
    this->b.przesun_y(dy);
    this->c.przesun_x(dx);
    this->c.przesun_y(dy);
}
void trojkat::obrot(punkt p, double kat)
{
    this->a.obrot(p, kat);
    this->b.obrot(p, kat);
    this->c.obrot(p, kat);
}
punkt trojkat::wsp_a()
{
    return this->a;
}
punkt trojkat::wsp_b()
{
    return this->b;
}
punkt trojkat::wsp_c()
{
    return this->c;
}
