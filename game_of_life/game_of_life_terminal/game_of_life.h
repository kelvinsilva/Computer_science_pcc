#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

#include <iostream>
#define WORLDSIZE  20

using namespace std;

void display_board(int board[][WORLDSIZE]); //convert integer values to graphical characters
void copy_board(int dest[][WORLDSIZE], int src[][WORLDSIZE]);   //copy one array to another array



void new_line(int siz);


void rule(int board[][WORLDSIZE], int board_temp[][WORLDSIZE], int subboard[][3]);
void sub_board(int board[][WORLDSIZE], int boardsub[][3], int i, int j);

int count_neighbor(int sub_board[][3]);

#endif // GAME_OF_LIFE_H_
