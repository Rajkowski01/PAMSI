#ifndef PLANSZA_H
#define PLANSZA_H

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Plansza
{
    public:
        Plansza();

        void wyswietl(int tryb);
        void mozliwe_ruchy(int* Tab, int gracz);
        bool ruch(int kod_ruchu); // jesli zbicie to 1
        bool wygrana(int gracz);
        bool damka(int gracz);

    protected:

    private:
        int Pole[10][10];
};

#endif // PLANSZA_H
