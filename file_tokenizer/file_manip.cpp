#include "file_manip.h"

void Print2d(std::ostream &stream, char print_char[][TOKEN_MAX_SIZE], int row_ct){  //Outputs print_char tokens into ostream

    for (int i = 0; i < row_ct; i++){
        stream << print_char[i] << std::endl;
    }
}

bool /*getblock*/ extract_block_file(std::fstream &read_file, char block[]){ //Extracts block using istream::read

    read_file.read(block, BLOCK_MAX_SIZE-1); //avoid off by one error
    block[read_file.gcount()] = '\0'; //Append null termination for safety
    return read_file.gcount() != 0;
}

void Open_File_Prompt(std::fstream &ofn){

     char FILE_NAME[512] = {};

     //Poll for valid filename
     do{

        std::cout << "\nEnter FileName: " << std::endl;
        std::cin >> FILE_NAME;
        ofn.open(FILE_NAME);

        if (ofn.fail()){
            std::cout << "\nError, bad file name" << std::endl;
        }
    }while(ofn.fail());
}
