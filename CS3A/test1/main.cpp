#include <iostream>

#include "mixedNumbers.h"
#include "twodarray.h"
#include "operationfuncs.h"
#include "parsefuncs.h"

using namespace std;

enum MAINERROR {DIMENSION};


void help();
void promptOpen(ofstream &fo, string filename);





int main(int argc, char *argv[]){

    two2Darray left("mixed");
    two2Darray right("mixed");
    two2Darray solution("mixed");
    mixedNumber *soln_array;

    ifstream *in = new ifstream[2];
    ofstream out;

    char operation;

    parseCommandLine(argc, argv, in, out, operation, soln_array);

    if (in[0].is_open())
        in[0] >> left;

    if (in[1].is_open())
        in[1] >> right;

    solution.resize(left.getCols(),left.getRows());

    if (operation == 'g')
        for(int i=0;i<left.getRows();i++){
            solution[i][0] = soln_array[i];
           cout << endl << "Solution: " << solution[i][0];
        }

    //After the switch, then associate out with solution matrix.


    switch(operation){

    case 'a'  : //addd
                {
                    if ( in[0].is_open() && in[1].is_open()){
                        cout << "\nleft matrix:\n";
                        left.printContents(cout);
                        cout << "\n\nRight matrix\n\n";
                        right.printContents(cout);

                        add (left, right, solution);
                        //cout << "\nProcessed Add\n";//Tracer
                        cout << "\n\nAddition: Solution:\n";
                    }else {
                        help();
                    }
                    out << solution;//print my solution
                }
                break;

        case 'm'  : //Multiply;
            {
                if ( in[0].is_open() && in[1].is_open()){
                    cout << "\nleft matrix:\n";
                    left.printContents(cout);
                    cout << "\n\nRight matrix\n\n";
                    right.printContents(cout);

                    multiplyMatrices (left, right, solution);
                    //cout << "\nProcessed Multiply\n";//Tracer
                    cout << "\n\nMultiply: Solution:\n";
                }else {
                    help();
                }
                out << solution;//print my solution
            }
            break;
        case 's'  : //Subtract;
            {
                if ( in[0].is_open() && in[1].is_open()){
                    cout << "\nleft matrix:\n";
                    left.printContents(cout);
                    cout << "\n\nRight matrix\n\n";
                    right.printContents(cout);

                    subtract (left, right, solution);
                    //cout << "\nProcessed Subtract\n";//Tracer
                    cout << "\n\nSubtration: Solution:\n";
                }else { //One of the instreams not open...
                    help();
                }
                out << solution;//print my solution
            }
            break;
        case 'g' : //gaussian elimination;
            {
                if (in[0].is_open()){
                    cout<< "\nMatrix:\n";
                    left.printContents(cout);

                    Gaussian_Elimination(left, solution);

                    cout << "\nProcessed Gaussian Elimination\n";
                }
                out << solution;//print my solution
            }
            break;
        case 'i' : //Inverse;
            {
                if(in[0].is_open()){
                cout<< "\nMatrix:\n";
                left.printContents(cout);

                invertMatrices(left, solution);
                cout << "\nProcessed Inverse\n";
                }
                out << solution; //print my solution
            }
            break;
        case 'e' : //Editing;
            {
                if (edit(left) == true); //if editing was success
                    out << left;
            }
        default :
            { //Help
                help();

            }

    }
    solution.printContents(cout);


    if (out.is_open()){
        out.close();
    }

    if (in[0].is_open())
        in[0].close();

    if (in[1].is_open())
        in[1].close();

   return 0;
}



void help()
{
    cout << "Usage: [/h] [/f]\n/h\tHelp\n/f\tForce Overwrite (Inclusion of /f will not prompt file overwrite)\n\nNOTE: Inclusion of output file is optional.\n";
        cout << "\nBinary operations:\n\tmatrix <left(.mat)> OPERATION <right(.mat)> <output(.mat)>";
        cout << "\n\nSingle Operand Operations:\n\t matrix <left(.mat)> OPERATION <output(.mat)>";
        cout << "\n\nGaussian Elimination:\n\tmatrix <left(.mat)> gelim \"solution_values\" <output(.mat)>";
        cout << "\n\nOPERATION:\n\tadd\n\tsubtract\n\tmultiply\n\tinverse";
        cout << "\n\nExample Invocations:\n\tBinary Operation:\t  matrix left.mat add right.mat output.mat /f";
        cout << "\n\tSingle Operand Operation: matrix left.mat inverse output.mat";
        cout << "\n\tGaussian Elimination:     matrix rref.mat gelim \"2,3,-1 1/2\" output.mat";
}
