#ifndef KOPIEC_H
#define KOPIEC_H


class Kopiec
{
    public:
        Kopiec();

        void dodaj(int element);
        int usun();
        int wielkosc() {return rozmiar;}

    protected:

    private:
        int Tablica_kopca[1000007];
        int rozmiar;


};

#endif // KOPIEC_H
