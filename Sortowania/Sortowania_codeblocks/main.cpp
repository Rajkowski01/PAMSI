#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "Kopiec.h"



using namespace std;

// GENEROWANIE LOSOWYCH ELEMENTOW TABLICY
void generuj(int * Tablica, int poczatek, int koniec)
{
    for (int i=poczatek; i<=koniec; i++)
    {
        //srand(time(NULL));
        Tablica[i] = rand() % 1000000 + 1;
    }
}

void odwroc(int * Tablica, int poczatek, int koniec)
{
    for (int i=poczatek; i<=(poczatek+koniec)/2; i++)
    {
        swap(Tablica[i], Tablica[koniec+poczatek-i]);
    }
}

///////////////////////////////////////
// SCALANIE W SORTOWANIU PRZEZ SCALANIE
void scalanie(int * Tablica, int poczatek, int srodek, int koniec)
{
    int rozmiar = koniec-poczatek+1;
    int Tymczasowa_Tablica[rozmiar];
    int i=0;
    int kopia_poczatku = poczatek;
    int kopia_srodka = srodek+1;
    while (kopia_poczatku <= srodek && kopia_srodka <= koniec)
    {
        if (Tablica[kopia_poczatku] < Tablica[kopia_srodka])
        {
            Tymczasowa_Tablica[i] = Tablica[kopia_poczatku];
            kopia_poczatku++;
        }
        else
        {
            Tymczasowa_Tablica[i] = Tablica[kopia_srodka];
            kopia_srodka++;
        }
        i++;
    }
    while (kopia_poczatku <= srodek)
    {
        Tymczasowa_Tablica[i] = Tablica[kopia_poczatku];
        kopia_poczatku++;
        i++;
    }
    while (kopia_srodka <= koniec)
    {
        Tymczasowa_Tablica[i] = Tablica[kopia_srodka];
        kopia_srodka++;
        i++;
    }
    for (i=0; i<rozmiar; i++)
    {
        Tablica[poczatek+i] = Tymczasowa_Tablica[i];
    }
}

// SORTOWANIE PRZEZ SCALANIE
void sortowanie_przez_scalanie(int * Tablica, int poczatek, int koniec)
{
    if (poczatek < koniec)
    {
        int srodek = (poczatek + koniec) / 2;
        sortowanie_przez_scalanie(Tablica, poczatek, srodek);
        sortowanie_przez_scalanie(Tablica, srodek+1, koniec);
        scalanie(Tablica, poczatek, srodek, koniec);
    }
}
//////////////////////////////
// SORTOWANIE PRZEZ KOPCOWANIE
void sortowanie_przez_kopcowanie(int * Tablica, int poczatek, int koniec)
{
    Kopiec K;
    for (int i=poczatek; i<=koniec; i++)
    {
        K.dodaj(Tablica[i]);
    }
    for (int i=poczatek; i<=koniec; i++)
    {
        Tablica[i] = K.usun();
    }
}
////////////////////////////////////////////////////
// PODZIAL TABLICY W ALGORYTMIE SORTOWANIA SZYBKIEGO
int podziel_tablice(int * Tablica, int poczatek, int koniec)
{
    int piwot = (rand() % (koniec-poczatek+1)) + poczatek;
    //int piwot = (poczatek+koniec)/2;

    //swap(Tablica[piwot], Tablica[koniec]);
    //int pozycja = poczatek;
    //for (int i=poczatek; i<koniec; i++)
    //{
    //    if(Tablica[i] < Tablica[koniec])
    //    {
    //        swap(Tablica[i], Tablica[pozycja]);
    //        pozycja++;
    //    }
    //}
    //swap(Tablica[pozycja], Tablica[koniec]);
    //return pozycja;

    swap(Tablica[piwot], Tablica[poczatek]);
    piwot = Tablica[poczatek];
    while(poczatek!=koniec)
    {
        if(Tablica[poczatek+1]>piwot)
        {
            swap(Tablica[poczatek+1], Tablica[koniec]);
            koniec--;
        }
        else
        {
            Tablica[poczatek]=Tablica[poczatek+1];
            poczatek++;
        }
    }
    Tablica[poczatek]=piwot;
    return poczatek;
}

