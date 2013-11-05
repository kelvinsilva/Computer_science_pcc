//Kelvin Silvaxx
#include <iostream>
#include <fstream>

#include "string_manip.h"
#include "token_manip.h"

using namespace std;

    char ALPHA_NUMERIC_TEST[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";
    char PUNCTUATION_TEST[] = ",<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";
    char WHITE_SPACE_TEST[] = " ";
    char TEST_NEWLINE[] = "\n";

bool extract_block_file(ifstream &read_file, char block[], int size_read = BLOCK_MAX_SIZE){

    read_file.read(block, size_read-1); //avoid off by one error
    block[read_file.gcount()] = '\0';
    return !read_file.eof();

}

int main(){

    char char_table[TOKEN_MAX_COUNT][TOKEN_MAX_SIZE]{}; //Can store 4096 tokens each with a size of 64
    char block[BLOCK_MAX_SIZE];

    int statistics[5]{}; //index 0 is token count, index[type] is the type of token counted
    char FILE_NAME[512]{};

    ifstream read_file;

    do{

        cout << "\nEnter FileName: " << endl;
        cin >> FILE_NAME;
        read_file.open(FILE_NAME);

        if (read_file.fail()){
            cout << "\nError, bad file name" << endl;
        }

    }while(read_file.fail());
    read_file.clear();

    cout << "Tokens are displayed below.";

    while(extract_block_file(read_file, block)){

        TokenizeBlock(block, char_table, statistics);
        for (int i = 0; i < statistics[0]; i++){

            cout << char_table[i];
        }
    }

    cout << "\n\nTotal tokens found: " << statistics[0] << "\n\nAlphaNumeric Tokens: " << statistics[1]
         << "\n\nPunctuation character found: " << statistics[2] << "\n\nPress Enter to exit";

    cin.get();
    read_file.close();


  //  cout << "Enter File Name: ";
   // cin.getline(file_Name, 512, '\n');
    //cin.ignore();

    //TokenizeFile()

}
