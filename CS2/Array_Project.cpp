//Array project
//Kelvin Silva
/*
Operator, Operand syntax format.
Ex.
Array> a9 //adds 9 to array

Ex.
Array> A 9 // adds 9 to array

///////////////////////////
Operations are as follows:
a <operand> to add to array

i <operand> to search for value and return index
d <no operand> delete value at selected index
4 <no operand> to shift selection left
6 <no operand> to shift selection right
q <no operand> to quit
////////////////////////////
*/


#include <iostream>

using namespace std;

int add(int A[], int &numused, int value);
void show(int A[], int numused, int cursor);
int search(int A[], int numused, int value);
int Delete(int A[], int &numused, int index);

const int MAX_SIZE = 200;

int main(){

    int space[MAX_SIZE], numused = 0, cursor = 0, operand = 0;
    char operation = 0;

    show(space, numused, cursor); cout << "\n\nArray> ";
    cin >> operation;
    while(operation != 'q'){

        switch (operation){

            case '4':{
                    cursor--;
                  break;
            }
            case '6':{
                    cursor++;
                    break;
            }

            case 'a':
            case 'A':{
                    cin >> operand;
                    if(add(space, numused, operand) == -1){
                        cout << "\nAdd failed\n";
                    }
                    break;
            }
            case 'd':
            case 'D':{
                    //cin >> operand;
                    if(Delete(space, numused, cursor) == -1){
                        cout << "\nDelete Failed\n";
                    }
                    break;
            }

            case 's':
            case 'S':{
                    cin >> operand;
                    int value = search(space, numused, operand);
                    if (value == -1){

                        cout << "\nSearch Failed\n";
                    }else {

                        cout << "\nFirst occurrence of " << operand << " found at index: " << value << "\n";
                    }
                    break;
            }
            case 'h':
            case 'H':{

                cout << "\nOperator, Operand syntax format.\n";
                cout << "\nOperations:\na <operand> append to array\ni <operand> search value and return index\nd <no operand> delete value at selected index\n";
                cout << "4 <no operand> select left\n6 <no operand> select right\nq <no operand> quit\nAll commands have uppercase equivalents\n";
                break;
            }
            default : cout << "\nSyntax Error";
        }
        if (cursor >= numused)
            cursor = numused-1;
        else if (cursor < 0)
            cursor = 0;

        cout << "\n"; show(space, numused, cursor); cout << "\n\nArray> ";
        cin >> operation;
    }

}

int add(int A[], int &numused, int value){

    if (numused > MAX_SIZE){
        return -1;
    }

    A[numused] = value;
    numused++;
}

int Delete(int A[], int &numused, int index){

    if (index >= numused || index < 0){
        return -1;
    }


    for (int i = index; index < numused; index++){
        A[index] = A[index+1];
    }
    numused--;
}

void show(int A[], int numused, int cursor){

    if (numused == 0)
            cout << "\n[]\n";
    else{

        for (int i = 0; i < numused; i++){
            if (i == cursor){
                cout << "[" << A[i] << "] ";
            }else
                cout << A[i] << " ";
        }
    }

}
int search(int A[], int numused, int value){

    for (int i = 0; i < numused; i++){
        if (A[i] == value){
            return i;
        }
    }
    return -1;
}


