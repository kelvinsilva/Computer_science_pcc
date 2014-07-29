#include "parsefuncs.h"

bool fileExists(const char *filename){

    ifstream check (filename);

    if (check.good()){
        check.close();
        return true;
    }else
        return false;

}

void parseCommandLine(int argc,char *argv[], ifstream *in, ofstream &out, char &operation,  mixedNumber* &soln_matrix){

    //First step, check if there are any /h or /? characters in argument list
    //If there are, then we defer to the help prompt and exit the program.

    operation = 0; //If we happen to fall through the entire loop without hitting any of the conditions, then we will defaulty throw an syntax error/

    //Some special cases to be tested first:
    if (argc == 1){ //If we only have one argument, then exit.
        operation = 0; //Code zero for help prompt
        return; //Exit function
    }else if (argc == 2){ // If we only have for example: matrix mat1.mat, we need to open that file for editing.
        operation = 'e'; //Check the twodarray.cpp file to see how cin handles the edit

        out.open( clean_name(argv[1]).c_str() );
        return;
    }

    bool force_overwrite = false;

    for (int i = 0; i < argc; i++){

        if ( string(argv[i]) == "/h" || string(argv[i]) == "/?" ){ //Recall that strcmp returns 0 if strings match
            operation = 0; //Code zero for help prompt
            return; //Exit this function
        }else if (string(argv[i]) == "/f"){ //Also check for /f tokens
            force_overwrite = true;
        }

    }

    int i = 0;

    for (; i < argc; i++){ //we have

        if  ( (string(argv[i]) == "add" || string(argv[i]) == "subtract" || //find the place in between operators, ONLY if our argument count is greater than or equal to 4
             string(argv[i]) == "multiply") && argc >= 4 ){     //Because the syntax for add can ONLY be "matrix mat1.mat add mat2.mat" or also aspecify output  (argc MUST be >= 4)
                                                                //If there are three arguments, it can only be a syntax error, or a Inverse operation.


                    if ( i != 2 ){ //if we encounter our operators at the beginning of argument list or at the very end, then it is a syntax error.
                                                //The operators MUST be in between two filenames.
                        operation = 0;
                        break;

                    }else{

                        operation = argv[i][0]; //for add, assign a, subtract, assign letter s, multiply assign letter m
                        in[0].open(argv[i-1]);
                        in[1].open(argv[i+1]);

                    }

                 if ( argc > 4 ){ //If we have an output....

                     if (fileExists(argv[i+2])){ //and this file already exists...

                            if (force_overwrite){   //and we are forced to overwrite it

                                out.open( clean_name(string(argv[i+2])).c_str());
                            }else{                  //if we are not forced to overwrite it...

                                promptOpen( out, clean_name(string(argv[i+2])).c_str() );   //Prompt the user
                            }

                     }else { //If the file does not already exist, write it, regardless if we are forced or not

                                out.open( clean_name(string(argv[i+2])).c_str());

                     }
                 }



        }else if ( string(argv[i]) == "gelim" && argc >= 4){ //User MUST specify "matrix mat1.mat gelim (1, 2, 3)" or an output file (similar syntax to add

                if (i != 2 ){ //if we encounter our operator at the beginning of argument list or at the very end, then it is a syntax error.
                                                //The operators MUST be in between two filenames or tokens.
                        operation = 0;
                        break;
                }

                operation = argv[i][0]; //assign letter g for operation
                in[0].open(argv[i-1]);

                bool is_ok = parse_mixedInput(argv[i+1], soln_matrix);
                    if (!is_ok){ //If parse_mixedInput encountered an error, then we complain.
                        operation = 0;
                        break;
                    }

                 if ( argc > 4 ){ //If we have an output....

                     if (fileExists(argv[i+2])){ //and this file already exists...

                            if (force_overwrite){   //and we are forced to overwrite it

                                out.open( clean_name(string(argv[i+2])).c_str());
                            }else{                  //if we are not forced to overwrite it...

                                promptOpen( out, clean_name(string(argv[i+2])).c_str() );   //Prompt the user
                            }

                     }else { //If the file does not already exist, write it, regardless if we are forced or not

                                out.open( clean_name(string(argv[i+2])).c_str());

                     }
                 }


        }else if (string(argv[i]) == "inverse" && argc >= 3){
             if ( i!=2 ){ //if we encounter our operator at the beginning of argument list or at the very end, except if we have an output file  then it is a syntax error.
                                                    //The operators MUST be in between two filenames or tokens.
                 //matrix mat1.mat mat2.mat inverse is a syntax error
                 //but... matrix mat1.mat inverse is not a syntax error even though both have inverse operation on last side.
                  operation = 0;
                  break;
             }
             operation = argv[i][0]; //Assign letter i to operation.

             in[0].open(argv[i-1]);

            //We can only open the file if there are more than 3 arguments--> test1 mat1.mat inverse mat2.mat
             if (fileExists(argv[i+1]) && argc > 3){ //and this file already exists..., if argc is greater than 3 then we have an output file

                    if (force_overwrite){   //and we are forced to overwrite it

                         out.open( clean_name(string(argv[i+1])).c_str());
                    }else{                  //if we are not forced to overwrite it...

                         promptOpen( out, clean_name(string(argv[i+1])).c_str());
                    }

            }else if (argc > 3){ //If the file does not already exist, write it, regardless if we are forced or not

                         out.open( clean_name(string(argv[i+1])).c_str());
            }

        }


        }

}

bool parse_mixedInput(const char *input, mixedNumber* &soln_array){

    string input_val = string(input);
    //cout << input_val;
    int wordcount = 0;
    int comma_count = 0;


    for (int i = 0; i < input_val.length(); i++){
        if (input_val[i] == ','){ //Count the number of mixed numbers we have based on commas.

            comma_count++; //Replace the comma with a \n because the delimiter of mixednumber input is a \n
        }else if (!isdigit(input_val[i]) && input_val[i] != '/' &&
                  input_val[i] != ',' && input_val[i] != ' ' &&
                  input_val[i] != '+' && input_val[i] != '-' ){ //Check for anything that is not a number or a or a whitespace,
                                                                                                                //slash or a comma, if we find something nondigit and nonslash then its a syntax error
            return false;
        }
    }

    wordcount = comma_count + 1; //The number of mixed numbers taht we have is always 1 more than the amount of commas.
    //cout << "wordcount " << wordcount;
    soln_array = new mixedNumber[wordcount]();

    char junk = 0;

    stringstream ss;
    ss.str(input_val);

    for ( int i = 0; i < comma_count; i++){ //Keep feeding in solutions.

        ss >> soln_array[i] >> junk;

        //cout << "ss: " << ss.str() << endl;
    }
    //cout <<
    ss >> soln_array[comma_count]; //the last element is parse outside the loop since there is no >>junk
    return true;
}


void promptOpen(ofstream &fo, string filename){

    string response = "";
    bool good = true;

    cout << "\n Do you want to overwrite this file (Y/N)? ";

    do {
        getline (cin, response);

        if (response == "y" || response ==  "Y"){
            fo.open(filename.c_str());
            good = false;
        }else if (response == "n" || response == "N"){
            good = false;
        }else cout << "\nPlease enter a Y or N: ";

    }while (good);

}

string clean_name(string filename){

    string ret_val;
    int pos = filename.find('.');
    if (pos != string::npos){ //If we do not find any '.', find function returns string::npos
        ret_val = filename.substr(0, pos); //So then !npos means we found something, so append to filename everything except the file extension
    }else {
        ret_val = filename;     //if we did not find anything just append the filename.
    }

    ret_val.append(".mat");

    return ret_val;
}


