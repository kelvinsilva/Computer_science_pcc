#include "array_manip.h"

void display_board(std::ostream &ost, int board[][WORLDSIZE]){ //convert integer values to graphical characters

    for (int i = 0; i < WORLDSIZE; i++){

        for (int x = 0; x < WORLDSIZE; x++){

            if ( i == 1 || i == WORLDSIZE-2 || x == 1 || x == WORLDSIZE-2){
                ost << " ";
                continue;
            }

            if (board[i][x] == 2){
                ost << "* ";
            }else if (board[i][x] == 1){
                ost << 'O' << " ";
            }else if (board[i][x] == 0){
                ost << 'X' << " ";
            }
        }
        ost << "\n";
    }
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

void display_board(int board[][WORLDSIZE]){

    for (int i = 0; i < WORLDSIZE; i++){

        for (int x = 0; x < WORLDSIZE; x++){

            if ( i == 1 || i == WORLDSIZE-2 || x == 1 || x == WORLDSIZE-2){
                cout << " ";
                continue;
            }

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
