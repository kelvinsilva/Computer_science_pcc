
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

void SubStr(char source[], char destination[], int startpos, int endpos){

    int i = 0;
    for (; i <= (endpos - startpos); i++ ){
        destination[i] = source[startpos+i];
    }
    destination[i] = '\0';
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
