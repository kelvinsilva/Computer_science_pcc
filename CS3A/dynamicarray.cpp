#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>

typedef unsigned int uint;

using namespace std;

enum TYPE {INT, DOUBLE, CHAR, BOOL, FLOAT, LONG, SHORT, UINT, ULONG, USHORT, UCHAR};

void initialize2DArray(int** &ptr, int rows, int cols);
void initialize2DArray(double** &ptr, int rows, int cols);
void create2DArray(void** &ptr, int row, int col, TYPE which);
bool again(string title);
int getInput(string title, int minimum,int maximum);
void rollDice(int** dice,int rows, int cols);
void computeOdds(double** odds,  int **rolls, int rows, int cols);
void printRolls(int **rolls, int rows, int cols);
void printOdds(double **odds, int rows, int cols);
void delete2DArray(void **rolls, int rows, TYPE which);


int main()
{
    double **odds;
    int **rolls;
    void **param;
    int size;
    srand(time(NULL));
    cout<<"This program will roll dice and compute the odds."<<endl
        <<"Simulations will be in powers of ten"<<endl;
    do
    {
        size = getInput("What is the highest power of 10 to run simulations for (0 <= x <= 9)? ", 0, 9);
        param = (void**)rolls;
        create2DArray(param,size,11,INT);
        rolls = (int**)param;
/*
        create2DArray(reinterpret_cast<void**&>(rolls),size,11,INT);
*/
        param = (void**)odds;
        create2DArray(param,size,11,DOUBLE);
        odds = (double**)param;
/*
        create2DArray(reinterpret_cast<void**&>(odds),size,11,DOUBLE);
*/

        rollDice(rolls,size,11);
        printRolls(rolls,size,11);
        computeOdds(odds, rolls, size, 11);
        printOdds(odds,size,11);
        delete2DArray((void**)rolls, size, INT);
        delete2DArray((void**)odds,  size, DOUBLE)

    }while(again("Do you want to do this again? "));
    return 0;
}


void create2DArray(void** &ptr, int rows, int cols, TYPE which)
{//LONG, SHORT, UINT, ULONG, USHORT
    int **ptrI;
    double **ptrD;
    float **ptrF;
    char **ptrC;
    bool **ptrB;

    long **ptrL;
    short **ptrS;

    unsigned int **ptrUI;
    unsigned long **ptrUL;
    unsigned short **ptrUS;
    unsigned char **ptrUC;

        switch(which)
        {

            case LONG   : ptrL = new long*[rows];
                        break;

            case SHORT  : ptrS = new short*[rows];
                        break;

            case UINT   : ptrUI = new unsigned int*[rows];
                        break;

            case ULONG  : ptrUL = new unsigned long*[rows];
                        break;

            case USHORT : ptrUS = new unsigned short*[rows];
                        break;

            case UCHAR  : ptrUC = new unsigned char*[rows];
                        break;

            case INT     : ptrI = new int*[rows];
                           break;

            case DOUBLE  : ptrD = new double*[rows];
                           break;

            case FLOAT   : ptrF = new float*[rows];
                           break;

            case CHAR    : ptrC = new char*[rows];
                           break;

            case BOOL    : ptrB = new bool*[rows];
                           break;

            default      : cout<<"ERROR in creating array"<<endl;
                           exit(1);
        }
        for(int i = 0; i < rows; i++)
            switch(which)
            {

                case LONG   : ptrL[i] = new long[cols]();
                            ptr = (void**)ptrI;
                            break;

                case SHORT  : ptrS[i] = new short[cols]();
                            ptr = (void**)ptrI;
                            break;

                case UINT   : ptrUI[i] = new unsigned int[cols]();
                            ptr = (void**)ptrI;
                            break;

                case ULONG  : ptrUL[i] = new unsigned long[cols]();
                            ptr = (void**)ptrI;
                            break;

                case USHORT : ptrUS[i] = new unsigned short[cols]();
                              ptr = (void**)ptrI;
                            break;

                case UCHAR  : ptrUC[i] = new unsigned char[cols]();
                              ptr = (void**)ptrI;
                            break;

                case INT     : ptrI[i] = new int[cols](); //with parentheses initialize all elements to zero
                               ptr = (void**)ptrI;
                               break;

                case DOUBLE  : ptrD[i] = new double[cols]();
                                   ptr = (void**)ptrD;
                                   break;

                case FLOAT   : ptrF[i] = new float[cols]();
                                   ptr = (void**)ptrF;
                                   break;

                case CHAR    : ptrC[i] = new char[cols]();
                                   ptr = (void**)ptrC;
                                   break;

                case BOOL    : ptrB[i] = new bool[cols]();
                                   ptr = (void**)ptrB;
            }



}

