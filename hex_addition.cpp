#include <iostream>
#include <cstdlib>
#include <string.h>

const char MAX_SIZE = 10;

int ascii_to_integer(char arr[], int destination[]);
void integer_to_ascii(int arr[], char destination[]);
void add_array(int arr1[], int arr2[], int destination[]);
void reverse_array(char arr[]);

using std::cout;
using std::cin;

int main(){

    char input1[MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char input2[MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char answer[MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int dest1[MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
       ,dest2[MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
       ,dest3[MAX_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cin >> input1;
    reverse_array(input1);
    ascii_to_integer(input1, dest1);

    cin >> input2;
    reverse_array(input2);
    ascii_to_integer(input2, dest2);

    add_array(dest1, dest2, dest3);

    integer_to_ascii(dest3, answer);
    reverse_array(answer);
    cout << "\nAnswer of addition: "<< answer;

    return 0;
}

int ascii_to_integer(char arr[], int destination[]){

    for (int i = 0; i < MAX_SIZE; i++){
        if (arr[i] >= '0' && arr[i] <= '9'){
            destination[i] = arr[i] - '0';
        }else if (arr[i] >= 'A' && arr[i] <= 'F'){
            destination[i] = arr[i] - 55;
        }else return -1;
    }
}

void integer_to_ascii(int arr[], char destination[]){

    const char lookup_int_to_char[] = "0123456789ABCDEF";

    for (int i = 0; i < MAX_SIZE-1; i++){
        destination[i] = lookup_int_to_char[arr[i]];
    }

}

void reverse_array(char arr[]){

    int current_size = strlen(arr);
    int end_arr = current_size-1;
    char temp = 0;

    for (int i = 0; i < current_size/2; i++){

        temp = arr[i];
        arr[i] = arr[end_arr];
        arr[end_arr] = temp;
        end_arr--;
    }
}

void add_array(int arr1[], int arr2[], int destination[]){

    int stay = 0, carry = 0;
    for (int i = 0; i < MAX_SIZE; i++){

        stay =  (arr1[i] + arr2[i]) % 16;
        destination[i] = stay+carry;
        carry = (arr1[i] + arr2[i]) / 16;
        //answer += carry;
    }
}

