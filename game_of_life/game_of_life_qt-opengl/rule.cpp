#include "rule.h"
#include "array_manip.h"

void testit(){cout<<"testing...."<<endl;} //Dummy funcction

void rule(int board[][WORLDSIZE], int board_temp[][WORLDSIZE], int subboard[][3]){

    int neighbor_count = 0;
    //for every cell in the board...
    //1. Skip border
    //2. Capture subboard at i, j
    //3. count the number of neighbors --> count number of occuring integer 1 in the subboard
    //4. game of life rules to determine if i, j lives or dies
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

//In the subboard, count how many number 1's there are. return count.
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