// SORTOWANIE SZYBKIE
void sortowanie_szybkie(int * Tablica, int poczatek, int koniec)
{
    if (poczatek < koniec)
    {
        int srodek = podziel_tablice(Tablica, poczatek, koniec);
        sortowanie_szybkie(Tablica, poczatek, srodek-1);
        sortowanie_szybkie(Tablica, srodek+1, koniec);
    }
}
////////////////////////////
// SORTOWANIE INTROSPEKTYWNE
void sortowanie_introspektywne(int * Tablica, int poczatek, int koniec, int poziom, int rozmiar)
{
    if (poczatek < koniec)
    {
        if (poziom > rozmiar)
        {
            sortowanie_przez_kopcowanie(Tablica, poczatek, koniec);
        }
        else
        {
            poziom = poziom*2;
            int srodek = podziel_tablice(Tablica, poczatek, koniec);
            sortowanie_introspektywne(Tablica, poczatek, srodek-1, poziom, rozmiar);
            sortowanie_introspektywne(Tablica, srodek+1, koniec, poziom, rozmiar);
        }
    }
}
////////////////////////////////////////
// SPRAWDZA CZY TABLICA JEST POSORTOWANA
bool posortowane(int * Tablica, int poczatek, int koniec)
{
    for (int i=poczatek; i<koniec; i++)
    {
        if (Tablica[i] > Tablica[i+1])
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    srand(time(NULL));
    int n;
    int n_posortowanych;
    int ile_promili;
    int wybor;
    bool odwrotnie;
    clock_t czas;

    for(;;)
    {

        cout << "wpisz wielkosc tablicy\n";
        cin >> n;
        int T[n];
        cout << "generowanie\n";
        generuj(T,0,n-1);
        cout << "wygenerowano\n";
        cout << "ile promili pierwszych elementow posortowanych?\n";
        cin >> ile_promili;
        n_posortowanych = (n/1000)*ile_promili;
        sort(T,T+n_posortowanych);
        cout << "\n";
        cout << "posortowano\n";
        cout << "1 - tablica posortowana odwrotnie, 0 - nie\n";
        cin >> odwrotnie;
        if(odwrotnie)
        {
            sort(T,T+n);
            cout << "posortowano... ";
            odwroc(T,0,n-1);
            cout << "i odwrocono\n";
        }
        cout << "pierwsze 10 elementow tablicy:\n";
        for (int i=0; i<10; i++)
        {
            cout << T[i] << " ";
        }
        cout << "\n\n";
        cout << "wybierz sortowanie:\n";
        cout << "0 - przerwij dzialanie programu\n";
        cout << "1 - sorowanie przez scalanie\n";
        cout << "2 - sortowanie szybkie\n";
        cout << "3 - sortowanie introspektywne\n\n";
        cin >> wybor;
        switch(wybor)
        {
        case 1:
            cout << "SORTOWANIE PRZEZ SCALANIE\n";
            cout << "sortowanie... ";
            czas = clock();
            /*for (int i=0;i<100;i++)*/
            sortowanie_przez_scalanie(T,0,n-1);
            czas = clock() - czas;
            break;
        case 2:
            cout << "SORTOWANIE SZYBKIE\n";
            cout << "sortowanie... ";
            czas = clock();
            /*for (int i=0;i<100;i++)*/
            sortowanie_szybkie(T,0,n-1);
            czas = clock() - czas;
            break;
        case 3:
            cout << "SORTOWANIE INTROSPEKTYWNE\n";
            cout << "sortowanie... ";
            czas = clock();
            /*for (int i=0;i<100;i++)*/
            sortowanie_introspektywne(T,0,n-1,1,n);
            czas = clock() - czas;
            break;
            default:
            cout << "konczenie programu\n";
            system("PAUSE");
            return 0;
        }
        cout << "zakonczono\n";
        cout << "posortowano w czasie: ";
        cout << czas << " ms\n";
        cout << "sprawdzanie\n";
        if (posortowane(T,0,n-1))
        {
            cout << "posortowane poprawnie\n";
        }
        else
        {
            cout << "posortowane NIEpopranie\n";
        }
        /*
        for (int i=0; i<n; i++)
        {
            cout << T[i] << " ";
        }
        */
        system("PAUSE");
        system("cls");

    }

    return 0;
}