bool again(string title)
{
    string answer;
    cout<<endl<<title;
    cin.ignore();
    getline(cin,answer);
    return toupper(answer[0]) == 'Y';
}

int getInput(string title, int minimum,int maximum)
{
    int value;
    bool repeat = true;
    while(repeat)
    {
        cout<<title;
        cin>>value;
        repeat = value < minimum || value > maximum;
    }
    return value;
}


void rollDice(int** dice,int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        int  times = (int)pow(10.,i);
        for(int j = 0; j < times; j++)
        {
            int die1 = 1 + rand()%6,
                die2 = 1 + rand()%6,
                sum = die1 + die2 - 2;
            dice[i][sum]++;
        }
    }
}


void computeOdds(double** odds,  int **rolls, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        int times = (int)pow(10., i);
        for(int j = 0; j < cols; j++)
            odds[i][j] = 100.*rolls[i][j]/times;
    }
}

void printRolls(int **rolls, int rows, int cols)
{
    cout<<endl<<"The odds of rolling dice"<<endl
        <<"First column represents the number of rolls "
        <<"in powers of 10"<<endl;
    int colWidth = rows + 3;
    cout<<setw(3)<<"|";
    for(int i = 2; i <=12; i++)
        cout<<setw(colWidth)<<i;
    cout<<endl
        <<setw(11*colWidth + 3)<<setfill('-')<<"-"
        <<setfill(' ')<<endl;
    for(int i = 0; i < rows; i++)
    {
        cout<<setw(2)<<i<<"|";
        for(int j = 0; j < cols; j++)
            cout<<setw(colWidth)<<rolls[i][j];
        cout<<endl;
    }

}

void printOdds(double **odds, int rows, int cols)
{
    cout<<endl<<"The odds of rolling dice"<<endl
        <<"First column represents the number of rolls "
        <<"in powers of 10"<<endl;

    cout<<setw(3)<<"|";
    for(int i = 2; i <=12; i++)
        cout<<setw(7)<<i;
    cout<<endl
        <<setw(80)<<setfill('-')<<"-"
        <<setfill(' ')<<endl;
    for(int i = 0; i < rows; i++)
    {
        cout<<setw(2)<<i<<"|";
        cout<<setprecision(2)<<fixed<<showpoint;
        for(int j = 0; j < cols; j++)
            cout<<setw(6)<<odds[i][j]<<"%";
        cout<<endl;
    }

}

void delete2DArray(void * * rolls, int rows, TYPE which) {
    switch (which) {
        case LONG:
            long ** dptr = (  long**) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case SHORT:
            short ** dptr = ( short** ) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case UINT:
            unsigned int ** dptr = (  unsigned int**) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case ULONG:
            unsigned long ** dptr = (  unsigned long**) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case USHORT:
            unsigned short ** dptr = (  unsigned short**) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case UCHAR:
            unsigned char ** dptr = (  unsigned char**) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case INT:
            int ** dptr = ( ** int) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case DOUBLE:
            double ** dptr = ( ** double) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case FLOAT:
            float ** dptr = ( ** float) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case CHAR:
            char ** dptr = ( ** char) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        case BOOL:
            bool ** dptr = ( ** bool) rolls;
            for (int i = 0; i < rows; i++) delete[] dptr[i];
            delete[] dptr;
            break;
        default:
            cout << "ERROR in deleting array" << endl;
            exit(1);
    }
}

/////////mixed
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "mixednumber.h"


using namespace std;

bool getLine(string &line);
void getInput(const string &line, mixedNumber &x, char &op,mixedNumber &y);
void trim(string &line);
mixedNumber getValue(string &line);
void output(mixedNumber x, char op, mixedNumber y, mixedNumber z);
void calculate(const mixedNumber &x, char op, const mixedNumber &y, mixedNumber &z);
mixedNumber add(const mixedNumber &x, const mixedNumber &y);
mixedNumber sub(const mixedNumber &x, const mixedNumber &y);
mixedNumber mult(const mixedNumber &x, const mixedNumber &y);
mixedNumber div(const mixedNumber &x, const mixedNumber &y);
mixedNumber getImproper(mixedNumber frac);
double getDecimal(mixednumber frac);


