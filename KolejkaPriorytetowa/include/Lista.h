#ifndef LISTA_H
#define LISTA_H

#include "Element.h"

class Lista
{
    public:
        Lista();
        virtual ~Lista();

        Element head;
        Element tail;
        int Size() { return _size; }
        bool IsEmpty();
        void AddAfter(int* obj, int num);
        int* Remove(int num);
        int* Get(int num);

    protected:

    private:
        int _size;
};

#endif // LISTA_H
