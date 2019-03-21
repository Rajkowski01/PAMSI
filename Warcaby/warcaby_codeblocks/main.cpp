#include <iostream>
#include <cstdlib>
#include <string>

#include "plansza.h"

using namespace std;

int alfa;
int beta;

int minimax_rekurencja(Plansza _Plansza, int gracz, int poziom, int limit, int kod_ruchu)
{
    int drugi_gracz;
    bool ciach = false;
    int wartosc_ruchu = 0;
    int wartosc_naj = 0;
    int wartosc_rek;
    int Tablica_ruchow[100];
    if (_Plansza.ruch(kod_ruchu) == true) // zbicie
    {
        if (gracz == 1)
        {
            wartosc_ruchu--;
        }
        else // gracz == 2
        {
            wartosc_ruchu++;
        }
    }
    if (_Plansza.damka(gracz) == true) // damka
    {
        if (gracz == 1)
        {
            wartosc_ruchu--;
        }
        else // gracz == 2
        {
            wartosc_ruchu++;
        }
    }
    if (_Plansza.wygrana(gracz) == true) // wygrana
    {
        if (gracz == 1)
        {
            wartosc_ruchu = -1000;
        }
        else // gracz == 2
        {
            wartosc_ruchu = 1000;
        }
        poziom = limit; // koniec gry
    }
    if (gracz == 1)
    {
        drugi_gracz = 2;
    }
    else // gracz == 2
    {
        drugi_gracz = 1;
    }
    // ciecia alfa-beta
    if (gracz == 1)
    {
        if (wartosc_ruchu - (limit - poziom)/2 > beta) // jesli nie da sie z tego wyjsc na plus
        {
            ciach = true;
        }
    }
    else // gracz == 2
    {
        if (wartosc_ruchu + (limit - poziom)/2 < alfa) // jesli nie da sie z tego wyjsc na plus
        {
            ciach = true;
        }
    }
    if (poziom < limit && ciach == false) // SZUKANIE MAKSIMUM / MINIMUM
    {
        _Plansza.mozliwe_ruchy(Tablica_ruchow, drugi_gracz);
        for (int i=1; i<=Tablica_ruchow[0]; i++)
        {
            kod_ruchu = Tablica_ruchow[i];
            wartosc_rek = minimax_rekurencja(_Plansza, drugi_gracz, poziom+1, limit, kod_ruchu); // REKURENCJA
            if (drugi_gracz == 1)
            {
                if (wartosc_naj > wartosc_rek)
                {
                    wartosc_naj = wartosc_rek;
                }
            }
            else // gracz == 2
            {
                if (wartosc_naj < wartosc_rek)
                {
                    wartosc_naj = wartosc_rek;
                }
            }
        }
        wartosc_ruchu = wartosc_ruchu + wartosc_naj;
    }
    if (gracz == 1 && wartosc_ruchu < beta)
    {
        beta = wartosc_ruchu;
    }
    if (gracz == 2 && wartosc_ruchu > alfa)
    {
        alfa = wartosc_ruchu;
    }
    return wartosc_ruchu;
}

int minimax_start(Plansza _Plansza, int limit)
{
    int Tablica_ruchow[100];
    int Wartosci_ruchow[100];
    int kod_ruchu;
    int wartosc_ruchu;
    int najlepszy = -limit;
    alfa = -100;
    beta = 100;
    _Plansza.mozliwe_ruchy(Tablica_ruchow, 2);
    for (int i=1; i<=Tablica_ruchow[0]; i++)
    {
        kod_ruchu = Tablica_ruchow[i];
        wartosc_ruchu = minimax_rekurencja(_Plansza, 2, 1, limit, kod_ruchu);
        Wartosci_ruchow[i] = wartosc_ruchu;
        if (wartosc_ruchu > najlepszy)
        {
            najlepszy = wartosc_ruchu;
        }
    }
    for (int i=1; i<=Tablica_ruchow[0]; i++)
    {
        if (najlepszy == Wartosci_ruchow[i])
        {
            kod_ruchu = Tablica_ruchow[i];
        }
    }
    return kod_ruchu;
}

