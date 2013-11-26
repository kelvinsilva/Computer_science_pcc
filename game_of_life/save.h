#ifndef SAVE_H_
#define SAVE_H_

#include <iostream>

#include <fstream>
#include "rule.h"

using namespace std;
void Open_File_Prompt(fstream &ofn);
void out_file_board(fstream &fout, int board[][WORLDSIZE], int i, int j, int ii, int jj);
void out_file_board(fstream &fout, int board[][WORLDSIZE]);
void load_file(fstream  &fin, int board[][WORLDSIZE]);
#endif // SAVE_H_
