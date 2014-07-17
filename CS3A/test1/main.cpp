#include <iostream>
#include "mixedNumbers.h"
#include "twodarray.h"

using namespace std;

int main(int argc, char *argv[])
{

    mixedNumber sup(true , 7, 1, 6);
    mixedNumber he(false, 5, 1, 6);
    mixedNumber fg;

    two2Darray hold_numbers("Mixed_List", 3, 2);
    two2Darray numb_disp("Mixed List", 3, 2);


        hold_numbers[0][0] = 1.577848545;
        hold_numbers[0][1] = 1.58545;
        hold_numbers[1][0] = 1.55;
        hold_numbers[1][1] = 1.577545;
        hold_numbers[2][0] = 3.14159;
        hold_numbers[2][1] = 23.47;





    ifstream fi;
    fi.open("test1.mat");
    fi >> numb_disp;
    fi.close();

    cout << numb_disp;
    //cout << numb_disp;
    //cin >> hold_numbers;
    //cout << hold_numbers;




    //cin >> he >> sup;
    //fg = sup + he;
    //cout << fg;


    //cout << "\n\n";
    //sup.output();
    //cout << "\n\n";
    //cout << "sup numerator: "  << sup.getNumerator() <<endl;
    //cout << "sup denominator: " << sup.getDenominator() << endl;
    //cout << "sup whole: " << sup.getWhole() << endl;


    return 0;
}
