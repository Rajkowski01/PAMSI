#include <iostream>
#include "Element.h"
#include "Lista.h"

using namespace std;

int main()
{
    Lista test;
    int T[3] = {5,4,3};
    test.AddAfter(T, test.Size());
    test.AddAfter(T+1, test.Size());
    cout << *(test.Get(1));
    cout << *(test.Get(2));

    cout << "Hello world!" << endl;
    return 0;
}
