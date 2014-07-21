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
    two2Darray solution("Mixed");

    ifstream *in = new ifstream[2];
    ofstream out;
    mixedNumber *soln_array;
    char operation;


    parseCommandLine(argc, argv, in, out, operation, soln_array);




    if (in[0].is_open())
        in[0] >> left;

    if (in[1].is_open())
        in[1] >> right;

    //After the switch, then associate out with solution matrix.



    switch(operation){

        case 'a'  : //addd
            {
                if ( in[0].is_open() && in[1].is_open()){
                    cout << "add";
                    add (left, right, solution);
                }else {
                    help();
                }
                out << solution;//print my solution
            }
            break;

        case 'm'  : //Multiply;
            {
                if ( in[0].is_open() && in[1].is_open()){
                        cout << "smultiplyct";
                    //multiply (left, right, solution);
                }else {
                    help();
                }
                out << solution;//print my solution
            }
            break;
        case 's'  : //Subtract;
            {
                if ( in[0].is_open() && in[1].is_open()){
                        cout << "msubtract;";
                    //multiply (left, right, solution);
                }else { //One of the instreams not open...
                    help();
                }
                out << solution;//print my solution
            }
            break;
        case 'g' : //gaussian elimination;
            {
                if (in[0].is_open()){
                    //gelim(....)
                    cout << "gelimming";
                    cout << soln_array[0] << " " << soln_array[1];
                }
                out << solution;//print my solution
            }
            break;
        case 'i' : //Inverse;
            {
                if (in[0].is_open()){
                        cout << "inverse";
                    //inverse(....)
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


    if (out.is_open()){

        out.close();
    }

    if (in[0].is_open())
        in[0].close();

    if (in[1].is_open())
        in[1].close();

    delete [] soln_array;

   return 0;
}



void help()
{
   cout<<"\nPlease enter format in command line => infile1 (add/multiply) infiles2 outfile"
       <<"\nOr infile inverse outfile for inverse"
       <<"\nExcluding the outfile will still also work\n";
}
