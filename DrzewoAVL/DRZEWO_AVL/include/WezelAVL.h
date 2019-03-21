#ifndef WEZELAVL_H
#define WEZELAVL_H

#include <iomanip>

class WezelAVL
{
    public:
        WezelAVL();

        WezelAVL * rodzic;
        WezelAVL * lewy;
        WezelAVL * prawy;
        int klucz;
        int wsp_row; //wspolczynnik rownowagi

    protected:

    private:
};

#endif // WEZELAVL_H
