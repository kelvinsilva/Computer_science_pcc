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

