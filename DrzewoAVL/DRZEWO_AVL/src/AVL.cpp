#include "AVL.h"
#include "WezelAVL.h"

#include<iomanip>
#include<iostream>

using namespace std;

//konstruktor
AVL::AVL()
{
    korzen = NULL;
    licz_w = 0;
}

//destruktor
AVL::~AVL()
{
    while(korzen)
    {
        delete(usun(korzen));
    }
}

//wezel poprzednika
WezelAVL * AVL::poprzed(WezelAVL * W)
{
    if(W->lewy)
    {
        return maks_wezel(W->lewy);
    }
    WezelAVL * W_tmp;
    W_tmp = W;
    W = W->rodzic;
    while((W->prawy != W_tmp) && W)
    {
        W_tmp = W;
        W = W->rodzic;
    }
    return W;
}

//wezel mastepnika
WezelAVL * AVL::nastep(WezelAVL * W)
{
    if(W->prawy)
    {
        return mini_wezel(W->prawy);
    }
    WezelAVL * W_tmp;
    W_tmp = W;
    W = W->rodzic;
    while((W->lewy != W_tmp) && W)
    {
        W_tmp = W;
        W = W->rodzic;
    }
    return W;
}

//wezel z najwiekszym kluczem
WezelAVL * AVL::maks_wezel(WezelAVL * W)
{
    while(W->prawy)
    {
        W = W->prawy;
    }
    return W;
}

//wezel z najmiejszym kluczem
WezelAVL * AVL::mini_wezel(WezelAVL * W)
{
    while(W->lewy)
    {
        W = W->lewy;
    }
    return W;
}

//najwiekszy klucz
int AVL::maks_klucz(WezelAVL * W)
{
    while(W->prawy)
    {
        W = W->prawy;
    }
    return W->klucz;
}

//najmniejszy klucz
int AVL::mini_klucz(WezelAVL * W)
{
    while(W->lewy)
    {
        W = W->lewy;
    }
    return W->klucz;
}


// rotacja w prawo
WezelAVL * AVL::rotacjaP(WezelAVL * W)
{
    WezelAVL * W2 = W->prawy;
    WezelAVL * W0 = W->rodzic;
    W->prawy = W2->lewy;
    if(W->prawy)
    {
        W->prawy->rodzic = W;
    }
    W2->lewy = W;
    W2->rodzic = W0;
    W->rodzic = W2;
    if(W0)
    {
        if(W0->lewy == W)
        {
            W0->lewy = W2;
        }
        else
        {
            W0->prawy = W2;
        }
    }
    else
    {
        korzen = W2;
    }
    if(W2->wsp_row == -1)
    {
        W->wsp_row = 0;
        W2->wsp_row = 0;
    }
    else
    {
        W->wsp_row = -1;
        W2->wsp_row = 1;
    }
    return W2;
}

//rotacja w lewo
WezelAVL * AVL::rotacjaL(WezelAVL * W)
{
    WezelAVL * W1 = W->lewy;
    WezelAVL * W0 = W->rodzic;
    W->lewy = W1->prawy;
    if(W->lewy)
    {
        W->lewy->rodzic = W;
    }
    W1->prawy = W;
    W1->rodzic = W0;
    W->rodzic = W1;
    if(W0)
    {
        if(W0->lewy == W)
        {
            W0->lewy = W1;
        }
        else
        {
            W0->prawy = W1;
        }
    }
    else
    {
        korzen = W1;
    }
    if (W1->wsp_row == 1)
    {
        W->wsp_row = 0;
        W1->wsp_row = 0;
    }
    else
    {
        W->wsp_row = 1;
        W1->wsp_row = -1;
    }
    return W1;
}

//rotacja prawo-lewo
WezelAVL * AVL::rotacjaPL(WezelAVL * W)
{
    WezelAVL * W2 = W->prawy;
    WezelAVL * W21 = W2->lewy;
    WezelAVL * W0 = W->rodzic;
    W2->lewy = W21->prawy;
    if(W2->lewy)
    {
        W2->lewy->rodzic = W2;
    }
    W->prawy = W21->lewy;
    if(W->prawy)
    {
        W->prawy->rodzic = W;
    }
    W21->lewy = W;
    W21->prawy = W2;
    W->rodzic = W21;
    W2->rodzic = W21;
    W21->rodzic = W0;
    if(W0)
    {
        if(W0->lewy == W)
        {
            W0->lewy = W21;
        }
        else
        {
            W0->prawy = W21;
        }
    }
    else
    {
        korzen = W21;
    }
    if(W21->wsp_row == -1)
    {
        W->wsp_row = 1;
    }
    else
    {
        W->wsp_row = 0;
    }
    if(W21->wsp_row == 1)
    {
        W2->wsp_row = -1;
    }
    else
    {
        W2->wsp_row = 0;
    }
    W21->wsp_row = 0;
    return W21;
}