int main()
{
    mixedNumber x, y, z;
    char op;
    string line;
    while(getLine(line))
    {
        getInput(line, x, op, y);
        //calculate(x,op,y,z);
        //output(x,op,y,z);
        z = getImproper(x);
        cout << "whole: " << z.whole << " numer: " << z.num << " denom: " << z.denom;
    }
    return 0;
}

mixedNumber add(const mixedNumber &x, const mixedNumber &y)
{
    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num)*y.denom + (y.whole*y.denom+y.num)*x.denom;
    ans.denom = x.denom * y.denom;
    ans.reduce();
    return ans;
}

mixedNumber sub(const mixedNumber &x, const mixedNumber &y)
{
    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num)*y.denom - (y.whole*y.denom+y.num)*x.denom;
    ans.denom = x.denom * y.denom;
    ans.reduce();
    return ans;
}

mixedNumber mult(const mixedNumber &x, const mixedNumber &y)
{
    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num) * (y.whole*y.denom+y.num);
    ans.denom = x.denom * y.denom;
    ans.reduce();
    return ans;
}

mixedNumber div(const mixedNumber &x, const mixedNumber &y)
{
    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num) * y.denom;
    ans.denom = x.denom * (y.whole*y.denom+y.num);
    ans.reduce();
    return ans;
}

mixedNumber POWE(const mixedNumber &x, const mixedNumber &y){
    
    mixedNumber ans;
    ans.num = pow(x.num, y.num);
    ans.denom = pow(x.denom, y.num);
    y.num = 1;
    
    double decans, decy;
    decans = getDecimal(ans);
    decy = getDecimal(decy);
    double answer = pow(decans, decy);
    
    mixedNumber ret_val;

 
}



void calculate(const mixedNumber &x, char op, const mixedNumber &y, mixedNumber &z)
{
    switch(op)
    {
        case '+' : z = add(x,y);
                   break;
        case '-' : z = sub(x, y);
                   break;
        case '*' : z = mult(x, y);
                   break;
        case '/' : z = div(x, y);
                    break;
        case '^' : //z = POW(x, y);
                    break;
        default  : cout<<"unknown operator!"<<endl;
    }
}


void output(mixedNumber x, char op, mixedNumber y, mixedNumber z)
{
    x.output();
    cout<<" "<<op<<" ";
    y.output();
    cout<<" =  ";
    z.output();
    cout<<endl;
}


void trim(string &line)
{
    while(line[0] == ' ')
        line.erase(0,1);
    while(line[line.size()-1] == ' ')
        line.erase(line.size()-1);
}

bool getLine(string &line)
{
    cout<<"Input: ";
    getline(cin,line);
    trim(line);
    return line != "";
}


mixedNumber getValue(string &line)
{
    stringstream ss;
    char junk;
    mixedNumber x;
    x.whole = 0;
    x.num = 0;
    x.denom = 1;
    ss<<line;
    if(line.find(' ') < line.size()) //Do I have a true mixed number
        ss>>x.whole>>x.num>>junk>>x.denom;//Yes, read in
    else
        if(line.find('/') < line.size()) //If not, then do I have just a fraction
        {
            x.whole = 0;
            ss>>x.num>>junk>>x.denom; //If so, read it in
        }
        else //If not, all I have is a whole number, so read it in.
        {
            x.num = 0;
            x.denom = 1;
            ss>>x.whole;
        }
    return x;
}

void getInput(const string &line, mixedNumber &x, char &op,mixedNumber &y)
{
    char data;
    string first, second;
    stringstream ss;
    int pos = line.find_first_of("+*-");
    if(pos < line.size())
    {
        op = line[pos];
        first = line.substr(0,pos);
        x = getValue(first);
        second = line.substr(pos+1);
        y = getValue(second);
    }
    else
    {
        char junk;
        int num1, num2, num3;
        ss<<line;
        ss>>num1;
        if(ss.peek() == '/') // Dealing with a pure fraction
        {
            ss>>junk>>num2;
            x.whole = 0;
            x.num = num1;
            x.denom = num2;
            x.reduce();
        }
        else
            if(ss.peek() == ' ')
            {
                ss>>num2>>junk>>num3;
                x.whole = num1;
                x.num = num2;
                x.denom = num3;
                x.reduce();
            }
            else
            {
                x.whole = num1;
                x.num = 0;
                x.denom = 1;
            }
        ss>>op>>num1;
        if(ss.peek() == '/')
        {
            ss>>junk>>num2;
            y.whole = 0;
            y.num = num1;
            y.denom = num2;
            y.reduce();
        }
        else
            if(ss.peek() == ' ')
            {
                ss>>num2>>junk>>num3;
                y.whole = num1;
                y.num = num2;
                y.denom = num3;
                y.reduce();
            }
            else
            {
                y.whole = num1;
                y.num = 0;
                y.denom = 1;
            }

    }
}

