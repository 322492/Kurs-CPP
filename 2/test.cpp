#include <bits/stdc++.h>
#include "figury.hpp"

using namespace std;

int main()
{

    punkt a = punkt(2.0, 4.0);
    punkt b = punkt(1.0, 17.0);
    punkt e1 = punkt(1.0, 0.0);
    punkt e2 = punkt(0.0, 1.0);
    punkt c = a;
    punkt zero = punkt();

    odcinek A = odcinek(a, b);
    odcinek B = A;

    //trojkat T0 = trojkat(a, a, b);
    trojkat T1 = trojkat(a, b, zero);
    trojkat T2 = trojkat(zero, e1, e2);

    //trojkaty
    cout << "wspolrzedne T1: (" << T1.wsp_a().wsp_x() << "; " << T1.wsp_a().wsp_y() << "), (" << T1.wsp_b().wsp_x() << "; " << T1.wsp_b().wsp_y() << "), (" << T1.wsp_c().wsp_x() << "; " << T1.wsp_c().wsp_y() << ")\n";
    cout << "srodek T1: (" << T1.srodek().wsp_x() << ", " << T1.srodek().wsp_y() << ")\n";
    cout << "pole T1: " << T1.pole() << "\n";
    cout << "obwod T1: " << T1.obwod() << "\n";
    cout << "czy e1 jest w T1: " << T1.czy_w_srodku(e1) << "\n";

    cout << "wspolrzedne T2: (" << T2.wsp_a().wsp_x() << "; " << T2.wsp_a().wsp_y() << "), (" << T2.wsp_b().wsp_x() << "; " << T2.wsp_b().wsp_y() << "), (" << T2.wsp_c().wsp_x() << "; " << T2.wsp_c().wsp_y() << ")\n";
    T2.obrot(zero, M_PI / 2);
    cout << "wspolrzedne T2 po obrocie wokol zera o pi/2: (" << T2.wsp_a().wsp_x() << "; " << T2.wsp_a().wsp_y() << "), (" << T2.wsp_b().wsp_x() << "; " << T2.wsp_b().wsp_y() << "), (" << T2.wsp_c().wsp_x() << "; " << T2.wsp_c().wsp_y() << ")\n";
    T2.przesun(0.0, 2.0);
    cout << "wspolrzedne T2 po przesunieciu o [0, 2]: (" << T2.wsp_a().wsp_x() << "; " << T2.wsp_a().wsp_y() << "), (" << T2.wsp_b().wsp_x() << "; " << T2.wsp_b().wsp_y() << "), (" << T2.wsp_c().wsp_x() << "; " << T2.wsp_c().wsp_y() << ")\n";
    cout << "\n";

    //odcinki
    cout << "wspolrzedne odcinka B: (" << B.wsp_a().wsp_x() << "; " << B.wsp_a().wsp_y() << "), (" << B.wsp_b().wsp_x() << "; " << B.wsp_b().wsp_y() << ") \n";
    B.przesun(e1.wsp_x(), e1.wsp_y());
    cout << "wspolrzedne odcinka B po przesunieciu o e1: (" << B.wsp_a().wsp_x() << "; " << B.wsp_a().wsp_y() << "), (" << B.wsp_b().wsp_x() << "; " << B.wsp_b().wsp_y() << ") \n";

    cout << "wspolrzedne odcinka A: (" << A.wsp_a().wsp_x() << "; " << A.wsp_a().wsp_y() << "), (" << A.wsp_b().wsp_x() << "; " << A.wsp_b().wsp_y() << ") \n";
    cout << "srodek odcinka A: (" << A.srodek().wsp_x() << "; " << A.srodek().wsp_y() << ") \n";
    cout << "dlugosc odcinka A: " << A.dlugosc() << "\n";
    cout << "\n";

    //punkty
    cout << "odleglosc miedzy e1 i e2: " << e1.odleglosc(e2) << "\n";
    e2.obrot(e1, -M_PI);
    cout << "obrocony e2 wzgledem e1 o pi: (" << e2.wsp_x() << "; " << e2.wsp_y() << ") \n";
    e1.przesun_x(17.0);
    cout << "przesuniecie e1 o [17, 0]: (" << e1.wsp_x() << "; " << e1.wsp_y() << ") \n";

    return 0;
}