#include "operationfuncs.h"

bool edit(two2Darray &left){

        int r = 0, c = 0;
        string rs = "", cs = "";
        cout << "Enter how many rows you want to edit or create: ";
        getline(cin, rs);
        if (rs.find_first_not_of("123456789") != string::npos){ //Quick way to check crappy input
            cout << "ERROR! Aborting"; //If i find stuff that is not numeric, then i tell the user that there is an error and i abort the program
            return false;
        }else r = atoi(rs.c_str()); //a to i, alphabet to integer. converts "1234" to 1234


        cout << "Enter how many columns you want to edit or create: ";
        getline(cin, cs);
        if (cs.find_first_not_of("123456789") != string::npos){
            cout << "ERROR! Aborting";
            return false;
        } else c = atoi(cs.c_str());

        left.resize(r, c); //resize to appropriate row and col

        cout << "Entering a " << r << "x" << c << " array\n";
        cout << "Enter each row, with elements separated by commas\n";
        cout << "Do not enter spaces in between comma values\n";
        for (int i = 0; i< r; i++){

            cout << "Row " << i << " : "; //for each row...
            cin >> left[i]; //i dereference a safearray element and call its extraction operator

        }
        return true;
}


void add (two2Darray &arr1, two2Darray &arr2, two2Darray &arrRes){
    int rows = 0, cols = 0;

    rows = arr1.getRows();
    cols = arr1.getCols();

    for (int i = 0; i < rows; i++){

        for (int j = 0; j < cols; j++){

            arrRes[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return;
}

void subtract (two2Darray &arr1, two2Darray &arr2, two2Darray &arrRes){
    int rows = 0, cols = 0;

    rows = arr1.getRows();
    cols = arr1.getCols();

    for (int i = 0; i < rows; i++){

        for (int j = 0; j < cols; j++){

            arrRes[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    return;
}


void multiplyMatrices (two2Darray &arr1, two2Darray &arr2, two2Darray &arrRes)
{   //This function will only work for square matrices, where the colsize and rowsize are constant. **Maybe a matrix class with dimensions should be implemented
    //so that this matrix can be integrated to format into any dimensions.
    int rowsize = arr1.getRows(), colsize = arr1.getCols();
    for(int i=0; i<rowsize; i++)
    {
        for(int j=0; j<colsize; j++)
        {
            for(int k=0; k<rowsize; k++){    //<- this will run through each col and row to find the multiplicitive values
                arrRes[i][j] += arr1[i][k]*arr2[k][j];  //<- follows the algorithim c[0,0] = a[0,n]+b[n,0] ... Temptotal will sum itself.
                //cout<<"\nSolution at "<<i<<" "<<j<<" = "<<arrRes[i][j]<<endl; //TRACETRACE
            }
        }
    }
}

void invertMatrices (two2Darray &arr,two2Darray &arrRes)
{
    int rows = arr.getRows();
    for(int i=0; i<rows;i++) arrRes[i][i] = 1;
    Gaussian_Elimination(arr,arrRes);
}

void Gaussian_Elimination(two2Darray &arr, two2Darray &arrRes)
{
    int rows = arr.getRows(), cols = arr.getCols();
    for(int i=0;i<cols;i++)
    {
        //while(matrix[i][i] == 0) rearrangeRows(matrix,sol,i);//This is optional
        makeLeadingOnes(arr, arrRes, rows, i);
        reduceLowerTriangular(arr, arrRes, rows, cols, i);
    }
    for(int i=rows-1;i!=0;i--)
        reduceUpperTriangular(arr, arrRes, rows, cols, i);
}


void makeLeadingOnes(two2Darray &arr, two2Darray &arrRes, int rows, int pos)
{   //pos is the most important part of this.
    arr.printContents(cout);

    for(int i=0;i<arr.getRows();i++)
    {
        for(int j=0;j<arr.getCols();j++)
        {
            arr[i][j] = arr[i][j] / arr[i][0];
            cout<<endl<<arr[i][j];
            arrRes[i][j] = arrRes[i][j] / arr[i][0];
            cout<<endl;
        }
    }
    arr.printContents(cout);
    arrRes.printContents(cout);
}

void reduceLowerTriangular(two2Darray &arr, two2Darray &arrRes, int rows, int cols, int pos)
{

    for(int i=0;i<rows-1;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr[i+1][j] = arr[i+1][j] - arr[pos][j];
            arrRes[i+1][j] = arrRes[i+1][j] - arrRes[pos][j];
        }
    }

}

void reduceUpperTriangular(two2Darray &arr, two2Darray &arrRes, int rows, int cols, int pos)
{

    for(int i=rows-1;i!=1;i--)
        for(int j=cols-1;j!=0;j--)
        {
            arr[i-1][j] = arr[i-1][j] - arr[pos][j] ;
            arrRes[i-1][j] = arrRes[i-1][j] - arrRes[pos][j] ;
        }
}

