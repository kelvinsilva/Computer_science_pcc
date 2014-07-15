#include <iostream>
#include "mixedNumbers.h"

using namespace std;

int main()
{

    mixedNumber sup( 2, 3, 4);
    mixedNumber he(2, 4, 5);
    mixedNumber fg;


    fg = (sup / he);
    fg.output();

    return 0;
}
