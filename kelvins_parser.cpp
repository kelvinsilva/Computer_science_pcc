//Kelvin Silva
//Uses a search table to find each token.
#include <iostream>

using namespace std;
void Parse(char block[], char alpha_numeric_storage[], char punctuation_storage[],
           char whitespace_storage[], int &white_space_count, int &punctuation_count, int &alpha_numeric_count);

int Find(char key, char source[], int startpos);
void StrCat(char destination[], char source[]);
int StrLen(char A[]);

char SEARCH_TABLE[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789,<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";

int main(){


    char PUNCTUATION_TEST[] = ",<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";
    char WHITE_SPACE_TEST[] = " ";

    char alpha_numeric_storage[1024]{};
    char punctuation_storage[1024]{};
    char whitespace_storage[1024]{};

    int white_space_count = 0, punctuation_count = 0, alpha_numeric_count = 0;

    char str[] = "The Quick Brown8888 Fox Ju 'mpe,.3d over! the Lazy Dog'1";
    Parse(str, alpha_numeric_storage, punctuation_storage, whitespace_storage,
          white_space_count, punctuation_count, alpha_numeric_count);

    cout << "Original String: " << str << "\n\nAlpha Numeric Tokens: " << alpha_numeric_storage << "\nNumber of Alpha Numeric Tokens found: " << alpha_numeric_count
                                       << "\n\nWhiteSpace Tokens: ["   << whitespace_storage << "]" << "\n\nNumber of WhiteSpace Tokens Found: " << white_space_count
                                       << "\n\nPunctuation Tokens: "   << punctuation_storage << "\n\nNumber of Punctuation Tokens Found: " << punctuation_count;

   // for (int i = 0; i < StrLen(SEARCH_TABLE); i++){
       // cout << i << SEARCH_TABLE[i] << endl;
   // }

    return 0;
}


//index 0 = whitespace
//index 1 through 61 = Letters and Numbers (alphanumeric)
//index  62 through 93 = Punctuation

void Parse(char block[], char alpha_numeric_storage[], char punctuation_storage[],
           char whitespace_storage[], int &white_space_count, int &punctuation_count, int &alpha_numeric_count){

    int type = 0;
    char result_storage[2] = {0 ,'\0'};
    for (int i = 0; i < StrLen(block); i++){

        type = Find(block[i], SEARCH_TABLE, 0);

            if(type == 0){

                white_space_count++;
                result_storage[0] = block[i];
                StrCat(whitespace_storage, result_storage);

                if(   block[i+1] >= 'A' && block[i+1] <= 'Z' //if the adjacent letter is alphanumeric,
                   || block[i+1] >= 'a' && block[i+1] <= 'z'  //we must separate it into a different token
                   || block[i+1] >= '0' && block[i+1] <= '9') {  //Tokens in alpha_numeric_storage are separated by whitespaces
                         StrCat(alpha_numeric_storage, result_storage);
                }
            }else if(type >= 1 && type <= 61){

                alpha_numeric_count++;
                result_storage[0] = block[i];
                StrCat(alpha_numeric_storage, result_storage);

            }else if (type >= 61 && type <= 93){

                punctuation_count++;
                result_storage[0] = block[i];
                StrCat(punctuation_storage, result_storage);

                if(    block[i+1] >= 'A' && block[i+1] <= 'Z' //if the adjacent letter is alphanumeric,
                    || block[i+1] >= 'a' && block[i+1] <= 'z'  //we must separate it into a different token
                    || block[i+1] >= '0' && block[i+1] <= '9'){  //Tokens in alpha_numeric_storage are separated by whitespaces

                         result_storage[0] = ' ';
                         StrCat(alpha_numeric_storage, result_storage);
                }
            }
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

int StrLen(char A[]){

    int i = 0;
    while(A[i] != '\0'){
        i++;
    }
    return i;
}


void StrCat(char destination[], char source[]){

    int dest_size = StrLen(destination);
    int source_size = StrLen(source);

    for (int i = 0; i < source_size; i++){

        destination[dest_size] = source[i];
        dest_size++;
    }

}
