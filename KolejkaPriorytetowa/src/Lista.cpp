#include "Lista.h"

Lista::Lista()
{
    this->head.next = &(this->tail);
    this->tail.prev = &(this->head);
    this->_size = 0;
}

Lista::~Lista()
{
    Element* iter;
    iter = &(this->head);
    while (this->_size > 0)
    {
        iter = iter->next;
        delete(iter->prev);
    }
    delete(&head);
    delete(&tail);
}

bool Lista::IsEmpty()
{
    if (this->_size == 0) return true;
    else return false;
}
void Lista::AddAfter(int* obj, int num)
{
    Element* iter;
    Element* elem;
    elem->objekt = obj;
    iter = &(this->head);
    for (int i=0; i<num; i++)
    {
        iter = iter->next;
    }
    elem->prev = iter;
    elem->next = iter->next;
    elem->next->prev = elem;
    elem->prev->next = elem;

    (this->_size)++;
}
int* Lista::Remove(int num)
{
    if (num > this->_size || num <= 0) throw "Error: Deleting non-existing element.";
    else
    {
        Element* iter;
        iter = &(this->head);
        for (int i=0; i<num; i++)
        {
            iter = iter->next;
        }
        iter->next->prev = iter->prev;
        iter->prev->next = iter->next;
        return iter->objekt;
        delete(iter);
        (this->_size)--;
    }
}
int* Lista::Get(int num)
{
    Element* iter;
    iter = &(this->head);
    for (int i=0; i<num; i++)
    {
        iter = iter->next;
    }
    iter->next->prev = iter->prev;
    iter->prev->next = iter->next;
    return iter->objekt;
}
