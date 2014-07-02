//Kelvin Silva cs002
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Value of each card
char board[4][4] = {{'A', 'A','B','B'},
                    {'C', 'C','D','D'},
                    {'E', 'E','F','F'},
                    {'H', 'H','G','G'}};
//To see which cards must be shown
int board_mask[4][4] = {{0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};

void display_board(char board[][4], int mask[][4]);
void initialize_board(char board[][4]);
void set_mask(int mask[][4], int row, int col, int value);
bool check_win(int mask[][4]);

int main(){

    for (int i = 0; i < 4; i++){
        for (int x = 0; x < 4; x++){
            set_mask(board_mask, i, x, 0);
        }
    }

    initialize_board(board);

    while(!check_win(board_mask)){


        display_board(board, board_mask);

        int coord1, coord2, coord11, coord22;
        cout << "\nEnter (row col) for first card, type -1 to quit: ";
        cin >> coord1;
        if (coord1 == -1 || coord2 == -1) return 0;
        cin >> coord2;

        cout << "\nEnter (row col) for second card, type -1 to quit: ";
        cin >> coord11;
        if (coord11 == -1 || coord22 == -1) return 0;
        cin >> coord22;

        //Emulate clearing of buffer
        for (int i = 0; i < 15; i++)
            cout << endl;

        //Make sure that coordinates are in range and that they do not equal to each other
        if ((coord1 >= 0 && coord1 < 5) || (coord11 >= 0 && coord11 < 5) || (coord2 >= 0 && coord2 < 5)|| (coord22 >= 0 && coord22 < 5)){

            if ((board[coord1][coord2] == board[coord11][coord22]) && (coord1 != coord11 || coord2 != coord22)){

                //Set the mask to enable the showing of card or not showing of card
                set_mask(board_mask, coord1, coord2, 1);
                set_mask(board_mask, coord11, coord22, 1);
                cout << "\n\nCards are Matching!\n";

            }else {

                //Set the mask to enable the showing of card or not showing of card
                set_mask(board_mask, coord1, coord2, 0);
                set_mask(board_mask, coord11, coord22, 0);

                if ((coord1 == coord11 && coord2 == coord22)){
                        cout << "Coordinate input invalid!\nDo not enter same coordinates\n";
                }else cout << "\n\nCards are not Matching!\n";
            }

        }else {
            // if bad letter input then press enter to continue playing
            cout << "\n\nCoordinate input invalid. Press enter to continue game..\n\n";
            cin.get();
        }
    }

}

//Check if the mask is all 0's or 1's if mask contains one or more 0's then it is lose
//If mask has all 1 values then it is winnings
bool check_win(int mask[][4]){

    for (int i = 0; i < 4; i++){
        for (int x = 0; x < 4; x++){
            if (mask[i][x] == 0){
                return false;
            }
        }
    }

    return true;
}

void set_mask(int mask[][4], int row, int col, int value){

    mask[row][col] = value;
}

void display_board(char board[][4], int mask[][4]){

    cout << "    0 1 2 3  ";
    cout << "\n  * * * * *";

    for (int i = 0; i < 4; i++){

        cout << "\n"<<i << " " << "* ";
        for (int x = 0; x < 4; x++){
            //If mask bit is set, then display the card, if it is not, the display X for null card
            if (mask[i][x] == 1){
                cout << board[i][x] << " ";

            }else cout << 'X' << " ";
        }
    }
}

//Randomly swap each card at each random coordinate. Note that the only cards available are values A-H but each is swapped at random locations
void initialize_board(char board[][4]){

    srand(time(NULL));
    for (int i = 0; i < 15; i++){

            char temp = 0;
            int rand_row = ((rand() % 4)) , rand_col = ((rand() % 4)), rrand_row = ((rand() % 4)), rrand_col = ((rand() % 4));
            temp = board[rand_row][rand_col];
            board[rand_row][rand_col] = board[rrand_row][rrand_col];
            board[rrand_row][rrand_col] = temp;
    }
}
