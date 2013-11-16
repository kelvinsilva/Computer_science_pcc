//Kelvin Silva
#include <iostream>
#include <fstream>
#include <cstring>

#include "string_manip.h"   //Lower level string manipulation functions
#include "token_manip.h"    //Higher level token manipulation functions
#include "file_manip.h"

//Table of tokenization lookup values
    char ALPHA_NUMERIC_TEST[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";
    char PUNCTUATION_TEST[] = ",<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";
    char WHITE_SPACE_TEST[] = " ";
    char TEST_NEWLINE[] = "\n";


int main(){

    using namespace std;

    char char_table[TOKEN_MAX_COUNT][TOKEN_MAX_SIZE] = {}; //Can store TOKEN_MAX_COUNT tokens each with a size of TOKEN_MAX_SIZE
    int statistics[5]{}; //index 0 is token count, index[type] is the type of token counted

    fstream read_file; //Read for tokens
    fstream out_file;   //Write for tokens

    Open_File_Prompt(read_file);
    Open_File_Prompt(out_file);

    cout << "Tokens are displayed below.";

    TokenizeFile(read_file, char_table, statistics);    //Process file

    Print2d(cout, char_table, statistics[0]);   //Output all tokens to console screen, statistics[0] represents token count
    Print2d(out_file, char_table, statistics[0]);   //Output all tokens into outfile, statistics[0] represents token count

    //Report statistics and analyzation of read_file
    //Statistics: Type 1 = alpha numeric, type 2 = punctuation, type 3 white spce, type 4 newline, Type 0 is token count
    cout    << "\n\nTotal tokens found: " << statistics[0] << "\n\nAlphaNumeric Tokens: " << statistics[1]
            << "\n\nPunctuation character found: " << statistics[2] << "\nNumber of whitespace: " << statistics[3]
            << "\nNumber of newlines: " << statistics[4] << "\n\nTokens are stored in out file\n\nPress Enter to exit....";

    //Write to outfile....
    out_file    << "\n\nTotal tokens found: " << statistics[0] << "\n\nAlphaNumeric Tokens: " << statistics[1]
                << "\n\nPunctuation character found: " << statistics[2] << "\nNumber of whitespace: " << statistics[3]
                << "\nNumber of newlines: " << statistics[4];

    read_file.close();  //Close
    out_file.close();

    cin.get();  //Wait for user newline to end program
    cin.get();

    return 0;
}