//rotacja lewo-prawo
WezelAVL * AVL::rotacjaLP(WezelAVL * W)
{
    WezelAVL * W1 = W->lewy;
    WezelAVL * W12 = W->prawy;
    WezelAVL * W0 = W->rodzic;
    W1->prawy = W12->lewy;
    if(W1->prawy)
    {
        W1->prawy->rodzic = W1;
    }
    W->lewy = W12->prawy;
    if(W->lewy)
    {
        W->lewy->rodzic = W;
    }
    W12->prawy = W;
    W12->lewy = W1;
    W->rodzic = W12;
    W1->rodzic = W12;
    W12->rodzic = W0;
    if(W0)
    {
        if(W0->lewy == W)
        {
            W0->lewy = W12;
        }
        else
        {
            W0->prawy = W12;
        }
    }
    else
    {
        korzen = W12;
    }
    if(W12->wsp_row == 1)
    {
        W->wsp_row = -1;
    }
    else
    {
        W->wsp_row = 0;
    }
    if(W12->wsp_row == -1)
    {
        W1->wsp_row = 1;
    }
    else
    {
        W1->wsp_row = 0;
    }
    W12->wsp_row = 0;
    return W12;
}

//wstaw wezel do drzewa
bool AVL::wstaw(WezelAVL * W)
{
    WezelAVL * W0 = korzen;
    WezelAVL * W1;
    WezelAVL * W2;
    W1 = NULL;
    W->lewy = NULL;
    W->prawy = NULL;
    W->wsp_row = 0;
    while(W0)
    {
        if(W0->klucz == W->klucz)
        {
            delete W;
            return false;
        }
        W1 = W0;
        if(W->klucz < W0->klucz)
        {
            W0 = W0->lewy;
        }
        else
        {
            W0 = W0->prawy;
        }
    }
    licz_w++;
    if(!(W->rodzic = W1))
    {
        korzen = W;
        return true;
    }
    if(W->klucz < W1->klucz)
    {
        W1->lewy = W;
    }
    else
    {
        W1->prawy = W;
    }
    if(W1->wsp_row)
    {
        W1->wsp_row = 0;
        return true;
    }
    if(W1->lewy == W)
    {
        W1->wsp_row = 1;
    }
    else
    {
        W1->wsp_row = -1;
    }
    W2 = W1->rodzic;
    while(W2)
    {
        if(W2->wsp_row) break;
        if(W2->lewy == W1)
        {
            W2->wsp_row = 1;
        }
        else
        {
            W2->wsp_row = -1;
        }
        W1 = W2;
        W2 = W2->rodzic;
    }
    if(!W2)
    {
        return true;
    }
    if(W2->wsp_row == 1)
    {
        if(W2->prawy == W1)
        {
            W2->wsp_row = 0;
            return true;
        }
        if(W1->wsp_row == -1)
        {
            rotacjaLP(W2);
        }
        else
        {
            rotacjaL(W2);
        }
        return true;
    }
    else
    {
        if(W2->lewy == W1)
        {
            W2->wsp_row = 0;
            return true;
        }
        if(W1->wsp_row == 1)
        {
            rotacjaPL(W2);
        }
        else
        {
            rotacjaP(W2);
        }
        return true;
    }
}

