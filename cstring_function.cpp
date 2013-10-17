#include <iostream>

using namespace std;



int StrLen(char A[]){

    int i = 0;
    while(A[i] != '\0'){
        i++;
    }
    return i;
}

void StrCpy(char dest[], char source[]){

    int i = 0;
    for (; source[i] != '\0'; i++){
        dest[i] = source[i];
    }
    dest[++i] = '\0';
}

int StrCmp(char first[], char second[]){

    int i = 0;
    while(first[i] != '\0' && second[i] != '\0'){

        if (first[i] != second[i]){

            if (first[i] > second[i]){
                return 1;
            }else if (first[i] < second[i]){
                return -1;
            }
        }
        i++;
    }
    return 0;
}


void StrCat(char destination[], char source[]){

    int dest_size = StrLen(destination);
    int source_size = StrLen(source);

    for (int i = 0; i < source_size; i++){

        destination[dest_size] = source[i];
        dest_size++;
    }

}

int Find(char key, char source[]){

    int i = 0;
    while (source[i] != '\0'){

        if (source[i] == key){
            return i;
        }
        i++;
    }
    return -1;
}

int FindAny(char key[], char source[]){

    int i = 0;
    while(source[i] != '\0'){

        if (Find(source[i], key) != -1){
            return i;
        }

        i++;
    }
    return -1;
}
