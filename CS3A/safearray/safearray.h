#ifndef SAFE_ARRAY_H_
#define SAFE_ARRAY_H_

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "mixedNumbers.h"

using namespace std;

enum ERRORS {INVALID};

class safeArray
{
    public:
        safeArray(string n = "", int s = 10);
        ~safeArray();

        safeArray(const safeArray &other);
        safeArray& operator=(const safeArray &other);

        mixedNumber& operator[](int index);
        mixedNumber operator()(int index);

        int getSize();
        void resize(int s);
        void clear();

        friend ostream& operator<<(ostream &out, const safeArray &list);
        ostream& print_array(ostream &out);

        friend istream& operator>>(istream &in, safeArray &list);

        static int print_width;

     private:

        mixedNumber *list;
        int size;


        void getPrintWidth();

        string name;

        void copy(const safeArray &other);
        void nukem();
        void makeNewList(int s);
};

#endif // SAFEARRAY_H
