#include "rule.h"
#include "array_manip.h"

void testit(){cout<<"testing...."<<endl;}
void rule(int board[][WORLDSIZE], int board_temp[][WORLDSIZE], int subboard[][3]){

    int neighbor_count = 0;
    for (int i = 0; i < WORLDSIZE; i++){

        for (int j = 0; j < WORLDSIZE; j++){

            if (board[i][j] == 2){ //skip if border
                continue;
            }else {

                sub_board(board, subboard, i , j);
                neighbor_count = count_neighbor(subboard);
            }

            if (board[i][j] == 1){
                if (neighbor_count < 2){
                    board_temp[i][j] = 0;
                }
                else if ( neighbor_count > 3){
                    board_temp[i][j] = 0;
                }
                else{
                    board_temp[i][j] = 1;
                }

            }else if ( board[i][j] == 0 && neighbor_count == 3){
                board_temp[i][j] = 1;
            }
        }
    }

}

int count_neighbor(int board[][3]){

    int neighbor_count = 0;
    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){
            if ( i == 1 && j == 1){ //Skip self...
                continue;
            }else {
                if (board[i][j] == 1){
                    neighbor_count++;
                }
            }
        }
    }

    return neighbor_count;
}
