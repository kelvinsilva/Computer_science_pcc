
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

enum ERRORS {ILLEGAL_FRACTION};

int get_num_of_places(double dec); //Non member, non friend function.

class fraction
{
    public:
        //fraction();//default constructor
        fraction(int n = 0, int d = 1); //constructor with parameters
        fraction(const fraction &other); //copy constructor
        ~fraction(); //destructor


        //Assignment operators
        fraction& operator=(const fraction &other);//assignment operator
        fraction& operator= ( double dec);

        fraction& operator+=(const fraction &other);
        fraction& operator-=(const fraction &other);
        fraction& operator*=(const fraction &other);
        fraction& operator/=(const fraction &other);

        fraction& operator+=(const int &other);
        fraction& operator-=(const int &other);
        fraction& operator*=(const int &other);
        fraction& operator/=(const int &other);

        //Accessor functions
        int getNum() const;
        int getDenom() const;

        //Mutator functions
        void setNum(int n);
        void setDenom(int d);

        //double return
        double getDouble();


        //Friends that can take two mixed numbers and create a third mixed number
        friend
        fraction operator*(const fraction &x, const fraction &y);

        friend
        fraction operator/(const fraction &x, const fraction &y);

        friend
        fraction operator-(const fraction &x, const fraction &y);

        friend
        fraction operator+(const fraction &x, const fraction &y);

        //friends that take an integer and a mixed number
        friend
        fraction operator*(const fraction &x, const int &y);

        friend
        fraction operator/(const fraction &x, const int &y);

        friend
        fraction operator-(const fraction &x, const int &y);

        friend
        fraction operator+(const fraction &x, const int &y);

        friend
        fraction operator*(const int &x, const fraction &y);

        friend
        fraction operator/(const int &x, const fraction &y);

        friend
        fraction operator-(const int &x, const fraction &y);

        friend
        fraction operator+(const int &x, const fraction &y);


        //input / output friemds

        friend//cout<<fractionA<<fractionB
        ostream& operator<<(ostream &out, const fraction &x);

        friend
        istream& operator>>(istream &in, fraction &x);

        //Comparision operator friends
        friend
        bool operator==(const fraction &x, const fraction &y);

        friend
        bool operator!=(const fraction &x, const fraction &y);

        friend
        bool operator>=(const fraction &x, const fraction &y);

        friend
        bool operator<=(const fraction &x, const fraction &y);

        friend
        bool operator>(const fraction &x, const fraction &y);

        friend
        bool operator<(const fraction &x, const fraction &y);

        //Comparision operators for fractions and integers
        friend
        bool operator==(const fraction &x, const int &y);

        friend
        bool operator!=(const fraction &x, const int &y);

        friend
        bool operator>=(const fraction &x, const int &y);

        friend
        bool operator<=(const fraction &x, const int &y);

        friend
        bool operator>(const fraction &x, const int &y);

        friend
        bool operator<(const fraction &x, const int &y);

        friend
        bool operator==(const int &x, const fraction &y);

        friend
        bool operator!=(const int &x, const fraction &y);

        friend
        bool operator>=(const int &x, const fraction &y);

        friend
        bool operator<=(const int &x, const fraction &y);

        friend
        bool operator>(const int &x, const fraction &y);

        friend
        bool operator<(const int &x, const fraction &y);

    protected:

        int& theNum();
        int& theDenom();
        void setFraction(int x, int y);

    private:
        int num, denom;

        void copy(const fraction &other);
        void reduce();
        int gcd(int p , int q);
};
#endif // FRACTION_H
