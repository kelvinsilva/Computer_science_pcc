#include <iostream>
#include <windows.h>

#define WORLDSIZE  20



using namespace std;

void display_board(int board[][WORLDSIZE]);
void copy_board(int dest[][WORLDSIZE], int src[][WORLDSIZE]);

void init_board(int board[][WORLDSIZE]); //Initializes an empty board 29 by 20 with all dead cells and borders around board
//void set_value(int board[][WORLDSIZE], int i, int j, int value);  //set a value of board

void new_line(int siz){

    for (int i = 0; i < siz; i++){
        cout << "\n";
    }
}


void rule(int board[][WORLDSIZE], int board_temp[][WORLDSIZE], int subboard[][3]);
void sub_board(int board[][WORLDSIZE], int boardsub[][3], int i, int j);

int count_neighbor(int sub_board[][3]);

int main(){

    int board[WORLDSIZE][WORLDSIZE] = {};

    int board_temp[WORLDSIZE][WORLDSIZE] = {};
    int subboard[3][3] = {};


    init_board(board);
    init_board(board_temp);

    board[7][5] = 1;
    board[8][5] = 1;
    board[9][5] = 1;

    while (1){

        new_line(20);

        display_board(board);

        rule(board, board_temp, subboard);

        copy_board(board, board_temp);

        cout << "Press enter for next iteration...";


        cin.get();
        Sleep(200);
        //dostuff...
    }


    return 0;
}
void init_board(int board[][WORLDSIZE]){

    for (int y = 0; y < WORLDSIZE; y++){

        for (int z = 0; z < WORLDSIZE; z++){

            board[y][z] = 0;
        }
    }

    int j = 0;
    int i = 0;

    for (; j < WORLDSIZE; j++){
        //top edge
        board[i][j] = 2;
    }
    for (; i < WORLDSIZE; i++){
        //left edge
        board[i][j] = 2;
    }
    for (i = WORLDSIZE-1, j = 0; j < WORLDSIZE; j++){
        //bottom edge
        board[i][j] = 2;
    }
    for (i = 0; i < WORLDSIZE; i++){
        //right edge
        board[i][WORLDSIZE-1] = 2;
    }
}

void copy_board(int dest[][WORLDSIZE], int src[][WORLDSIZE]){

    for (int i = 0; i < WORLDSIZE; i++){

        for (int j = 0; j < WORLDSIZE; j++){

            dest[i][j] = src[i][j];
        }
    }
}

void sub_board(int board[][WORLDSIZE], int subboard[][3], int i, int j){

    int is = i - 1;
    int js = j - 1;

    for (int iz = 0; iz < 3; iz++){

        for (int jz = 0; jz < 3; jz++){
            subboard[iz][jz] = board[is+iz][js+jz];
        }
    }


}

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
                if (neighbor_count < 2)
                    board_temp[i][j] = 0;
                else if ( neighbor_count > 3){
                    board_temp[i][j] = 0;
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

void display_board(int board[][WORLDSIZE]){

    for (int i = 0; i < WORLDSIZE; i++){

        for (int x = 0; x < WORLDSIZE; x++){

            if (board[i][x] == 2){
                cout << "* ";
            }else if (board[i][x] == 1){
                cout << 'O' << " ";
            }else if (board[i][x] == 0){
                cout << 'X' << " ";
            }
        }
        cout << "\n";
    }
}
