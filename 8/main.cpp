#include <bits/stdc++.h>
#include "wymierne.hpp"

using namespace obliczenia;

int main()
{
    try
    {
        wymierna w1(1, 3);
        wymierna w2(-4, -8);
        wymierna w3(1077, 1079);

        std::cout << w1 << " " << w2 << " " << w3 << "\n";

        std::cout << w1 + w2 << " " << w3 + w2 << " " << w2 * w2 << " " << -w1 << " " << !w2 << "\n";

        std::cout << (int)(w1 + w2) << " " << (int)w1 << " " << (double)(w2 * w2) << " " << (int)-w1 << " " << (int)!w2 << "\n";

        wymierna w0(0, 7);
        wymierna w00(0);

        std::cout << w0 << " " << w00 << "\n";
        wymierna blad = !w0;
        wymierna duza1 = (123456789, 1);
        wymierna duza2 = (9876543210, 1);

        std::cout << duza1 * duza2 << "\n";
    }
    catch (dzielenie_przez_0 e)
    {
        std::cout << "\nERROR: " << e.what() << "\n";
    }
    catch (przekroczenie_zakresu e)
    {
        std::cout << "\nERROR: " << e.what() << "\n";
    }

    return 0;
}