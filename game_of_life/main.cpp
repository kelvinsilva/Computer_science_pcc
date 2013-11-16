#include <iostream>
#include <windows.h>
#include "rule.h"
#include "array_manip.h"

using namespace std;

void new_line(int siz){

    for (int i = 0; i < siz; i++){

        cout << "\n";
    }
}

int main(){

    int board[WORLDSIZE][WORLDSIZE] = {};

    int board_temp[WORLDSIZE][WORLDSIZE] = {};
    int subboard[3][3] = {};

    init_board(board);
    init_board(board_temp);

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
