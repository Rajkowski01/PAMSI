#include "Plansza.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
Plansza::Plansza()
{
    for (int i=0; i<10; i++)
    {
        Pole[0][i]=-1;
        Pole[9][i]=-1;
        Pole[i][0]=-1;
        Pole[i][9]=-1;
    }
    for (int i=1; i<=8; i++)
    {
        for (int j=1; j<=8; j++)
        {
            if ((i+j)%2 == 0)
            {
                Pole[i][j] = -1;
            }
            else
            {
                if (i <= 3) Pole[i][j] = 2;
                if (i == 4 || i == 5) Pole[i][j] = 0;
                if (i >= 6) Pole[i][j] = 1;
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////
void Plansza::wyswietl(int tryb)
{
    char znak[5];
    if (tryb == 0)
    {
        znak[0] = '.';
        znak[1] = 1;
        znak[2] = 2;
        znak[3] = 3;
        znak[4] = 4;
    }
    else
    {
        znak[0] = '.';
        znak[1] = 't';
        znak[2] = 'q';
        znak[3] = 'T';
        znak[4] = 'Q';
    }
    cout << "\n";
    cout << "     ABCDEFGH  \n";
    cout << "    +--------+\n";
    for (int i=1; i<=8; i++)
    {
        cout << "   " << 9-i << "|";
        for (int j=1; j<=8; j++)
        {
            if(Pole[i][j] == -1)
            {
                cout << "#";
            }
            else
            {
                cout << znak[Pole[i][j]];
            }
        }
        cout << "|" << 9-i << "\n";
    }
    cout << "    +--------+\n";
    cout << "     ABCDEFGH  \n\n";
}
///////////////////////////////////////////////////////////////////////////////
void Plansza::mozliwe_ruchy(int* Tab, int gracz)
{
    int k=1;
    Tab[0] = 0;
    for (int i=1; i<=8; i++)
    {
        for (int j=1; j<=8; j++)
        {
            if (gracz == 1) // GRACZ 1 (czlowiek)
            {
                if (Pole[i][j] == 1) // pion gracza 1
                {
                    if (Pole[i-1][j-1] == 0) // ruch w lewo
                    {
                        Tab[0]++;
                        Tab[Tab[0]] = i*1000 + j*100 + (i-1)*10 + (j-1);
                    }
                    if (Pole[i-1][j+1] == 0) // ruch w prawo
                    {
                        Tab[0]++;
                        Tab[Tab[0]] = i*1000 + j*100 + (i-1)*10 + (j+1);
                    }
                    if (Pole[i-1][j-1] == 2 || Pole[i-1][j-1] == 4) // bicie na lewo
                    {
                        if (Pole[i-2][j-2] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i-2)*10 + (j-2);
                        }
                    }
                    if (Pole[i-1][j+1] == 2 || Pole[i-1][j+1] == 4) // bicie na prawo
                    {
                        if (Pole[i-2][j+2] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i-2)*10 + (j+2);
                        }
                    }
                    if (Pole[i+1][j-1] == 2 || Pole[i+1][j-1] == 4) // bicie na lewo w tyl
                    {
                        if (Pole[i+2][j-2] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i+2)*10 + (j-2);
                        }
                    }
                    if (Pole[i+1][j+1] == 2 || Pole[i+1][j+1] == 4) // bicie na prawo w tyl
                    {
                        if (Pole[i+2][j+2] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i+2)*10 + (j+2);
                        }
                    }
                }
                if (Pole[i][j] == 3) // damka gracza 1
                {
                    k=1;
                    while (Pole[i-k][j-k] != -1) // ruchy w lewo
                    {
                        if (Pole[i-k][j-k] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i-k)*10 + (j-k);
                        }
                        if (Pole[i-k][j-k] == 2 || Pole[i-k][j-k] == 4) // zbicie
                        {
                            if (Pole[i-k-1][j-k-1] == 0)
                            {
                                Tab[0]++;
                                Tab[Tab[0]] = i*1000 + j*100 + (i-k-1)*10 + (j-k-1);
                            }
                            break;
                        }
                        k++;
                    }
                    k=1;
                    while (Pole[i-k][j+k] != -1) // ruchy w prawo
                    {
                        if (Pole[i-k][j+k] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i-k)*10 + (j+k);
                        }
                        if (Pole[i-k][j+k] == 2 || Pole[i-k][j+k] == 4) // zbicie
                        {
                            if (Pole[i-k-1][j+k+1] == 0)
                            {
                                Tab[0]++;
                                Tab[Tab[0]] = i*1000 + j*100 + (i-k-1)*10 + (j+k+1);
                            }
                            break;
                        }
                        k++;
                    }
                    k=1;
                    while (Pole[i+k][j-k] != -1) // ruchy w lewo w tyl
                    {
                        if (Pole[i+k][j-k] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i+k)*10 + (j-k);
                        }
                        if (Pole[i+k][j-k] == 2 || Pole[i+k][j-k] == 4) // zbicie
                        {
                            if (Pole[i+k+1][j-k-1] == 0)
                            {
                                Tab[0]++;
                                Tab[Tab[0]] = i*1000 + j*100 + (i+k+1)*10 + (j-k-1);
                            }
                            break;
                        }
                        k++;
                    }
                    k=1;
                    while (Pole[i+k][j+k] != -1) // rychy w prawo w tyl
                    {
                        if (Pole[i+k][j+k] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i+k)*10 + (j+k);
                        }
                        if (Pole[i+k][j+k] == 2 || Pole[i+k][j+k] == 4) // zbicie
                        {
                            if (Pole[i+k+1][j+k+1] == 0)
                            {
                                Tab[0]++;
                                Tab[Tab[0]] = i*1000 + j*100 + (i+k+1)*10 + (j+k+1);
                            }
                            break;
                        }
                        k++;
                    }
                }
            }
            if (gracz == 2) // GRACZ 2 (komputer)
            {
                if (Pole[i][j] == 2) // pion gracza 2
                {
                    if (Pole[i+1][j-1] == 0) // ruch w prawo
                    {
                        Tab[0]++;
                        Tab[Tab[0]] = i*1000 + j*100 + (i+1)*10 + (j-1);
                    }
                    if (Pole[i+1][j+1] == 0) // ruch w lewo
                    {
                        Tab[0]++;
                        Tab[Tab[0]] = i*1000 + j*100 + (i+1)*10 + (j+1);
                    }
                    if (Pole[i-1][j-1] == 1 || Pole[i-1][j-1] == 3) // bicie na prawo w tyl
                    {
                        if (Pole[i-2][j-2] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i-2)*10 + (j-2);
                        }
                    }
                    if (Pole[i-1][j+1] == 1 || Pole[i-1][j+1] == 3) // bicie na lewo w tyl
                    {
                        if (Pole[i-2][j+2] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i-2)*10 + (j+2);
                        }
                    }
                    if (Pole[i+1][j-1] == 1 || Pole[i+1][j-1] == 3) // bicie na prawo
                    {
                        if (Pole[i+2][j-2] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i+2)*10 + (j-2);
                        }
                    }
                    if (Pole[i+1][j+1] == 1 || Pole[i+1][j+1] == 3) // bicie na lewo
                    {
                        if (Pole[i+2][j+2] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i+2)*10 + (j+2);
                        }
                    }
                }
                if (Pole[i][j] == 4) // damka gracza 2
                {
                    k=1;
                    while (Pole[i-k][j-k] != -1) // ruchy w prawo w tyl
                    {
                        if (Pole[i-k][j-k] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i-k)*10 + (j-k);
                        }
                        if (Pole[i-k][j-k] == 1 || Pole[i-k][j-k] == 3) // zbicie
                        {
                            if (Pole[i-k-1][j-k-1] == 0)
                            {
                                Tab[0]++;
                                Tab[Tab[0]] = i*1000 + j*100 + (i-k-1)*10 + (j-k-1);
                            }
                            break;
                        }
                        k++;
                    }
                    k=1;
                    while (Pole[i-k][j+k] != -1) // ruchy w lewo w tyl
                    {
                        if (Pole[i-k][j+k] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i-k)*10 + (j+k);
                        }
                        if (Pole[i-k][j+k] == 1 || Pole[i-k][j+k] == 3) // zbicie
                        {
                            if (Pole[i-k-1][j+k+1] == 0)
                            {
                                Tab[0]++;
                                Tab[Tab[0]] = i*1000 + j*100 + (i-k-1)*10 + (j+k+1);
                            }
                            break;
                        }
                        k++;
                    }
                    k=1;
                    while (Pole[i+k][j-k] != -1) // ruchy w prawo
                    {
                        if (Pole[i+k][j-k] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i+k)*10 + (j-k);
                        }
                        if (Pole[i+k][j-k] == 1 || Pole[i+k][j-k] == 3) // zbicie
                        {
                            if (Pole[i+k+1][j-k-1] == 0)
                            {
                                Tab[0]++;
                                Tab[Tab[0]] = i*1000 + j*100 + (i+k+1)*10 + (j-k-1);
                            }
                            break;
                        }
                        k++;
                    }
                    k=1;
                    while (Pole[i+k][j+k] != -1) // rychy w lewo
                    {
                        if (Pole[i+k][j+k] == 0)
                        {
                            Tab[0]++;
                            Tab[Tab[0]] = i*1000 + j*100 + (i+k)*10 + (j+k);
                        }
                        if (Pole[i+k][j+k] == 1 || Pole[i+k][j+k] == 3) // zbicie
                        {
                            if (Pole[i+k+1][j+k+1] == 0)
                            {
                                Tab[0]++;
                                Tab[Tab[0]] = i*1000 + j*100 + (i+k+1)*10 + (j+k+1);
                            }
                            break;
                        }
                        k++;
                    }
                }
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////
bool Plansza::ruch(int kod_ruchu)
{
    int i_pocz = kod_ruchu/1000;
    int j_pocz = kod_ruchu/100 - (kod_ruchu/1000)*10;
    int i_kon = kod_ruchu/10 - (kod_ruchu/100)*10;
    int j_kon = kod_ruchu - (kod_ruchu/10)*10;

    // przeniesienie pionka / damki
    Pole[i_kon][j_kon] = Pole[i_pocz][j_pocz];
    Pole[i_pocz][j_pocz] = 0;

    // czy bylo bicie
    if(i_kon - i_pocz > 1)
    {
        if(j_kon - j_pocz > 1)
        {
            if (Pole[i_kon-1][j_kon-1] != 0)
            {
                Pole[i_kon-1][j_kon-1] = 0;
                return true;
            }
        }
        if(j_kon - j_pocz < -1)
        {
            if (Pole[i_kon-1][j_kon+1] != 0)
            {
                Pole[i_kon-1][j_kon+1] = 0;
                return true;
            }
        }
    }
    if(i_kon - i_pocz < -1)
    {
        if(j_kon - j_pocz > 1)
        {
            if (Pole[i_kon+1][j_kon-1] != 0)
            {
                Pole[i_kon+1][j_kon-1] = 0;
                return true;
            }
        }
        if(j_kon - j_pocz < -1)
        {
            if (Pole[i_kon+1][j_kon+1] != 0)
            {
                Pole[i_kon+1][j_kon+1] = 0;
                return true;
            }
        }
    }
    return false;
}
//////////////////////////////////////////////////////////////////////////
bool Plansza::wygrana(int gracz)
{
    for (int i=1; i<=8; i++)
    {
        for (int j=1; j<=8; j++)
        {
            // jesli na polu jest pionek lub damka przeciwnika
            if (Pole[i][j] != gracz && Pole[i][j] != gracz+2 && Pole[i][j] != 0)
            {
                return false; // to jeszcze nie wygrales
            }
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////
bool Plansza::damka(int gracz)
{
    if (gracz == 1)
    {
        for (int j=1; j<=8; j++)
        {
            if (Pole[1][j] == gracz)
            {
                Pole[1][j] = gracz+2;
                return true;
            }
        }
    }
    if (gracz == 2)
    {
        for (int j=1; j<=8; j++)
        {
            if (Pole[8][j] == gracz)
            {
                Pole[8][j] = gracz+2;
                return true;
            }
        }
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////
