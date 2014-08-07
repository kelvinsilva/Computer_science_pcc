#ifndef TOKEN_DEF_H_
#define TOKEN_DEF_H_
#include <iostream>
#include "mixedNumber.h"

using namespace std;

struct token{ /*Define ourselves a token since our program has to put all things on 1 output queue
                It may hold either a Char or a mixed number. So we hold 2 variables and a boolean to determine which is which.
                Similar function to unions.
              */

    mixedNumber mix;
    double value;
    bool IS_NUMBER;

    void setNumber(mixedNumber val){
        mix = val;
        IS_NUMBER = true;
    }
    void setChar(double val){
        value = val;
        IS_NUMBER = false;
    }

    friend istream& operator>>(istream &in, token &x);
    friend ostream& operator<<(ostream &out, const token &x);

};

#endif // TOKEN_DEF_H_
