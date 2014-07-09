#include <iostream>


using namespace std;

void display_lab(int ** labs);
void id_enter (int **labs);
void id_search(int **labs);
int getINT(int lower, int maxx);
int getArraySize(int *labs);

int main(){


    int **labs = new int* [4];
          labs[0] = new int[6](); labs[0][5] = -1;
          labs[1] = new int[7](); labs[1][6] = -1;
          labs[2] = new int[5](); labs[2][4] = -1;
          labs[3] = new int[4](); labs[3][3] = -1;

    int input = 0;
    while (input != 3){

        display_lab(labs);
        cout << "Enter choice:\n";
        cout << "1. Log in an ID to a lab station\n";
        cout << "2. Search for ID\n";
        cout << "3. Quit\nChoice: ";
        cin >> input;

        switch(input){

            case 1: id_enter(labs);
                break;
            case 2: id_search(labs);
                break;
            case 3: break;

            default : cout << "\nNot a valid choice\n";
                break;

        }

        cout << "\n\n\n";

    }





    return 0;
}



int getArraySize(int *labs){

    for (int i = 0; 1; i++){
        if (labs[i] == -1)
            return i;
    }
}

int getINT(int lower, int maxx){

    int temp = 0;
    cin >> temp;
    while ((temp < lower || temp > maxx)){

        if (temp < lower || temp > maxx){
            cout << "\nRe enter input, not within valid bound\n";
        }
        cin >> temp;

    }

    return temp;
}

void id_search(int **labs){

    cout << "\n\nEnter ID to search: ";
    int id = 0;
    cin >> id;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < getArraySize(labs[i]); j++){

            if (labs[i][j] == id){
                cout << "\n\nFound at Lab number: " << i+1 << " at computer station: " << j+1 << "\n\n";
                return;
            }
        }
    }
    cout << "\nNone found\n";

}

void id_enter (int **labs){

    cout <<"\n\n Enter ID to enter: ";
    int id = 0;
    cin >> id;

    cout << "\n\n Enter lab number: ";
    int labn = 0;
    labn = getINT(1, 4);
    labn -= 1;


    cout << "\n\nEnter computer station: ";
    int cptn = 0;

    cptn = getINT(1, getArraySize(labs[labn]));
    cptn -= 1;


    labs[labn][cptn] = id;


}
void id_search(int **labs);

void display_lab(int ** labs){

    cout << "Lab Number Computer Stations: \n";

        for (int i = 0; i < 4; i++){

            cout << i+1<<".\t";

            for (int j = 0; j < getArraySize(labs[i]) ; j++){

                cout << j+1 << ": ";
                if (labs[i][j] == 0){
                    cout << " EMPTY ";
                }else cout << " " << labs[i][j] << " ";

            }

            cout << "\n";
        }
}
