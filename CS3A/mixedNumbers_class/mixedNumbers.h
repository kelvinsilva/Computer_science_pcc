//Kelvin Silva
//To use  this class, if you want a negative number you can either assign manually negative whole number and negative numerator
//Or you can use all positive numerator, positive whole number and use true and false for sign bit on the third constructor.
//The use of signbit or manually setting the numbers does not affect the behavior of the class.



#ifndef MIXEDNUMBERS_H
#define MIXEDNUMBERS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;


class mixedNumber{



    private:

        long whole, num, denom;

    public:

        mixedNumber();
        mixedNumber(long w, long n, long d);
        mixedNumber(bool sbit, long w, long n, long d );

        ~mixedNumber();

        void reduce();
        void output();

        mixedNumber getImproper();

        long gcd(int x, int y);

        double getDecimalVal();

        long getWhole();
        long getNumerator();
        long getDenominator();


        void setWhole(long w);
        void setNumerator(long q);
        void setDenominator(long q);



        friend mixedNumber operator+ ( const mixedNumber &x, const mixedNumber &y);
        friend mixedNumber operator- (mixedNumber &x, mixedNumber &y);
        friend mixedNumber operator* (mixedNumber &x, mixedNumber &y);
        friend mixedNumber operator/ (mixedNumber &x, mixedNumber &y);
        friend mixedNumber operator^ (mixedNumber &x, mixedNumber &y);


        mixedNumber& operator= (const mixedNumber& y);
        mixedNumber& operator= (double doub);





};

int get_num_of_places(double dec); //Non member, non friend function.

#endif // MIXEDNUMBERS_H