mixedNumber getImproper(mixedNumber frac)
{


    if (frac.whole == 0){
        mixedNumber ret_val;
            ret_val.whole = 0;
            ret_val.num = frac.num;
            ret_val.denom = frac.denom;
        return ret_val;
    }else {
        mixedNumber ret_val;
           ret_val.whole = 0;
           ret_val.num = frac.whole*frac.denom;
           ret_val.num += frac.num;
           ret_val.denom = frac.denom;
       return ret_val;

    }

}

double getDecimal(mixedNumber frac){
    mixedNumber ret_val = getImproper(frac);
    return ret_val.num/ret_val.denom;
}

/////////////////////////////////////array union

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

union pointers
{
    int **ptrI;
    char **ptrC;
    double **ptrD;

    unsigned char **ptrUC;
    unsigned int **ptrUI;
    unsigned double **ptrUD;

    long **ptrL;
    short **ptrS;
    unsigned long **ptrUL;
    unsigned short **ptrUS;

};

enum TYPE {INT, DOUBLE, CHAR, UCHAR, UINT, UDOUBLE, LONG, SHORT, ULONG, USHORT};
pointers create2Darray(int rows, int cols,  TYPE type);

int main()
{
    int **myList;
    myList = create2Darray(5,5, INT).ptrI;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout<<myList[i][j];
        cout<<endl;
    }
    return 0;
}

pointers create2Darray( int rows, int cols, TYPE type)
{
    pointers ptr;
    switch(type)
    {
        case INT:
                    ptr.ptrI = new int*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrI[i] = new int[cols]();

                    }
                    return ptr;
                    break;
        case DOUBLE:
                    ptr.ptrD = new double*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrD[i] = new double[cols]();

                    }
                    return ptr;
                    break;
        case CHAR:
                    ptr.ptrC = new char*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrC[i] = new char[cols]();

                    }
                    return ptr;
                    break;
        case UCHAR:
                    ptr.ptrUC = new unsigned char*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrUC[i] = new unsigned char[cols]();

                    }
                    return ptr;
                    break;
        case UINT:
                    ptr.ptrUI = new unsigned int*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrUI[i] = new unsigned int[cols]();

                    }
                    return ptr;
                    break;

        case UDOUBLE:
                    ptr.ptrUD = new unsigned double*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrUD[i] = new unsigned double[cols]();

                    }
                    return ptr;
                    break;

       case LONG:
                    ptr.ptrL = new long*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrL[i] = new long[cols]();

                    }
                    return ptr;
                    break;

      case SHORT:
                    ptr.ptrS = new short*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrS[i] = new short[cols]();

                    }
                    return ptr;
                    break;

      case ULONG:
                    ptr.ptrUL = new unsigned long*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrUL[i] = new unsigned long[cols]();

                    }
                    return ptr;
                    break;

     case USHORT:
                    ptr.ptrUS = new unsigned short*[rows];
                    for(int i = 0; i < rows; i++)
                    {
                        ptr.ptrUS[i] = new unsigned short[cols]();

                    }
                    return ptr;
                    break;
    }
}


////////////////////////////////////////////////
//mixednumbers.h

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
        long numImproper, denomImproper;

        double decimal_val;

        void decimal_val_set();
        void setImproper();

    public:

        mixedNumber();

        void reduce();
        void output();



        double getImproper();

        long gcd(int x, int y);
        long getWhole();
        long getNumerator();
        long getDenominator();


        void setWhole();
        void setNumerator();
        void setDenominator();



        friend mixedNumber operator+ (mixedNumber &x, mixedNumber &y);
        friend mixedNumber operator- (mixedNumber &x, mixedNumber &y);
        friend mixedNumber operator* (mixedNumber &x, mixedNumber &y);
        friend mixedNumber operator/ (mixedNumber &x, mixedNumber &y);
        friend mixedNumber operator^ (mixedNumber &x, mixedNumber &y);




};



#endif // MIXEDNUMBERS_H

/////////////////
//.cpp

#include "mixednumbers.cpp"

mixedNumber::mixedNumber()
{
    whole = 0;
    num = 0;
    denom = 1;
}

