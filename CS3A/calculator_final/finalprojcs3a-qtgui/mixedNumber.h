
#ifndef MIXEDNUMBER_H
#define MIXEDNUMBER_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "fraction.h"

using namespace std;


class mixedNumber : public fraction
{
    public:
        mixedNumber();
        mixedNumber(int w, int n = 0, int d = 1);
        mixedNumber(const fraction &other);
        ~mixedNumber();
        mixedNumber(const mixedNumber &other);
        mixedNumber& operator=(const mixedNumber &other);
        mixedNumber& operator=(const fraction &other);
        void setValue(int w, int n = 0, int d = 1);

        mixedNumber& operator= ( double dec);

        friend
        ostream& operator<<(ostream& out, const mixedNumber &x);

        friend
        istream& operator>>(istream& in,  mixedNumber &x);

    private:

        void copy(const mixedNumber &other);
        void copy(const fraction &other);
};

#endif // MIXEDNUMBER_H
