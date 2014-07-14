#ifndef SAFEARRAY_H
#define SAFEARRAY_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

enum ERRORS {INVALID};

class safeArray
{
    public:
        safeArray(string n = "", int s = 10);
        ~safeArray();

        safeArray(const safeArray &other);
        safeArray& operator=(const safeArray &other);

        int& operator[](int index);
        int operator()(int index);

        int getSize();
        void resize(int s);
        void clear();

        friend ostream& operator<<(ostream &out, const safeArray &list);

        friend istream& operator>>(istream &in, safeArray &list);


     private:
        int *list, size;
        string name;

        void copy(const safeArray &other);
        void nukem();
        void makeNewList(int s);
};

#endif // SAFEARRAY_H
