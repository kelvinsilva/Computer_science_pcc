#include "fraction.h"
#include <cmath>

int get_num_of_places(double dec){


    int counter = 0;
    int integer_val = 0;

    do {

        integer_val = trunc(dec);
        dec = abs(integer_val - dec);

        dec *= 10;
        counter++;

    }while ( !((int)floor((float)dec) == (int)ceil((float)dec)) && (counter != 7) ); //counter!=7, to DEFAULT at most 7 decimal places.
                                                                                    //Any more will put too much error, bit overrun

    return counter;

}

    //Non member, non friend function.

fraction& fraction::operator= ( double dec){

    if (dec > 0){

           double decDecimal = abs(trunc(dec) - dec); // get the fractional element. Subtract the truncated decimal, from the decimal
           int number_to_raise = get_num_of_places(decDecimal); //Get the number of decimal places
           int numerator = decDecimal * pow(10, number_to_raise); //The numerator wil have the decimal raised to the power of decimal places (Equivalent to decimal part without the ."
           //ex: 1.342 -> .342 -> 342

           int denominator =  pow(10, number_to_raise);

           this->num = numerator;
           this->setDenom( denominator);

           this->reduce();

           return *this;

       }
       else
       {
           double decDecimal = abs(trunc(dec) - dec);

           int number_to_raise = get_num_of_places(decDecimal);
           int numerator = decDecimal * pow(10, number_to_raise) * -1;
           int denominator =  pow(10, number_to_raise);

           this->num = numerator;
           this->setDenom( denominator);

           this->reduce();

           return *this;
       }
}

double fraction::getDouble(){

    return (double)num/denom;

}


fraction::fraction(int n, int d ) //constructor with parameters
{
    num = n;
    denom = d;
    reduce();
}

fraction::fraction(const fraction &other) //copy constructor
{
    copy(other);
}

fraction::~fraction() //destructor
{
    num = 0;
    denom = 0;
}


//Assignment operators
fraction& fraction::operator=(const fraction &other)//assignment operator
{
    if(this != &other)
        copy(other);
    return *this;
}

fraction& fraction::operator+=(const fraction &other)
{
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other)
{
    *this = *this * other;
    return *this;
}

fraction& fraction::operator/=(const fraction &other)
{
    *this = *this / other;
    return *this;
}

fraction& fraction::operator+=(const int &other)
{
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const int &other)
{
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const int &other)
{
    *this = *this * other;
    return *this;
}

fraction& fraction::operator/=(const int &other)
{
    *this = *this / other;
    return *this;
}

//Accessor functions
int fraction::getNum() const
{
    return num;
}

int fraction::getDenom() const
{
    return denom;
}

//Mutator functions
void fraction::setNum(int n)
{
    num = n;
    reduce();
}

void fraction::setDenom(int d)
{
    if(d == 0)
        throw ILLEGAL_FRACTION;
    denom = d;
    reduce();
}

//protected:

int& fraction::theNum()
{
    return num;
}

int& fraction::theDenom()
{
    return denom;
}

void fraction::setFraction(int x, int y)
{
    if(y == 0)
        throw ILLEGAL_FRACTION;
    num = x;
    denom = y;
    reduce();
}

//private:
void fraction::copy(const fraction &other)
{
    num = other.num;
    denom = other.denom;
    reduce();
}

void fraction::reduce()
{
    if(denom < 0)
    {
        num *= -1;
        denom *= -1;
    }
    int divisor = gcd(abs(num), abs(denom));
    num /= divisor;
    denom /= divisor;
}

int fraction::gcd(int p , int q)
{
    return q == 0 ? p : gcd(q, p%q);
}



//Friends that can take two fractions and create a third fraction

fraction operator*(const fraction &x, const fraction &y)
{
    return fraction(x.num*y.num, x.denom * y.denom);
}


fraction operator/(const fraction &x, const fraction &y)
{
    return fraction(x.num*y.denom, x.denom * y.num);
}


fraction operator-(const fraction &x, const fraction &y)
{
    return fraction(x.num*y.denom-x.denom*y.num, x.denom*y.denom);
}


fraction operator+(const fraction &x, const fraction &y)
{
        return fraction(x.num*y.denom+x.denom*y.num, x.denom*y.denom);
}

//s that take an integer and a mixed number

fraction operator*(const fraction &x, const int &y)
{
    return fraction(x.num*y,x.denom);
}


fraction operator/(const fraction &x, const int &y)
{
    return fraction(x.num,x.denom*y);
}

fraction operator-(const fraction &x, const int &y)
{
    return fraction(x.num - y*x.denom ,x.denom);
}

fraction operator+(const fraction &x, const int &y)
{
    return fraction(x.num + y*x.denom ,x.denom);
}


fraction operator*(const int &x, const fraction &y)
{
    return fraction(x *y.num, y.denom);
}


fraction operator/(const int &x, const fraction &y)
{
    return fraction(x *y.denom, y.num);
}


fraction operator-(const int &x, const fraction &y)
{
    return fraction(x*y.denom - y.num, y.denom);
}



fraction operator+(const int &x, const fraction &y)
{
    return fraction(x*y.denom + y.num, y.denom);
}




//input / output friemds


ostream& operator<<(ostream &out, const fraction &x)
{
    out<<x.num<<"/"<<x.denom;
    return out;
}

istream& operator>>(istream &in, fraction &x)
{
    char junk;
    in>>x.num>>junk>>x.denom;
    return in;
}

//Comparision operator s

bool operator==(const fraction &x, const fraction &y)
{
    return x.num*y.denom == x.denom*y.num;
}


bool operator!=(const fraction &x, const fraction &y)
{
    return !(x == y);
}


bool operator>=(const fraction &x, const fraction &y)
{
    return x.num*y.denom >= x.denom*y.num;
}


bool operator<=(const fraction &x, const fraction &y)
{
    return x.num*y.denom <= x.denom*y.num;
}


bool operator>(const fraction &x, const fraction &y)
{
    return x.num*y.denom > x.denom*y.num;
}


bool operator<(const fraction &x, const fraction &y)
{
    return x.num*y.denom < x.denom*y.num;
}


//Comparision operators for fractions and integers

bool operator==(const fraction &x, const int &y)
{
    return x.num == y*x.denom;
}


bool operator!=(const fraction &x, const int &y)
{
    return !(x == y);
}

bool operator>=(const fraction &x, const int &y)
{
    return x.num >= y*x.denom;
}

bool operator<=(const fraction &x, const int &y)
{
    return x.num <= y*x.denom;
}

bool operator>(const fraction &x, const int &y)
{
    return x.num > y*x.denom;
}

bool operator<(const fraction &x, const int &y)
{
    return x.num < y*x.denom;
}


bool operator==(const int &x, const fraction &y)
{
    return y == x;
}


bool operator!=(const int &x, const fraction &y)
{
    return !(y == x);
}


bool operator>=(const int &x, const fraction &y)
{
    return x*y.denom >= y.num;
}

bool operator<=(const int &x, const fraction &y)
{
    return x*y.denom <= y.num;
}

bool operator>(const int &x, const fraction &y)
{
    return x*y.denom > y.num;
}

bool operator<(const int &x, const fraction &y)
{
    return x*y.denom < y.num;
}
