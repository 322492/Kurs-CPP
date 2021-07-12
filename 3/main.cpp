#include <bits/stdc++.h>
#include "kolejka.hpp"

using namespace std;

void menu()
{
    cout << "wybierz: \n";
    cout << "1 - aby wstawic elemnt do kolejki\n2 - aby usunac element z kolejki\n3 - aby zapytac o ilosc elementow w kolejce\n4 - zapytac o pojemnosc kolejki\n5 - wypisac kolejke\n6 - zakonczyc program\n7 - jesli chcesz ponownie wyswietlic menu\n";
    return;
}

int main()
{
    cout << "Witaj w symulatorze kolejki napisanym przez Kamila Tasarza. \nWciśnij dowolna cyfre, aby uruchomić program. \nWybieraj polecenia z listy i baw sie dobrze!\n";

    char co;
    string el;
    cin >> co;
    kolejka k = kolejka(100); //domyslna pojemnosc tutaj to 100;
    menu();

    while (co != '6')
    {
        cin >> co;
        switch (co)
        {
        case '1':
            cout << "podaj element typu napis: ";
            cin >> el;
            cout << "wlozono do kolejki " << el << "\n";
            k.wloz(el);
            break;
        case '2':
            cout << "wyciagniety element: " << k.wyciagnij() << "\n";
            break;
        case '3':
            cout << "ilosc elementow w kolejce: " << k.rozmiar() << "\n";
            break;
        case '4':
            cout << "pojemnosc kolejki to: 100\n";
            break;
        case '5':
            k.wypisz();
            break;
        case '7':
            menu();
            break;
        }
    }

    cout << "W takim razie konczymy\nDo zobaczenia!\n";

    return 0;
}