#ifndef FILE_MANIP_H_
#define FILE_MANIP_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include "token_manip.h"


void Print2d(std::ostream &stream, char print_char[][TOKEN_MAX_SIZE], int row_ct);   //outputs print_char 2d array to outstream
bool /*getblock*/ extract_block_file(std::fstream &read_file, char block[]);   //Extracts block from read_file through ifstream::read into char block[]
void Open_File_Prompt(std::fstream &ofn);   //Polling for valid filename

#endif