void start()
{
    cout << "--------WARCABY--------\n";
    cout << "Pawel Rajkowski 235216\n";
    cout << "\n";
    cout << "ZASADY\n";
    cout << "Jak w warcabach, ale:\n";
    cout << "1. maksymalnie jedno zbicie w turze,\n";
    cout << "2. damka przed zbiciem moze poruszyc sie dowolna liczbe pol,\n";
    cout << "3. damka po zbiciu laduje tak jakby byla zwyklym pionkiem (tuz za zbitym pionkiem).\n";
    cout << "\n";
    cout << "Ruchy wprowadzane w nastepujacym formacie:\n";
    cout << "{litera_poczatkowa}{cyfra_poczatkowa}{litera_koncowa}{cyfra_koncowa}\n";
    cout << "DUZE LITERY!\n";
    cout << "np. chcemy poruszyc pionek z A3 na B4\n";
    cout << "piszemy:\n";
    cout << "A3B4\n";
    cout << "i wciskamy Enter\n";
    cout << "\n";
    cout << "Powodzenia!\n\n";
}

int tekst_na_kod(string tekst)
{
    int kod = 0;
    if (tekst[0] < 'A' || tekst[0] > 'H') return false;
    //cout << tekst[0] << "\n";
    if (tekst[1] < '1' || tekst[1] > '8') return false;
    //cout << tekst[1] << "\n";
    if (tekst[2] < 'A' || tekst[2] > 'H') return false;
    //cout << tekst[2] << "\n";
    if (tekst[3] < '1' || tekst[3] > '8') return false;
    //cout << tekst[3] << "\n";
    kod = kod + (tekst[0] + 1 - 'A') * 100;
    //cout << kod << "\n";
    kod = kod + 9000 - (tekst[1] + 1 - '1') * 1000;
    //cout << kod << "\n";
    kod = kod + (tekst[2] + 1 - 'A') * 1;
    //cout << kod << "\n";
    kod = kod + 90 - (tekst[3] + 1 - '1') * 10;
    //cout << kod << "\n";
    return kod;
}

int main()
{

    Plansza _Plansza;
    int limit = 4;
    bool koniec_gry = false;
    int kod_ruchu;
    int Poprawne_ruchy[100];
    bool poprawny_ruch;
    string wybor;
    int tmp = 0;

    //system("cls");
    //_Plansza.wyswietl(1);

    //system("PAUSE");

    start();
    system("PAUSE");
    system("cls");

    cout << "ustaw poziom trudosci (glebokosc drzewa):\n";
    //cout << "1 - slepy\n";
    //cout << "2 - glupi\n";
    //cout << "4 - myslacy\n";
    cout << "6 - przecietny\n";
    cout << "8 - dobry\n";
    cout << "10+ - na wlasna odpowiedzialnosc (dlugo mysli)\n";
    cout << "\n";
    cout << "Twoj wybor:\n";

    cin >> limit;
    while (koniec_gry == false)
    {
        system("cls");
        cout << "Poziom trudnosci: " << limit;
        _Plansza.wyswietl(1);

        poprawny_ruch = false;
        _Plansza.mozliwe_ruchy(Poprawne_ruchy, 1);
        while (poprawny_ruch == false)
        {
            cin >> wybor;
            kod_ruchu = tekst_na_kod(wybor);

            if (kod_ruchu == false)
            {
                cout << "\n";
                cout << "ZLY FORMAT\n";
            }
            for (int i=1; i<=Poprawne_ruchy[0]; i++)
            {
                //cout << i << Poprawne_ruchy[i] << " ";
                if (kod_ruchu == Poprawne_ruchy[i])
                {
                    poprawny_ruch = true;
                    //cout << "BUM";
                }
            }
            cout << "OSZUKUJESZ\n";

        }

        tmp = _Plansza.ruch(kod_ruchu);

        if (_Plansza.wygrana(1) == true)
        {
            koniec_gry = true;
            break;
        }
        tmp = _Plansza.damka(1);
        system("cls");
        _Plansza.wyswietl(1);

        kod_ruchu = minimax_start(_Plansza, limit);
        tmp = _Plansza.ruch(kod_ruchu);
        tmp = _Plansza.damka(2);
        if (_Plansza.wygrana(2) == true)
        {
            koniec_gry = true;
            break;
        }
        system("PAUSE");
    }

    system("cls");
    _Plansza.wyswietl(1);
    cout << "KONIEC\n";
    system("PAUSE");
    cout << "\n" << "[" << tmp << "]\n";

    return 0;
}
