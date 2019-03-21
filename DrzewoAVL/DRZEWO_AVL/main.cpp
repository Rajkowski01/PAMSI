#include <iostream>
#include <iomanip>
#include "AVL.h"
#include "WezelAVL.h"

using namespace std;

//wstawia wezel o danym kluczu
void wstaw(AVL * Drzewo, int wartosc)
{
    WezelAVL * W;
    W = new WezelAVL;
    W->klucz = wartosc;
    cout << "...\n";
    Drzewo->wstaw(W);
}

//usuwa wezel o danym kluczu
bool usun(AVL * Drzewo, int wartosc)
{
    WezelAVL * W;
    W = Drzewo->szukaj(wartosc);
    if(W)
    {
        cout << "...\n";
        Drzewo->usun(W);
        return true;
    }
    else
    {
        return false;
    }
}

//sprawdza czy istnieje wezel o danym kluczu
bool sprawdz(AVL * Drzewo, int wartosc)
{
    if(Drzewo->szukaj(wartosc))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void preorder(AVL * Drzewo)
{
    Drzewo->preorder(Drzewo->korzen);
}

void inorder(AVL * Drzewo)
{
    Drzewo->inorder(Drzewo->korzen);
}

void postorder(AVL * Drzewo)
{
    Drzewo->postorder(Drzewo->korzen);
}

void zawartosc(AVL * Drzewo)
{
    Drzewo->zawartosc_drzewa(Drzewo->korzen);
}

int main()
{
    cout << "Hello world!\n\n" << endl;

    AVL * Drzewo = new AVL();
    int wybor = 1;
    int wartosc;
    while(wybor)
    {
        cout << "\n";
        cout << "0 - koniec\n";
        cout << "1 - dodaj wezel\n";
        cout << "2 - usun wezel\n";
        cout << "3 - sprawdz istnienie wezla\n";
        cout << "4 - preorder\n";
        cout << "5 - inorder\n";
        cout << "6 - postorder\n";
        cout << "7 - wypisz drzewo\n";
        cout << "\n";
        cout << "> ";
        cin >> wybor;
        switch(wybor)
        {
        case 1:
            cout << "klucz dodawanego wezla:\n";
            cin >> wartosc;
            wstaw(Drzewo,wartosc);
            cout << "Wstawiono.\n\n";
            break;
        case 2:
            cout << "klucz usuwanego wezla:\n";
            cin >> wartosc;
            if(usun(Drzewo,wartosc))
            {
                cout << "Usunieto.\n\n";
            }
            else
            {
                cout << "Brak elemetu.\n\n";
            }
            break;
        case 3:
            cout << "klucz szukanego wezla:\n";
            cin >> wartosc;
            if(sprawdz(Drzewo,wartosc))
            {
                cout << "Wezel jest w drzewie.\n\n";
            }
            else
            {
                cout << "Wezla nie ma w drzewie.\n\n";
            }
            break;
        case 4:
            preorder(Drzewo);
            cout << "\n";
            break;
        case 5:
            inorder(Drzewo);
            cout << "\n";
            break;
        case 6:
            postorder(Drzewo);
            cout << "\n";
            break;
        case 7:
            zawartosc(Drzewo);
            cout << "\n";
            break;
        }
        cout << ".......................................\n\n";
    }
    delete Drzewo;

    return 0;
}
