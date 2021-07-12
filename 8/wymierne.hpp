#include <bits/stdc++.h>
#include <stdexcept>

namespace obliczenia
{
    class wymierna
    {
        int licz, mian;

    public:
        wymierna(int licznik, int mianownik) throw(dzielenie_przez_0, przekroczenie_zakresu);
        wymierna(int licznik);
        int mianownik();
        int licznik();
        friend wymierna operator+(const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu);
        friend wymierna operator-(const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu);
        friend wymierna operator*(const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu);
        friend wymierna operator/(const wymierna &w1, const wymierna &w2) throw(dzielenie_przez_0, przekroczenie_zakresu);

        friend wymierna operator-(const wymierna &w) throw(przekroczenie_zakresu);
        friend wymierna operator!(const wymierna &w) throw(dzielenie_przez_0);

        operator double();
        explicit operator int();

        friend std::ostream &operator<<(std::ostream &wy, const wymierna &w);
    };

    //hierarchia wyjatkow

    class wyjatek_wymierny : public std::logic_error
    {
    public:
        wyjatek_wymierny() = default;
        ~wyjatek_wymierny() = default;
    };

    class dzielenie_przez_0 : public wyjatek_wymierny
    {
    public:
        dzielenie_przez_0() = default;
        virtual ~dzielenie_przez_0() = default;
        const char *what() { return "Dzielenie przez 0!"; }
    };

    class przekroczenie_zakresu : public wyjatek_wymierny // zakres int: -2147483648 -- 2147483647
    {
    public:
        przekroczenie_zakresu() = default;
        virtual ~przekroczenie_zakresu() = default;
        const char *what() { return "Przekrocznie zakresu!"; }
    };

}
