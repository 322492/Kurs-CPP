#include <bits/stdc++.h>
#include <stdexcept>
#include "wymierne.hpp"

// Uzywam funckji gcd i lcm, ktore sa w standardzie od c++17

namespace obliczenia
{
    wymierna::wymierna(int licznik, int mianownik) throw(dzielenie_przez_0, przekroczenie_zakresu)
    {
        if (mianownik == 0)
        {
            throw dzielenie_przez_0();
        }
        if ((licznik < 0 && mianownik < 0) || (licznik > 0 && mianownik < 0))
        {
            licznik *= -1;
            mianownik *= -1;
        }
        if (mianownik < 0)
            throw przekroczenie_zakresu();
        int d = std::gcd(licznik, mianownik);
        licz = licznik / d;
        mian = mianownik / d;
    }

    wymierna::wymierna(int licznik)
    {
        licz = licznik;
        mian = 1;
    }

    int wymierna::mianownik()
    {
        return mian;
    }

    int wymierna::licznik()
    {
        return licz;
    }

    wymierna operator+(const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu)
    {
        int LCM = std::lcm(w1.mian, w2.mian);
        int licznik1 = w1.licz * (LCM / w1.mian);
        int licznik2 = w2.licz * (LCM / w2.mian);
        if (licznik2 < 0 && licznik1 < INT_MIN - licznik2)
        {
            throw przekroczenie_zakresu();
        }
        if (licznik2 > 0 && licznik1 > INT_MAX - licznik2)
        {
            throw przekroczenie_zakresu();
        }
        return wymierna(licznik1 + licznik2, LCM);
    }

    wymierna operator-(const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu)
    {
        int LCM = std::lcm(w1.mian, w2.mian);
        int licznik1 = w1.licz * (LCM / w1.mian);
        int licznik2 = w2.licz * (LCM / w2.mian);
        if (licznik2 < 0 && licznik1 > INT_MAX + licznik2)
        {
            throw przekroczenie_zakresu();
        }
        if (licznik2 > 0 && licznik1 < INT_MIN + licznik2)
        {
            throw przekroczenie_zakresu();
        }
        return wymierna(licznik1 - licznik2, LCM);
    }

    wymierna operator*(const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu)
    {
        int d1 = std::gcd(w1.mian, w2.licz);
        int d2 = std::gcd(w2.mian, w1.licz);
        wymierna pom1(w1.licz / d2, w1.mian / d1);
        wymierna pom2(w2.licz / d1, w2.mian / d2);

        if (pom1.licz > INT_MAX / pom2.licz)
            throw przekroczenie_zakresu();
        if (pom1.mian > INT_MAX / pom2.mian)
            throw przekroczenie_zakresu();

        return wymierna(pom1.licz * pom2.licz, pom1.mian * pom2.mian);
    }

    wymierna operator/(const wymierna &w1, const wymierna &w2) throw(dzielenie_przez_0, przekroczenie_zakresu)
    {
        if (w2.licz == 0)
            throw dzielenie_przez_0();
        return w1 * (!w2);
    }

    wymierna operator-(const wymierna &w) throw(przekroczenie_zakresu) //zmiana znaku
    {
        if (w.licz == INT_MIN)
            throw przekroczenie_zakresu();
        return wymierna(-1 * w.licz, w.mian);
    }

    wymierna operator!(const wymierna &w) throw(dzielenie_przez_0) //odwrotnosc ulamka
    {
        if (w.licz == 0)
            throw dzielenie_przez_0();
        return wymierna(w.mian, w.licz);
    }

    wymierna::operator double()
    {
        return (double)licz / (double)mian;
    }

    wymierna::operator int()
    {
        return int(licz / mian);
    }

    std::ostream &operator<<(std::ostream &wy, const wymierna &w)
    {
        wy << (double)w.licz / w.mian;
        return wy;
    }
}