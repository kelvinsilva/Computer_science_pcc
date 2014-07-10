#ifndef MIXEDNUMBER_H
#define MIXEDNUMBER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

    struct mixedNumber
    {
        long whole, num, denom;

        mixedNumber();
        void reduce();
        long gcd(int x, int y);
        void output();
    };

#endif // MIXEDNUMBER_H
