
#ifndef TWO2DARRAY_H
#define TWO2DARRAY_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

#include "safearray.h"

using namespace std;

enum ERROR {NOTVALID};

class two2Darray
{
    public:

        two2Darray(string name = "", int r = 5, int c = 5);
        ~two2Darray();

        two2Darray(const two2Darray &other);
        two2Darray& operator=(const two2Darray &other);

        safeArray& operator[](int index);
        void resize(int r, int c);
        void clear();

        friend ostream& operator<<(ostream &out, const two2Darray &list);

        friend istream& operator>>(istream &in, two2Darray &list);

        int getRows();
        int getCols();


    private:
        safeArray *list;
        int rows, cols;

        string name;
        void copy(const two2Darray &other);

        void nukem();
        void makeNewList(int r, int c);
};

#endif // TWO2DARRAY_H
