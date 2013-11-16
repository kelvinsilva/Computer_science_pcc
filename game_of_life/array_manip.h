#ifndef ARRAY_MANIP_H_
#define ARRAY_MANIP_H_

#include <iostream>
#include "rule.h"

using namespace std;

void sub_board(int board[][WORLDSIZE], int boardsub[][3], int i, int j);
void display_board(int board[][WORLDSIZE]); //convert integer values to graphical characters
void copy_board(int dest[][WORLDSIZE], int src[][WORLDSIZE]);   //copy one array to another array

void init_board(int board[][WORLDSIZE]); //Initializes an empty board 29 by 20 with all dead cells and borders around board


#endif // ARRAY_MANIP_H_
