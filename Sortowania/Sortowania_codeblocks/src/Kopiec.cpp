#include "Kopiec.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

Kopiec::Kopiec()
{
    rozmiar = 0;
}

void sprawdz_w_gore(int * Tablica, int i)
{
    if (i > 1)
    {
        if (Tablica[i] < Tablica[i/2])
        {
            swap(Tablica[i], Tablica[i/2]);
            sprawdz_w_gore(Tablica, i/2);
        }
    }
}

void sprawdz_w_dol(int * Tablica, int i, int rozmiar)
{
    if(i*2 <= rozmiar)
    {
        int zamiennik = i*2;
        if(i*2 < rozmiar)
        {
            if (Tablica[i*2]>Tablica[i*2+1])
            {
                zamiennik = i*2+1;
            }
        }
        if (Tablica[i]>Tablica[zamiennik])
        {
            swap(Tablica[i], Tablica[zamiennik]);
            sprawdz_w_dol(Tablica, zamiennik, rozmiar);
        }
    }
}

void Kopiec::dodaj(int element)
{
    rozmiar++;
    Tablica_kopca[rozmiar] = element;
    sprawdz_w_gore(Tablica_kopca, rozmiar);
}

int Kopiec::usun()
{
    swap(Tablica_kopca[rozmiar], Tablica_kopca[1]);
    int do_oddania = Tablica_kopca[rozmiar];
    rozmiar--;
    sprawdz_w_dol(Tablica_kopca, 1, rozmiar);
    return do_oddania;
}
