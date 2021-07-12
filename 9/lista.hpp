#include <bits/stdc++.h>
//#include "sorty.hpp"

namespace calc
{
    template <typename T>
    class list
    {

    private:
        class node //zagniezdzona klasa wezla
        {
        public:
            node(T v);
            T val; //wartosc
            node *next;
        };

        node *start;    //poczatek listy
        int length = 0; //dlugosc listy

    public:
        list();
        ~list();
        bool is_empty();              //czy lista jest pusta
        void insert(T v);             //wstawianie na koniec listy
        void insert_at(T v, int poz); //wstawianie na pozycje poz listy, pozycje numerowane od 1 - tj. insert_at(v 1) wstawia na początek listy; 0<poz<length+2
        void remove(T v);             //usuwa wszystkie elementy v z listy, jesli zadnego v nie ma na liscie nic sie nie dzieje
        void remove_first(T v);       //usuwa pierwszy element v z listy, jesli zadnego v nie ma na liscie nic sie nie dzieje
        bool is_in(T v);              //sprawdza czy element v jest w liscie
        int size();                   //rozmiar listy

        list(const list &a);               // konstruktor kopiujący
        list(list &&a);                    // konstruktor przenoszący
        list &operator=(const list<T> &a); // przypisanie kopiujące
        list &operator=(list &&a);         // przypisanie przenoszące

        list(std::initializer_list<T> kol);

        friend std::ostream &operator<<(std::ostream &wy, const list<T> &a)
        {
            if (a.length > 0)
            {
                wy << ". ";
                node *akt = a.start;
                while (akt->next != NULL)
                {
                    wy << akt->val << " ";
                    akt = akt->next;
                }
                wy << akt->val << " .";
            }
            else
                wy << " (nothing) ";
            return wy;
        }

        bool issorted(); //czy lista jest posortowana
        void sort(); //sortowanie listy relacja <=
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //-------------------------------------------------------------------------------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T>
    list<T>::node::node(T v)
    {
        val = v;
        next = NULL;
    }

    template <typename T>
    list<T>::list()
    {
        start = NULL;
    }

    template <typename T>
    list<T>::~list()
    {
        if (length > 0)
        {
            node *akt = start;
            node *n;

            while (akt != NULL)
            {
                n = akt;
                akt = akt->next;
                delete n;
            }
        }
    }

    template <typename T>
    bool list<T>::is_empty()
    {
        return (length == 0);
    }

    template <typename T>
    void list<T>::insert(T v)
    {
        node *nowy = new node(v);
        if (length == 0)
        {
            start = nowy;
            length = 1;
        }
        else
        {
            node *akt = start;
            while (akt->next != NULL)
            {
                akt = akt->next;
            }
            akt->next = nowy;
            length += 1;
        }
    }

    template <typename T>
    void list<T>::insert_at(T v, int poz) //wstawianie na pozycje poz listy, pozycje numerowane od 1 - tj. insert_at(v 1) wstawia na początek listy; 0<poz<length+2
    {
        if (poz <= 0 || poz > length + 1)
            throw std::runtime_error("zla pozycja wstawiania");
        if (length == 0)
        {
            this->insert(v);
        }
        else if (poz == 1)
        {
            node *nowy = new node(v);
            nowy->next = start;
            start = nowy;
        }
        else if (poz == length + 1)
        {
            this->insert(v);
        }
        else
        {
            int np = 2;
            node *akt = start;
            node *nowy = new node(v);
            while (np != poz)
            {
                akt = akt->next;
            }
            node *p = akt->next;
            akt->next = nowy;
            nowy->next = p;
        }

        length++;
    }

    template <typename T>
    void list<T>::remove(T v)
    {
        while (start != NULL && start->val == v)
        {
            start = start->next;
            length--;
        }
        node *akt = start;
        node *prev = NULL;
        while (akt->next != NULL)
        {
            if (akt->val != v)
            {
                prev = akt;
            }
            else
            {
                prev->next = akt->next;
                length--;
            }
            akt = akt->next;
        }
    }

    template <typename T>
    void list<T>::remove_first(T v)
    {
        if (start != NULL && start->val == v)
        {
            start = start->next;
            length--;
            return;
        }
        node *akt = start;
        node *prev = NULL;
        while (akt->next != NULL)
        {
            if (akt->val != v)
            {
                prev = akt;
            }
            else
            {
                prev->next = akt->next;
                length--;
                return;
            }
            akt = akt->next;
        }
    }

    template <typename T>
    bool list<T>::is_in(T v)
    {
        node *akt = start;
        while (akt->next != NULL)
        {
            if (akt->val == v)
                return true;
            akt = akt->next;
        }
        return false;
    }

    template <typename T>
    int list<T>::size()
    {
        return length;
    }

    template <typename T>
    list<T>::list(const list<T> &a) //konstruktor kopiujacy
    {
        if (a.length == 0)
        {
            this->start = NULL;
        }
        else
        {
            node *akt = a.start;
            while (akt->next != NULL)
            {
                this->insert(akt->val);
                akt = akt->next;
            }
            this->insert(akt->val);
        }
    }

    template <typename T>
    list<T>::list(list<T> &&a) //konstruktor przenoszacy
    {
        if (a.length == 0)
        {
            this->start = NULL;
        }
        else
        {
            node *akt = a.start;
            while (akt->next != NULL)
            {
                this->insert(akt->val);
                akt = akt->next;
            }
            this->insert(akt->val);
        }
    }

    template <typename T>
    list<T> &list<T>::operator=(const list<T> &a) //przypisanie kopiujace
    {
        if (&a == this)
            return *this;
        this->~list();
        if (a.length == 0)
        {
            this->start = NULL;
        }
        else
        {
            node *akt = a.start;
            while (akt->next != NULL)
            {
                this->insert(akt->val);
                akt = akt->next;
            }
            this->insert(akt->val);
        }
        return *this;
    }

    template <typename T>
    list<T> &list<T>::operator=(list<T> &&a) //przypisanie przenoszace
    {
        if (&a == this)
            return *this;
        this->~list();
        if (a.length == 0)
        {
            this->start = NULL;
        }
        else
        {
            node *akt = a.start;
            while (akt->next != NULL)
            {
                this->insert(akt->val);
                akt = akt->next;
            }
            this->insert(akt->val);
        }
        return *this;
    }

    template <typename T>
    list<T>::list(std::initializer_list<T> kol)
    {
        this->start = NULL;

        for (auto elem : kol)
        {
            this->insert(elem);
        }
    }

    template <typename T>
    bool list<T>::issorted()
    {
        node *akt = start;
        node *n = akt->next;
        while (akt->next != NULL)
        {
            if (akt->val > n->val)
                return false;
            akt = n;
            n = n->next;
        }
        return true;
    }

    template <typename T>
    void list<T>::sort() //zwykly bubble_sort bez zadnych optymalizacji
    {
        for (int i = 0; i <= length; i++)
        {
            node **h = &start;
            for (int j = 0; j < length - 1; j++)
            {
                node *w1 = *h;
                node *w2 = w1->next;

                if (w1->val > w2->val)
                {
                    node *t = w2->next;
                    w2->next = w1;
                    w1->next = t;
                    *h = w2;
                }

                h = &(*h)->next;
            }
        }
    }

}
