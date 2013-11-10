//Kelvin Silvaxx
#include <iostream>
#include <fstream>
#include <cstring>

#include "string_manip.h"
#include "token_manip.h"

using namespace std;

    char ALPHA_NUMERIC_TEST[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";
    char PUNCTUATION_TEST[] = ",<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";
    char WHITE_SPACE_TEST[] = " ";
    char TEST_NEWLINE[] = "\n";


void Print2d(ostream &stream, char print_char[][TOKEN_MAX_SIZE], int row_ct){

    for (int i = 0; i < row_ct; i++){
        stream << print_char[i] << endl;
    }

}

bool /*getblock*/ extract_block_file(ifstream &read_file, char block[], int size_read = BLOCK_MAX_SIZE){

    read_file.read(block, size_read-1); //avoid off by one error
    block[read_file.gcount()] = '\0';
    return read_file.gcount() == BLOCK_MAX_SIZE;

}

void TokenizeFile(ifstream &read_file, char char_table[][TOKEN_MAX_SIZE], int statistics[]){

    char block[BLOCK_MAX_SIZE] = {};
    int row_ct = 0;
    while(extract_block_file(read_file, block)){

        TokenizeBlock(block, char_table, statistics, row_ct);
    }
    cout << "Block: " << block;
    extract_block_file(read_file, block);
    TokenizeBlock(block, char_table, statistics, row_ct);
}


int main(){

    char char_table[TOKEN_MAX_COUNT][TOKEN_MAX_SIZE] = {}; //Can store 4096 tokens each with a size of 64
    int statistics[5]{}; //index 0 is token count, index[type] is the type of token counted

    char FILE_NAME[512] = {};


    ifstream read_file;
    ofstream out_file;

    do{

        cout << "\nEnter FileName: " << endl;
        cin >> FILE_NAME;
        read_file.open(FILE_NAME);

        if (read_file.fail()){
            cout << "\nError, bad file name" << endl;
        }

    }while(read_file.fail());

    do{
        cout << "\nEnter Output Filename: " << endl;
        cin >> FILE_NAME;
        out_file.open(FILE_NAME);

        if (out_file.fail()){
            cout << "\nError, bad file name" << endl;
        }
    }while (out_file.fail());

    read_file.clear();
    out_file.clear();

    TokenizeFile(read_file, char_table, statistics);


    cout << "Tokens are displayed below.";


    Print2d(cout, char_table, statistics[0]);
    cout << "\n\nTotal tokens found: " << statistics[0] << "\n\nAlphaNumeric Tokens: " << statistics[1]
         << "\n\nPunctuation character found: " << statistics[2] << "\nNumber of whitespace: " << statistics[3]
         << "\nNumber of newlines: " << statistics[4] << "\n\nPress Enter to exit";

    Print2d(out_file, char_table, statistics[0]);

    cin.get();
    read_file.close();


  //  cout << "Enter File Name: ";
   // cin.getline(file_Name, 512, '\n');
    //cin.ignore();

    //TokenizeFile()

}
