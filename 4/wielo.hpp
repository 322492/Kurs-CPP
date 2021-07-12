//Kamil Tasarz, 322492

#include <bits/stdc++.h>
using namespace std;

class wielomian
{
private:
    int n;     // stopień wielomianu
    double *a; // współczynniki wielomianu

public:
    wielomian(int st = 0, double wsp = 1.0);  // konstruktor jednomianu
    wielomian(int st, const double wsp[]);    // konstruktor wielomianu
    wielomian(initializer_list<double> wsp);   // lista współczynników
    wielomian(const wielomian &w);            // konstruktor kopijący
    wielomian(wielomian &&w);                 // konstruktor przenoszący
    wielomian &operator=(const wielomian &w); // przypisanie kopijące
    wielomian &operator=(wielomian &&w);      // przypisanie przenoszące
    ~wielomian();                             // destruktor

    friend istream &operator>>(istream &we, wielomian &w);
    friend ostream &operator<<(ostream &wy, const wielomian &w);

    friend wielomian operator+(const wielomian &u, const wielomian &v);
    friend wielomian operator-(const wielomian &u, const wielomian &v);
    friend wielomian operator*(const wielomian &u, const wielomian &v);
    friend wielomian operator*(const wielomian &w, double c);
    friend wielomian operator*(double c, const wielomian &w);
    wielomian &operator+=(const wielomian &v);
    wielomian &operator-=(const wielomian &v);
    wielomian &operator*=(const wielomian &v);
    wielomian &operator*=(double c);
    double operator()(double x) const; // wartość wielomianu dla x
    double operator[](int i) const;    // odczytanie i-tego współczynnika
};
