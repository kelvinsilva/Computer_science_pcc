#include "operationfuncs.h"

bool edit(two2Darray &left){

        int r = 0, c = 0;
        string rs = "", cs = "";
        cout << "Enter how many rows you want to edit or create: ";
        getline(cin, rs);
        if (rs.find_first_not_of("123456789") != string::npos){ //Quick way to check crappy input
            cout << "ERROR! Aborting"; //If i find stuff that is not numeric, then i tell the user that there is an error and i abort the program
            return false;
        }else r = atoi(rs.c_str()); //a to i, alphabet to integer. converts "1234" to 1234


        cout << "Enter how many columns you want to edit or create: ";
        getline(cin, cs);
        if (cs.find_first_not_of("123456789") != string::npos){
            cout << "ERROR! Aborting";
            return false;
        } else c = atoi(cs.c_str());

        left.resize(r, c); //resize to appropriate row and col

        cout << "Entering a " << r << "x" << c << " array\n";
        cout << "Enter each row, with elements separated by commas\n";
        cout << "Do not enter spaces in between comma values\n";
        for (int i = 0; i< r; i++){

            cout << "Row " << i << " : "; //for each row...
            cin >> left[i]; //i dereference a safearray element and call its extraction operator

        }
}


void add (two2Darray &arr1, two2Darray &arr2, two2Darray &arrRes){
    int rows = 0, cols = 0;

    rows = arr1.getRows();
    cols = arr1.getCols();

    for (int i = 0; i < rows; i++){

        for (int j = 0; j < cols; j++){

            arrRes[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return;
}