void mixedNumber::reduce()
{
    int div, newNum;
    newNum = abs(denom * whole + num);
    div = abs(gcd(newNum, denom));
    newNum /= div;
    denom /= div;
    whole = newNum / denom;
    num = newNum % denom;
}

long mixedNumber::gcd(int p, int q)
{
    return q == 0 ? p : gcd(q, p%q);
}

/*
int mixedNumber::gcd(int p, int q)
{
    int r;
    while((r = p%q) != 0)
    {
        p = q;
        q = r;
    }
    return q;
)

    return
}
*/

void mixedNumber::output()
{
    if(whole == 0 && num == 0)
        cout<<0;
    else
      if(whole == 0)
        cout<<num<<"/"<<denom;
      else
         if(num == 0)
                cout<<whole;
         else
                cout<<whole<<" "<<num<<"/"<<denom;
}

long mixedNumber::getWhole(){
    return whole;

}

long mixedNumber getNumerator(){
    return num;
}

long mixedNumber::getDenominator(){
    return denom;
}

void mixedNumber::setWhole(long w){
    whole = w;
}

void mixedNumber::setNumerator(long q){
    num = q;
}

void mixedNumber::setDenominator(long q){
    denom = q;
}

mixedNumber mixedNumber::operator+ (mixedNumber &x, mixedNumber &y){

    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num)*y.denom + (y.whole*y.denom+y.num)*x.denom;
    ans.denom = x.denom * y.denom;
    ans.reduce();

    return ans;
}

mixedNumber mixedNumber::operator- (mixedNumber &x, mixedNumber &y){

    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num)*y.denom - (y.whole*y.denom+y.num)*x.denom;
    ans.denom = x.denom * y.denom;
    ans.reduce();
    return ans;
}

mixedNumber mixedNumber::operator* (mixedNumber &x, mixedNumber &y){

    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num) * (y.whole*y.denom+y.num);
    ans.denom = x.denom * y.denom;
    ans.reduce();
    return ans;
}

mixedNumber mixedNumber::operator/ (mixedNumber &x, mixedNumber &y){

    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num) * y.denom;
    ans.denom = x.denom * (y.whole*y.denom+y.num);
    ans.reduce();
    return ans;
}

mixedNumber mixedNumber::operator^ (mixedNumber &x, mixedNumber &y){

    mixedNumber x_temp = getImproper(x);
    mixedNumber y_temp = getImproper(y);


    mixedNumber power_root = getImproper(y);
    power_root.whole = 0;
    power_root.num = 1;

    double dec_to_raise_root = getDecimal(power_root);

    double numer_temp = pow(x_temp.num, dec_to_raise_root);
    double denom_temp = pow(x_temp.denom, dec_to_raise_root);

    double frac_to_convert = numer_temp / denom_temp;

    frac_to_convert = pow(frac_to_convert, y_temp.num);

    mixedNumber ret_val = double_to_fraction(frac_to_convert);

    return ret_val;
}

double mixedNumber::decimal_val_set(){

}

void mixedNumber::setImproper(){

    if (whole == 0){

                numImproper = num;
                denomImproper = denom;
        }else {

               numImproper = whole*denom;
               numImproper += num;
               denomImproper = denom;
        }
}

mixedNumber mixedNumber::getImproper(){
    mixedNumber mix();

    mix.setWhole(0);
    mix.setNumerator(0);
    mix.setDenominator(0);

}

/*double mixedNumber::decimal_val_set(){

    if (dec > 0){

        mixedNumber temp;
        temp.whole = trunc(dec);
        double decDecimal = abs(trunc(dec) - dec);
        int number_to_raise = get_num_of_places(decDecimal);
        int numerator = decDecimal * pow(10, number_to_raise);
        int denominator =  pow(10, number_to_raise);

        temp.num = numerator;
        temp.denom = denominator;
        return temp;

    }else {
        mixedNumber temp;
        temp.whole = trunc(dec);
        double decDecimal = abs(trunc(dec) - dec);
        int number_to_raise = get_num_of_places(decDecimal);
        int numerator = decDecimal * pow(10, number_to_raise) * -1;
        int denominator =  pow(10, number_to_raise);

        temp.num = numerator;
        temp.denom = denominator;
        return temp;
    }

}*/


//////
 stringstream sline;
    int ro = 0, co = 0;

    string line;
    cout << "\n";

    getline(in, line);
    sline.str(line);

    getline (sline, line, 'x');

    ro = atoi(line.c_str());

    getline(sline, line);
    co = atoi (line.c_str() );
    sline.str("");
    line.clear();



