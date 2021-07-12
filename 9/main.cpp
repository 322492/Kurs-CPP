#include <bits/stdc++.h>
#include "lista.hpp"

using namespace calc;

void menu()
{
  std::cout << "wybierz: \n";
  std::cout << "1 - aby wstawic element do listy\n2 - aby usunac element z listy\n3 - aby zapytac o ilosc elementow w liscie\n4 - wypisac liste\n5 - sprawdzic czy lista jest posortowana\n6 - posortowac liste\n7 - zakonczyc program\n8 - jesli chcesz ponownie wyswietlic menu\n";
  return;
}

int main()
{

  /* //luzne testy do mozliwego odkomentowania sprawdzajace wiecej metod
  list<int> A;
  std::cout << A.is_empty() << "\n";
  for (int i = 0; i <= 10; i++)
  {
    A.insert(i);
  }
  std::cout << A << "\n";
  A.remove(6);
  A.insert(15);
  std::cout << A << "\n";
  std::cout << A.is_empty() << " " << A.is_in(7) << " " << A.is_in(42) << "\n";
  list<int> B = A;
  for (int i = 0; i <= 10; i++)
  {
    A.insert_at(3, 2);
  }
  list<int> C = {0, 1, 1, 1, 1, 4, 9, 9, 5, 6, 9, 8, 7, 9, 1, 2, 2, 2, 2};
  list<int> D = {2, 0, 1, 8, 8, 8, 1, 9, 5, -3, 9, 8, 87, 9, 1, 88, 0, 17, 12};

  std::cout << A << "\n"
            << B << "\n"
            << C << "\n"
            << D << "\n";

  std::cout << D.issorted() << " " << A.issorted() << "\n";
  D.sort();
  std::cout << D << "\n"
            << D.issorted() << "\n";

  C.remove(9);
  C.remove(9);
  C.remove(1);
  C.remove(2);
  std::cout << C;
  return 0; 
  */

  //wlasciwy main
  std::cout << "Witaj w interaktywnym programie testującym działanie listy jednokierunkowej napisanym przez Kamila Tasarza. \nWciśnij dowolny klawisz, aby uruchomić program. \nWybieraj polecenia z listy i testuj do woli!\n";

  char co;
  int typ;
  std::cin >> co;
  std::cout << "Jakiego typu ma być Twoja lista?\n1. int\n2. char\n3. string\n";
  std::cin >> typ;

  if (typ == 2) //lista charow
  {
    char el;
    auto lista = new list<char>();
    std::cout << "Utworzono listę charów\n";
    menu();
    while (co != '7')
    {
      std::cin >> co;
      if (co == '7')
        break;
      switch (co)
      {
      case '1':
        std::cout << "podaj element typu char: ";
        std::cin >> el;
        std::cout << "wlozono do listy " << el << "\n";
        lista->insert(el);
        break;
      case '2':
        std::cout << "podaj element typu char: ";
        std::cin >> el;
        lista->remove(el);
        std::cout << "wyciagnieto element: " << el << "\n";
        break;
      case '3':
        std::cout << "ilosc elementow w liscie: " << lista->size() << "\n";
        break;
      case '4':
        std::cout << "Twoja lista to: " << *lista << "\n";
        break;
      case '5':
        if (lista->issorted())
          std::cout << "Twoja lista jest posortowana\n";
        else
          std::cout << "Twoja lista NIE jest posortowana\n";
        break;
      case '6':
        lista->sort();
        std::cout << "Twoja lista zostala posortowana\n";
        break;
      case '8':
        menu();
        break;
      }
    }
    delete lista;
  }
  else if (typ == 3) //lista stringow (calosc prawie taka sama jak wyzej)
  {
    std::string el;
    auto lista = new list<std::string>();
    std::cout << "Utworzono listę stringów\n";
    menu();
    while (co != '7')
    {
      std::cin >> co;
      if (co == '7')
        break;
      switch (co)
      {
      case '1':
        std::cout << "podaj element typu string: ";
        std::cin >> el;
        std::cout << "wlozono do listy " << el << "\n";
        lista->insert(el);
        break;
      case '2':
        std::cout << "podaj element typu string: ";
        std::cin >> el;
        lista->remove(el);
        std::cout << "wyciagnieto element: " << el << "\n";
        break;
      case '3':
        std::cout << "ilosc elementow w liscie: " << lista->size() << "\n";
        break;
      case '4':
        std::cout << "Twoja lista to: " << *lista << "\n";
        break;
      case '5':
        if (lista->issorted())
          std::cout << "Twoja lista jest posortowana\n";
        else
          std::cout << "Twoja lista NIE jest posortowana\n";
        break;
      case '6':
        lista->sort();
        std::cout << "Twoja lista zostala posortowana\n";
        break;
      case '8':
        menu();
        break;
      }
    }
    delete lista;
  }
  else //lista intow (calosc prawie taka sama jak wyzej)
  {
    int el;
    auto lista = new list<int>();
    std::cout << "Utworzono listę intów\n";
    menu();
    while (co != '7')
    {
      std::cin >> co;
      if (co == '7')
        break;
      switch (co)
      {
      case '1':
        std::cout << "podaj element typu int: ";
        std::cin >> el;
        std::cout << "wlozono do listy " << el << "\n";
        lista->insert(el);
        break;
      case '2':
        std::cout << "podaj element typu int: ";
        std::cin >> el;
        lista->remove(el);
        std::cout << "wyciagnieto element: " << el << "\n";
        break;
      case '3':
        std::cout << "ilosc elementow w liscie: " << lista->size() << "\n";
        break;
      case '4':
        std::cout << "Twoja lista to: " << *lista << "\n";
        break;
      case '5':
        if (lista->issorted())
          std::cout << "Twoja lista jest posortowana\n";
        else
          std::cout << "Twoja lista NIE jest posortowana\n";
        break;
      case '6':
        lista->sort();
        std::cout << "Twoja lista zostala posortowana\n";
        break;
      case '8':
        menu();
        break;
      }
    }
    delete lista;
  }

  std::cout << "W takim razie konczymy\nDo zobaczenia!\n";

  return 0;
}