#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

#include <iostream>
#define WORLDSIZE 75 //WORLDSIZE is a square. so for example is worldsize is 10, it will be a 10X10 board with 100 members.

using namespace std;

void rule(int board[][WORLDSIZE], int board_temp[][WORLDSIZE], int subboard[][3]);
int count_neighbor(int sub_board[][3]);
void testit();
#endif // GAME_OF_LIFE_H_

/*

This program is split up into two function groups.
THe first function group is array manipulation functions which are used to display, submit values, and take a "sub array" of an array
array_manip.h consists of the following functions:


void sub_board(int board[][WORLDSIZE], int boardsub[][3], int i, int j);
void display_board(int board[][WORLDSIZE]); //convert integer values to graphical characters
void copy_board(int dest[][WORLDSIZE], int src[][WORLDSIZE]);   //copy one array to another array
void init_board(int board[][WORLDSIZE]); //Initializes an empty board 29 by 20 with all dead cells and borders around board

The second function group consists of the functions that  enforce game of life rules upon an array. They consist of the following functions:

void rule(int board[][WORLDSIZE], int board_temp[][WORLDSIZE], int subboard[][3]);

    Any live cell with fewer than two live neighbours dies, as if caused by under-population.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overcrowding.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

int count_neighbor(int sub_board[][3]); //Count neighbors around a certain cell.

THe program iterates through each cell in the board and extracts each adjacten cell into a "sub array" and counts how many cells in the sub array
are alive (excluding itself).
Then the number of neighbors is fed into rule() which implements the game of life rules onto the cell at hand.

After all cells have been procesed into board temp, we copy board temp to the original board, overwriting the original board.

*/


