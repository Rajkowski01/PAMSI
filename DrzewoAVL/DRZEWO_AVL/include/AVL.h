#ifndef AVL_H
#define AVL_H

#include <iomanip>
#include "WezelAVL.h"

class AVL
{
    public:
        AVL();
        ~AVL();

        WezelAVL * korzen; //korzen drzewa

        WezelAVL * poprzed(WezelAVL * W);
        WezelAVL * nastep(WezelAVL * W);
        WezelAVL * maks_wezel(WezelAVL * W);
        WezelAVL * mini_wezel(WezelAVL * W);
        int maks_klucz(WezelAVL * W);
        int mini_klucz(WezelAVL * W);
        WezelAVL * szukaj(int klucz);

        WezelAVL * rotacjaP(WezelAVL * W);
        WezelAVL * rotacjaL(WezelAVL * W);
        WezelAVL * rotacjaPL(WezelAVL * W);
        WezelAVL * rotacjaLP(WezelAVL * W);

        bool wstaw(WezelAVL * W);
        WezelAVL * usun(WezelAVL * W);

        void preorder(WezelAVL * W);
        void inorder(WezelAVL * W);
        void postorder(WezelAVL * W);
        void zawartosc_drzewa(WezelAVL * W);

        int Wezlicz_w() { return licz_w; }

    protected:

    private:
        int licz_w; //liczba wezlow
};

#endif // AVL_H