//usun i zwroc wezel z drzewa
WezelAVL * AVL::usun(WezelAVL * W)
{
    WezelAVL * W_tmp;
    WezelAVL * W1;
    WezelAVL * W2;
    bool n2d; //czy nie dwoje dzieci
    if((W->lewy) && (W->prawy))
    {
        W1 = usun(poprzed(W));
        licz_w++;
        n2d = false;
    }
    else
    {
        if(W->lewy)
        {
            W1 = W->lewy;
            W->lewy = NULL;
        }
        else
        {
            W1 = W->prawy;
            W->prawy = NULL;
        }
        W->wsp_row = 0;
        n2d = true;
    }
    if(W1)
    {
        W1->rodzic = W->rodzic;
        W1->lewy = W->lewy;
        if(W1->lewy)
        {
            W1->lewy->rodzic = W1;
        }
        W1->prawy = W->prawy;
        if(W1->prawy)
        {
            W1->prawy->rodzic = W1;
        }
        W1->wsp_row = W->wsp_row;
    }
    if(W->rodzic)
    {
        if(W->rodzic->lewy == W)
        {
            W->rodzic->lewy = W1;
        }
        else
        {
           W->rodzic->prawy = W1;
        }
    }
    else
    {
        korzen = W1;
    }
    if(n2d)
    {
        W2 = W1;
        W1 = W->rodzic;
        while(W1)
        {
            if(!(W1->wsp_row))
            {
                if(W1->lewy == W2)
                {
                    W1->wsp_row = -1;
                }
                else
                {
                    W1->wsp_row = 1;
                }
                break;
            }
            else
            {
                if(((W1->wsp_row == 1) && (W1->lewy == W2)) || ((W1->wsp_row == -1) && (W1->prawy == W2)))
                {
                    W1->wsp_row = 0;
                    W2 = W1;
                    W1 = W1->rodzic;
                }
                else
                {
                    if(W1->lewy == W2)
                    {
                        W_tmp = W1->prawy;
                    }
                    else
                    {
                        W_tmp = W1->lewy;
                    }
                    if(!(W_tmp->wsp_row))
                    {
                        if(W1->wsp_row == 1)
                        {
                            rotacjaL(W1);
                        }
                        else
                        {
                            rotacjaP(W1);
                        }
                        break;
                    }
                    else
                    {
                        if(W1->wsp_row == W_tmp->wsp_row)
                        {
                            if(W1->wsp_row == 1)
                            {
                                rotacjaL(W1);
                            }
                            else
                            {
                                rotacjaP(W1);
                            }
                            W2 = W_tmp;
                            W1 = W_tmp->rodzic;
                        }
                        else
                        {
                            if(W1->wsp_row == 1)
                            {
                                rotacjaLP(W1);
                            }
                            else
                            {
                                rotacjaPL(W1);
                            }
                            W2 = W1->rodzic;
                            W1 = W2->rodzic;
                        }
                    }
                }
            }
        }
    }
    licz_w--;
    return W;
}

//przejscie preorder
void AVL::preorder(WezelAVL * W)
{
    if(W)
    {
        cout << W->klucz << "\n";
        preorder(W->lewy);
        preorder(W->prawy);
    }
}

//przejscie inorder
void AVL::inorder(WezelAVL * W)
{
    if(W)
    {
        inorder(W->lewy);
        cout << W->klucz << "\n";
        inorder(W->prawy);
    }
}

//przejscie postorder
void AVL::postorder(WezelAVL * W)
{
    if(W)
    {
        postorder(W->lewy);
        postorder(W->prawy);
        cout << W->klucz << "\n";
    }
}

void AVL::zawartosc_drzewa(WezelAVL * W)
{
    cout << "Wezel " << W->klucz << ", Wspolczynnik rownowagi: " << W->wsp_row << "\n";
    cout << "Lewy syn: ";
    if(W->lewy)
    {
        cout << W->lewy->klucz;
    }
    else
    {
        cout << "brak";
    }
    cout << ", Prawy syn: ";
    if(W->prawy)
    {
        cout << W->prawy->klucz;
    }
    else
    {
        cout << "brak";
    }
    cout << ", Rodzic: ";
    if(W->rodzic)
    {
        cout << W->rodzic->klucz;
    }
    else
    {
        cout << "brak";
    }
    cout << "\n";
    if(W->lewy)
    {
        zawartosc_drzewa(W->lewy);
    }
    if(W->prawy)
    {
        zawartosc_drzewa(W->prawy);
    }
}

WezelAVL * AVL::szukaj(int klucz)
{
    WezelAVL * W = korzen;
    while((W) && (W->klucz != klucz))
    {
        if(klucz < W->klucz)
        {
            W = W->lewy;
        }
        else
        {
            W = W->prawy;
        }
    }
    return W;
}
