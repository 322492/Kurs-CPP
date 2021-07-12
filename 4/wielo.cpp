//Kamil Tasarz, 322492

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdexcept>
#include "wielo.hpp"
using namespace std;

//wielomian::wielomian (int st=0, double wsp=1.0){}

wielomian::wielomian(int st, const double wsp[])
{
    if (st != 0 && wsp[st] == 0)
        throw invalid_argument("Niepoprawne wspolczynniki");
    this->n = st;
    this->a = new double[st + 1];
    copy(wsp, wsp + st + 1, a);
}

wielomian::wielomian(initializer_list<double> wsp)
{
    this->n = wsp.size() - 1;
    this->a = new double[wsp.size()];
    int i = 0;
    for (auto it = wsp.begin(); it != wsp.end(); ++it, i++)
    {
        a[i] = *it;
    }
    if (n != 0 && a[n] == 0)
        throw invalid_argument("Niepoprawne wspolczynniki");
    //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" LOL\n";
}

wielomian::wielomian(const wielomian &w)
{
    this->n = w.n;
    this->a = new double[n + 1];
    copy(w.a, w.a + n + 1, a);
    // cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " LOL\n";
}

wielomian::wielomian(wielomian &&w)
{
    this->n = w.n;
    this->a = new double[n + 1];
    copy(w.a, w.a + n + 1, a);
}

wielomian &wielomian::operator=(const wielomian &w)
{
    if (&w == this)
        return *this;
    this->~wielomian();
    this->n = w.n;
    this->a = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = w.a[i];
    }
    //cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " LOL\n";
    return *this;
}

wielomian &wielomian::operator=(wielomian &&w)
{
    if (&w == this)
        return *this;
    this->~wielomian();
    this->n = w.n;
    this->a = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = w.a[i];
    }

    return *this;
}

wielomian::~wielomian()
{
    delete[] a;
}

istream &operator>>(istream &we, wielomian &w)
{
    w.~wielomian();
    cout << "Stopień wielomianu to: ";
    we >> w.n;
    w.a = new double[w.n + 1];
    for (int i = 0; i <= w.n; i++)
        we >> w.a[i];

    if (w.n != 0 && w.a[w.n] == 0)
        throw invalid_argument("Niepoprawne wspolczynniki");
    return we;
}

ostream &operator<<(ostream &wy, const wielomian &w)
{
    for (int i = w.n; i > 0; i--)
    {
        if (w.a[i] == 1) //nie chce wypisywac wspolczynnika 1
            wy << "x^" << i << " + ";
        else if (w.a[i] == -1) //nie chce wypisywac wspolczynnika -1
            wy << "-x^" << i << " + ";
        else if (w.a[i] != 0) //nie chce wypisywac potęgi z zerowym wspolczynnikiem
            wy << w.a[i] << "x^" << i << " + ";
    }

    wy << w.a[0];
    return wy;
}

wielomian operator+(const wielomian &u, const wielomian &v)
{
    if (u.n >= v.n)
    {
        wielomian wyn = u;
        for (int i = v.n; i >= 0; i--)
        {
            wyn.a[i] += v.a[i];
        }
        while (wyn.a[wyn.n] == 0 && wyn.n > 0)
            wyn.n--;
        return wyn;
    }
    else
    {
        wielomian wyn = v;
        for (int i = u.n; i >= 0; i--)
        {
            wyn.a[i] += u.a[i];
        }
        while (wyn.a[wyn.n] == 0 && wyn.n > 0)
            wyn.n--;
        return wyn;
    }
}

wielomian operator-(const wielomian &u, const wielomian &v)
{
    if (u.n >= v.n)
    {
        wielomian wyn = u;
        for (int i = v.n; i >= 0; i--)
        {
            wyn.a[i] -= v.a[i];
        }
        while (wyn.a[wyn.n] == 0 && wyn.n > 0)
            wyn.n--;
        return wyn;
    }
    else
    {
        wielomian wyn = v;
        for (int i = u.n; i >= 0; i--)
        {
            wyn.a[i] -= u.a[i];
        }
        while (wyn.a[wyn.n] == 0 && wyn.n > 0)
            wyn.n--;
        return wyn;
    }
}

wielomian operator*(const wielomian &u, const wielomian &v)
{
    double wsp[u.n + v.n + 1] = {0};
    for (int i = 0; i <= u.n; i++)
    {
        for (int j = 0; j <= v.n; j++)
        {
            wsp[i + j] += u.a[i] * v.a[j];
        }
    }
    wielomian wyn = wielomian(u.n + v.n, wsp);
    return wyn;
}

wielomian operator*(const wielomian &w, double c)
{
    wielomian wyn = w;
    for (int i = 0; i <= w.n; i++)
        wyn.a[i] *= c;
    while (wyn.a[wyn.n] == 0 && wyn.n > 0)
        wyn.n--;
    return wyn;
}

wielomian operator*(double c, const wielomian &w)
{
    return w * c;
}

wielomian &wielomian::operator+=(const wielomian &v)
{
    int N = max(n, v.n);
    double *t = new double[N + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i] = a[i];
    }
    for (int i = 0; i <= v.n; i++)
    {
        t[i] += v.a[i];
    }
    *this = wielomian(N, t);
    delete[] t;
    return *this;
}

wielomian &wielomian::operator-=(const wielomian &v)
{
    int N = max(n, v.n);
    double *t = new double[N + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i] = a[i];
    }
    for (int i = 0; i <= v.n; i++)
    {
        t[i] -= v.a[i];
    }
    *this = wielomian(N, t);
    delete[] t;
    while (a[n] == 0 && n > 0)
        n--;
    return *this;
}

wielomian &wielomian::operator*=(const wielomian &v)
{
    int N = n + v.n;
    double *t = new double[N + 1];
    for (int i = 0; i <= N; i++)
    {
        t[i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= v.n; j++)
        {
            t[i + j] += a[i] * v.a[j];
        }
    }
    *this = wielomian(N, t);
    delete[] t;
    return *this;
}

wielomian &wielomian::operator*=(double c)
{
    for (int i = 0; i <= n; i++)
        a[i] *= c;
    while (a[n] == 0 && n > 0)
        n--;
    return *this;
}

double wielomian::operator()(double x) const
{
    double w = 0;
    for (int i = 0; i <= n; i++)
        w += pow(x, i);
    return w;
}

double wielomian::operator[](int i) const
{
    return a[i];
}