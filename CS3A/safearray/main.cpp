#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "twodarray.h"

using namespace std;

int main()
{
    ifstream in;
    ofstream out;

    two2Darray test("test"), test2("test");

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            test[i][j] = 23;

    cout<<test<<endl;
    out.open("test.dat");

    out<<test<<endl;
    out.close();

    cout<<"Reading in from test.dat"<<endl;

    in.open("test.dat");

    in>>test2;
    in.close();

    cout<<test2<<endl;

    return 0;
}
