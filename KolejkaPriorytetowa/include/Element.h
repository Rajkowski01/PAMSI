#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
    public:
        Element();
        virtual ~Element();

        //Element* Getprev() { return prev; }
        //void Setprev(Element* val) { prev = val; }
        //Element* Getnext() { return next; }
        //void Setnext(Element* val) { next = val; }
        //int* Getobiekt() { return obiekt; }
        //void Setobiekt(int* val) { obiekt = val; }

        Element* prev;
        Element* next;
        int* objekt;

    protected:

    private:

};

#endif // ELEMENT_H
