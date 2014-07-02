//Kelvin Silva
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//3 = exit immediately, 0 = invalid syntax, 1 = help, 2 = copy, 4 = input or output file is missing
int ret_operation(int argc, char* argv[]);

void help();
void error(string st);
void copy_file(int argc, char* argv[]);

int main(int argc, char* argv[])
//int main(int argc, char argv[][]_
{

    int operation = ret_operation(argc, argv);

        switch (operation){

            case 3: break;

            case 0: error("Invalid syntax, Bad Option");
            break;

            case 1: help();
            break;

            case 2: copy_file(argc, argv);
            break;

            case 4: error("Input or output file not specified");


        }

    return 0;
}

void copy_file(int argc, char* argv[]){

        char *outfile_name = NULL;
        char *infile_name = NULL;

        for(int i = 0; i < argc; i++){


            //Test to see if -o /o -i /i exist in command line invocation
            if ( (!strcmp(argv[i], "-o") || !strcmp(argv[i], "/o"))){

                outfile_name = argv[++i];

            }

            if ( (!strcmp (argv[i], "-i") || !strcmp(argv[i], "/i"))){

                    infile_name = argv[++i];
            }

        }

        ifstream infile(infile_name, ifstream::binary);
        ofstream outfile(outfile_name, ofstream::binary|ofstream::trunc);

        if(!infile){

            error("Error, File Not Found, Aborting");
            infile.close();
            outfile.close();
            return;
        }

        outfile << infile.rdbuf();

        infile.close();
        outfile.close();

        return;
}

void help(){

    cout << "\nCPY: Copies the content of input file into output file."
         << "\nUsage: [-i filename] [-o filename] \n\nOptions:\n\n\t-i\t\t"
         << "Input file name\n\t-o\t\tOutput file name";

}

void error(string st){

    cerr << st;

}


int ret_operation(int argc, char* argv[]){

        for(int i = 0; i < argc; i++){

            if ( !strcmp(argv[i], "/h") || !strcmp(argv[i], "-h") || argc == 1){

                return 1;
                break;
            }

            //Test to see if -o /o -i /i exist in command line invocation
            if ( (!strcmp(argv[i], "-o") || !strcmp(argv[i], "/o")) || (!strcmp(argv[i], "-i") || !strcmp(argv[i], "/i")) ){

                for (int j = ++i; j < argc; j++){

                    if ( (!strcmp(argv[j], "-o") || !strcmp(argv[j], "/o")) || (!strcmp(argv[j], "-i") || !strcmp(argv[j], "/i")) ){

                        return  2;
                    }

                }
                //You have input but no ouput. or output but no input
                return 4;
                break;
            }

        }
        return 0;
}

