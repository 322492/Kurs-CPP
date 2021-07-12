//Kamil Tasarz, 322492

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const vector<pair<int, string>> rzym = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

string bin2rzym(int x)
{
    string wynik = "";
    for (int i = 0; i < rzym.size(); i++)
    {
        if (x >= rzym[i].f)
        {
            wynik += rzym[i].s;
            x -= rzym[i].f;
            i--;
        }
    }

    return wynik;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        int x;
        try
        {
            x = stoi(argv[i]);
            if (x < 1 || x > 3999)
                clog << "blad: podana liczba jest spoza przedzialu [1, 3999]\n";
            else
                cout << bin2rzym(x) << "\n";
        }
        catch (exception &e)
        {
            clog << "blad: podano nieprawidlowy argument\n";
        }
    }

    return 0;
}