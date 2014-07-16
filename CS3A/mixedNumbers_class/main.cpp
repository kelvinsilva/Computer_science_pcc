#include <iostream>
#include "mixedNumbers.h"

using namespace std;

int main()
{

    mixedNumber sup(true , 7, 1, 6);
    mixedNumber he(false, 5, 1, 6);
    mixedNumber fg;

    cout << "adder: ";
    //cin >> he >> sup;
    fg = sup ^ he;
    cout << fg;


    //cout << "\n\n";
    //sup.output();
    //cout << "\n\n";
    //cout << "sup numerator: "  << sup.getNumerator() <<endl;
    //cout << "sup denominator: " << sup.getDenominator() << endl;
    //cout << "sup whole: " << sup.getWhole() << endl;


    return 0;
}
