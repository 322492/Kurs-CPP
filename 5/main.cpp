//Kamil Tasarz, 322492

#include <bits/stdc++.h>
#include "wyrazenia.hpp"
using namespace std;

int main()
{
    wyrazenie *t0 = new odejmij(
        new pi(),
        new dodaj(
            new liczba(2),
            new mnoz(
                new zmienna("x"),
                new liczba(7))));

    cout << "wzór T0: pi-(2+x*7)\n"
         << t0->zapis() << "\n";

    zmienna::dodaj_zmienna("x", -2.0 / 7.0);
    cout << "T0(-2/7) = " << t0->oblicz() << "\n\n";

    // ((x-1)*x)/2
    wyrazenie *t1 = new dziel(new mnoz(new odejmij(new zmienna("x"), new liczba(1)), new zmienna("x")), new liczba(2));

    //(3+5)/(2+x*7)
    wyrazenie *t2 = new dziel(new dodaj(new liczba(3), new liczba(5)), new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7))));

    //2+x*7-(y*3+5)
    wyrazenie *t3 = new odejmij(new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7))), new dodaj(new mnoz(new zmienna("y"), new liczba(3)), new liczba(5)));

    //cos((x+1)*x)/e^x^2
    wyrazenie *t4 = new dziel(new Cos(new mnoz(new dodaj(new zmienna("x"), new liczba(1)), new zmienna("x"))), new Exp(new potega(new zmienna("x"), new liczba(2))));

    cout << "wzór: ((x-1)*x)/2\n"
         << t1->zapis() << "\n";
    cout << "wzór: (3+5)/(2+x*7)\n"
         << t2->zapis() << "\n";
    cout << "wzór:2+x*7-(y*3+5)\n"
         << t3->zapis() << "\n";
    cout << "wzór: cos((x+1)*x)/e^x^2\n"
         << t4->zapis() << "\n";

    zmienna::dodaj_zmienna("y", 1.0); //w tescie 3. pojawia sie zmienna y

    cout << "\ntest1:\n";
    for (double i = 0.0; i <= 1.0; i += 0.1)
    {
        zmienna::dodaj_zmienna("x", i);
        cout << t1->oblicz() << "\n";
    }
    cout << "\ntest2:\n";
    for (double i = 0.0; i <= 1.0; i += 0.1)
    {
        zmienna::dodaj_zmienna("x", i);
        cout << t2->oblicz() << "\n";
    }
    cout << "\ntest3:\n";
    for (double i = 0.0; i <= 1.0; i += 0.1)
    {
        zmienna::dodaj_zmienna("x", i);
        cout << t3->oblicz() << "\n";
    }
    cout << "\ntest4:\n";
    for (double i = 0.0; i <= 1.0; i += 0.1)
    {
        zmienna::dodaj_zmienna("x", i);
        cout << t4->oblicz() << "\n";
    }

    //testy pozostalych klas:
    cout << "\nRózne testy:\n";
    wyrazenie *t = new Sin(new bezwgl(new mnoz(new liczba(-1), new pi())));
    cout << "sin(|(-1)*pi|)\n"
         << t->zapis() << " = " << t->oblicz() << "\n";

    wyrazenie *tt = new przeciw(new mnoz(new e(), new fi()));
    cout << "przeciw(e*fi)\n"
         << tt->zapis() << " = " << tt->oblicz() << "\n";

    wyrazenie *ttt = new ln(new potega(new e(), new modulo(new liczba(99), new liczba(101))));
    cout << "ln(e^(99 mod 101))\n"
         << ttt->zapis() << " = " << ttt->oblicz() << "\n";

    wyrazenie *tttt = new odwrot(new logarytm(new liczba(2), new liczba(4)));
    cout << "(log_(2)(4))^(-1)\n"
         << tttt->zapis() << " = " << tttt->oblicz() << "\n";

    return 0;
}