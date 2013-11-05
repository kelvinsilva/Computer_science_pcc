//Kelvin Silvaxx
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

void SubStr(char source[], char destination[], int startpos, int endpos);
int StrLen(char A[]);

int Find(char key, char source[], int startpos){

    int i = startpos;
    while (source[i] != '\0'){

        if (source[i] == key){
            return i;
        }
        i++;
    }
    return -1;
}

int FindAny(char key[], char source[], int startpos){

    int i = startpos;
    while(source[i] != '\0'){

        if (Find(source[i], key, 0) != -1){
            return i;   //Return index of found character
        }
        i++;
    }
    return -1; //Return not found error
}

int FindNotAny(char key[], char source[], int startpos){ //Returns index of first dis-occurence of key in source, if find not any fails, then
                                                         //If find not any fails, then return strlen of source
    int i = startpos;
    while(source[i] != '\0'){

        if (Find(source[i], key, 0) == -1){
            return i;   //Return index of character not in key
        }
        i++;
    }
    return -1; //Return not found error
}

int baby_grep /*zorg*/(char source[], char destination[], char char_set[], int start_pos){ //return value is the position of the end of first occurence of char_set was found in source

    int startpos = FindAny(char_set, source, start_pos);
    int end_pos = FindNotAny(char_set, source, startpos)-1;

    if (end_pos < 0){

        end_pos = StrLen(source);
        SubStr(source, destination, startpos, end_pos);
        return end_pos;
    }
    if (startpos != -1 && end_pos != -1){ //If a position was found

        SubStr(source, destination, startpos, end_pos);
        return ++end_pos;
    }else{

        return 0;
    }
}

char ALPHA_NUMERIC_TEST[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";
char PUNCTUATION_TEST[] = ",<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";
char WHITE_SPACE_TEST[] = " ";
char TEST_NEWLINE[] = "\n";

//Type 1 = alpha numeric, type 2 = punctuation, type 3 white spce, type 4 newline
//Type 0 is token count
bool GetNextToken(char block[], char token[], int &pos, int &type){

    bool token_notify = true;
    if (pos == StrLen(block)){
            token_notify = false;
    }
    if (Find(block[pos], ALPHA_NUMERIC_TEST, 0) != -1){

        pos = baby_grep(block, token, ALPHA_NUMERIC_TEST, pos);
        type = 1;
    }else if(Find(block[pos], PUNCTUATION_TEST, 0) != -1){

        pos = baby_grep(block, token, PUNCTUATION_TEST, pos);
        type = 2;
    }else if(Find(block[pos], WHITE_SPACE_TEST, 0) != -1){

        pos = baby_grep(block, token, WHITE_SPACE_TEST, pos);
        type = 3;
    }else if(Find(block[pos], TEST_NEWLINE, 0) != -1){

        pos = baby_grep(block, token, TEST_NEWLINE, pos);
        type = 4;
    }
    return token_notify;
} //return true if token does not exist

//Type 1 = alpha numeric, type 2 = punctuation, type 3 white spce, type 4 newline
void TokenizeBlock(char block[], char char_table[][64], int statistics[]){

    int pos = 0, type = 0, row = 0;
    while(GetNextToken(block, char_table[row], pos, type)){
       // if (type != 1){
        //    --row;
        //}
        statistics[type]++;
        statistics[0]++;
        row++;
    }
}

void TokenizeFile(&)

int main(){

    char file_Name[513]{};
    char char_table[10][64]{};

    int statistics[5]{};
    cout << "Original Block: " << source << endl;

    TokenizeBlock(source, char_table, statistics);

    cout << "Enter File Name: ";
    cin.getline(file_Name, 512, '\n');
    cin.ignore();

    TokenizeFile()

}