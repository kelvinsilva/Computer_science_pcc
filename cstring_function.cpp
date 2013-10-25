//Kelvin Silva
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

int StrCmp(char first[], char second[]){ //ret 1 if first > second, ret -1 if first < second, ret 0 if first == second

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
    return -1; //Return Error
}

int FindNotAny(char key[], char source[], int startpos){ //Returns index of first dis-occurence of key in source

    int i = startpos;
    while(source[i] != '\0'){

        if (Find(source[i], key, 0) == -1){
            return i;   //Return index of found character
        }

        i++;
    }
    return -1; //Return Error
}

char ToLower(char key){

    if (key >= 'A' && key <= 'Z'){
        return static_cast<char>(key + 32); // ' ' == 32
    }
    return key;
}

char ToUpper(char key){

    if (key >= 'a' && key <= 'z'){
        return static_cast<char>(key - 32); // ' ' == 32
    }
    return key;
}

bool GT(char str1[], char str2[]){ //Checks if str1 is greater than str2

    if (StrCmp(str1, str2) == 1){ //Str1 > str2
        return true;
    }
    return false;
}

bool LT(char str1[], char str2[]){ //Checks if str1 is less than str2

    if(StrCmp(str1, str2) == -1){ //StrCmp returns -1 if str1 < str2
        return true;
    }
    return false;

}

bool EQ(char str1[], char str2[]){ // returns true if str1 == str2

    if(StrCmp(str1, str2) == 0){ //StrCmp evaluates to zero if str1 == str2
        return true;
    }
    return false;
}




//Kelvin Silva


#include <iostream>
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
    cout << "here";
    return -1; //Return not found
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
    return StrLen(source); //Return not found
}


/*

alphanumeric
punctuation
numbers
whitespace newlines and carriage return

*/

int baby_grep /*zorg*/(char source[], char destination[], char char_set[], int startpos){ //return value is the position of the end of first occurence of char_set was found in source

    startpos = FindAny(char_set, source, startpos);
    int end_pos = FindNotAny(char_set, source, startpos);
    cout << "startpos: " << startpos << " end_pos: " << end_pos;

    if (startpos != -1){ //If a position was found

        SubStr(source, destination, startpos, end_pos);
        return end_pos;
    }else{

        return 0;
    }
}

char ALPHA_NUMERIC_TEST[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char PUNCTUATION_TEST[] = ",<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";
char WHITE_SPACE_TEST[] = " ";

bool GetNextToken(char block[], char token[], int &pos, int &type){

        //std::cout<<std::endl<<pos << " " << end_condition;
        pos = baby_grep(block, token, ALPHA_NUMERIC_TEST, pos); //if return 0, then token was not found
        type = 0;
        if (pos == 0){
            cout << "Found non alphanumeric";
            pos = baby_grep(block, token, PUNCTUATION_TEST, pos);
            type = 1;
        }else if (pos == 0){

            pos = baby_grep(block, token, WHITE_SPACE_TEST, pos);
            type = 2;
        }

} //return true if token does not exist

int main(){

    char str[] = "'The quick, brown, fo'x, jumped over the lazy DOG!. ";
    char str_dest[90] = {};
    //char strsrch[] = ";'.,ABC";

    int startpos = 0;
    int type = 0;

    //baby_grep(str, str_dest, strsrch, startpos);
    GetNextToken(str, str_dest, startpos, type);

    cout << std::endl << startpos;
    std::cout << std::endl << str_dest;



}






/*

Lower-Level Cstring Functions:
void StrCpy(char MyString[], char CopyThis[]); //CopyThis into MyString
void StrCat(char MyString[], char CatThis[]); // CatThis to the end of MyString
int StrLen(char MyString[]); //return length of MyString
int StrCmp(char MyString[], char Compare[]); //compare two strings
void SubStr(char MyString[], char Sub[], int start, int length);
//create substring of MyString with a certain length and starting position
int Find(char MyString[], char FindThis[], int pos);
//return location of FindThis in MyString
int Find(char FindHere[], char target, int pos);
//find a target character starting at a particular position
int FindAny(char MyString[], char FindThese[], int pos);
//return position of first occurence of anything in MyString, in FindThese
int FindNotAny(char MyString[], char FindThese[], int pos);
//position of first occurence of anything in MyString, not in FindThese

Additional functions to include:

int ToInt(char MyString[], int pos);
//return first int in MyString starting from a particular position
int AtoI(char ConvertThis[]); //convert array of characters to an integer
int CharToInt(char ch); //convert a single character to an integer
void ToLower(char MyString[]); //makes every character in an array lowercase
bool Eq(char MyString[], char Compare[]); //true if MyString=Compare
bool GT(char MyString[], char Compare[]); //true if MyString>Compare
bool LT(char MyString[], char Compare[]); //true if MyString<Compare


int baby_grep(char MyString[], char CharSet[], char Substring[], int pos);
//Creates a substring of characters from MyString that can be found inside a character set, starting from a particular position.

bool GetToken(char Block[], char Token[], char &tokenType, int &pos);
//Determines what type of token a character represents, and creates an array containing the token.

*/






