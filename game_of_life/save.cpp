#include "save.h"

void Open_File_Prompt(std::fstream &ofn){

     char FILE_NAME[512] = {};

     //Poll for valid filename
     do{

        std::cout << "\nEnter FileName: " << std::endl;
        std::cin >> FILE_NAME;
        ofn.open(FILE_NAME);

        if (ofn.fail()){
            std::cout << "\nError, bad file name" << std::endl;
        }
    }while(ofn.fail());
}

/*
void out_line(ofstream &fout, int line[], int size_arr){

    for (int i = 0; i < size_arr; i++){
        fout << line[i] << " ";
    }
}
*/

void out_file_board(fstream &fout, int board[][WORLDSIZE], int i, int j, int ii, int jj){

    for (int r = i; r < ii; r++){

        for(int c = j; c < jj; c++){

            fout << board[r][c];
        }
            fout << "\n";
    }
}

void out_file_board(fstream &fout, int board[][WORLDSIZE]){

    for (int r = 0; r < WORLDSIZE; r++){

        for(int c = 0; c < WORLDSIZE; c++){

            fout << board[r][c];
        }
            fout << "\n";
    }
}

void load_file(fstream  &fin, int board[][WORLDSIZE]){

    char result = 0;
    int ii = 0, jj = 0;
    for (int y = 0; y < WORLDSIZE; y++){

        result = fin.get();
        if (result == '\n'){
            ii++;
        }else if (result == '1' || result == '0'){ //2 is not implemented here because it is filled below.
            board[ii][jj] = static_cast<int>(static_cast<int>(board[ii][jj]) || (result - '0'));
        }
        jj++;
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
