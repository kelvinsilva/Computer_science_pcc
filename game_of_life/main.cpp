#include <iostream>
#include <windows.h>
#include "rule.h"
#include "array_manip.h"
#include "save.h"

using namespace std;

void new_line(int siz){

    for (int i = 0; i < siz; i++){

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

int main(){

    int board[WORLDSIZE][WORLDSIZE] = {};

    int board_temp[WORLDSIZE][WORLDSIZE] = {};
    int subboard[3][3] = {};

    init_board(board);
    init_board(board_temp);

   /* board[WORLDSIZE-3][5] = 1;
    board[2][5] = 1;
    board[3][5] = 1;

    board[WORLDSIZE-3][9] = 1;
    board[WORLDSIZE-4][9] = 1;
    board[WORLDSIZE-5][9] = 1;

    board[10][2] = 1;
    board[10][3] = 1;
    board[10][WORLDSIZE-3] = 1;

    board[15][2] = 1;
    board[15][WORLDSIZE-3] = 1;
    board[15][WORLDSIZE-4] = 1;*/

    //glider test
    board[8][6] = 1;
    board[8][7] = 1;
    board[8][8] = 1;
    board[7][8] = 1;
    board[6][7] = 1;


 /*   new_line(20);
    display_board(board);

        //border_reflection(board);
        //rule(board, board_temp, subboard);
        //border_reflection(board_temp);

        //copy_board(board, board_temp);

    cout << "Press enter for next iteration...";

    cin.get();*/

    bool exit = false;
    int iterate = 1;
    char operation = 0;
    int delay = 200;

    while (!exit){

        for (int i = 0; i < iterate; i++){
            new_line(20);

            border_reflection(board);
            rule(board, board_temp, subboard);
            border_reflection(board_temp);

            copy_board(board, board_temp);
            display_board(board);

            Sleep(delay);
        }

        cout << "Enter choice: "
             << "\nPress Enter to iterate once "
             << "\nType 'i' and a number and enter to iterate number times"
             << "\nType 'p' to save screen to text file"
             << "\nType 's' and four numbers to save a portion of screen to text file"
             << "\nType 'l' to load a file onto screen";


        iterate = 1;
        switch(cin.get()){

            case 'n':{
                continue;
            }
            break;
            case 'i':{

                cin >> iterate;
                cin.ignore();
                break;
            }
            case 's':{
                int i = 0, ii = 0, j = 0, jj = 0;
                //i = cin.get()
                //cin.ignore(999);
                //cin.ignore();

                    cin >> i >> j >> ii >> jj;


                    cout << "\nFile Saved to program directory. Press Enter for next iteration";
                    cin.ignore();
                    cin.get();
            }
            break;
            case 'p':{

                fstream fout;
                Open_File_Prompt(fout);
                cout << "Do you want a graphical printout, or a logical printout? (G/L)?";

                cin.ignore();
                char choice = cin.get();
                if (choice == 'G' || choice == 'g'){
                    display_board(fout, board);
                }else out_file_board(fout, board_temp);

                cout << "\nScreen saved to text file. Press Enter for next generation";
                fout.close();
                cin.ignore();
                cin.get();
            }
            break;
            case 'l':{

                fstream fin;
                cin.ignore();
                Open_File_Prompt(fin);
                load_file(fin, board);
                cin.ignore();
                cout << "Loaded.... Press enter for next generation";
                fin.close();
                cin.ignore();
                cin.get();
            }
            break;
            case 'd':{
                cin >> delay;
                cin.ignore();
            }
            break;
        }

            //dostuff...
    }

    return 0;
}
