#include "array_manip.h"

void display_board(std::ostream &ost, int board[][WORLDSIZE]){ //convert integer values to graphical characters
//this function used only for terminal. deprecated in qt opengl
//to display in cout or fstream usage

    for (int i = 0; i < WORLDSIZE; i++){

        for (int x = 0; x < WORLDSIZE; x++){

            if ( i == 1 || i == WORLDSIZE-2 || x == 1 || x == WORLDSIZE-2){
                ost << " ";    //ost outstream 
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
void init_board(int board[][WORLDSIZE]){    //initiate all array of board with dead cells and a border

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

void sub_board(int board[][WORLDSIZE], int subboard[][3], int i, int j){    //takes a sub_board (like a substring)

    int is = i - 1;
    int js = j - 1;

    for (int iz = 0; iz < 3; iz++){

        for (int jz = 0; jz < 3; jz++){
            subboard[iz][jz] = board[is+iz][js+jz];
        }
    }


}

void display_board(int board[][WORLDSIZE]){
//used for cout only!
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

void border_reflection(int board[][WORLDSIZE]){


    //top edge reflection coordinates: board[1][1] <= board[1][i] <=  board[1][WORLDSIZE-2]
    //bottom edge reflection: board[WORLDSIZE-2][1] <= board[WORLDSIZE-2][i] <= board[WORLDSIZE-2][WORLDSIZE-2]

    for (int i = 1; i <= WORLDSIZE-2; i++){

        board[1][i] = board[WORLDSIZE-3][i];
        board[WORLDSIZE-2][i] = board[2][i];
    }
    //left edge reflection: board[1][1] <= board[i][1] <= board[WORLDSIZE-2][1]
    //right edge reflection: board[1][WORLDSIZE-2] <= board[i][WORLDSIZE-2] <= board[WORLDSIZE-2][WORLDSIZE-2]

    for (int i = 1; i <= WORLDSIZE-2; i++){
        board[i][1] = board[i][WORLDSIZE-3];
        board[i][WORLDSIZE-2] = board[i][2];
    }

    //corners
    board[1][1] = board[WORLDSIZE-3][WORLDSIZE-3]; //top left = bottom right
    board[WORLDSIZE-2][WORLDSIZE-2] = board[2][2]; //bottom right = top left

    board[1][WORLDSIZE-2] = board[WORLDSIZE-3][2]; //top right = bottom left
    board[WORLDSIZE-2][1] = board[2][WORLDSIZE-3]; //bottom left = top right


}
