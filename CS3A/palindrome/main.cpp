//Kelvin Silva
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void getInput(char word[]);
bool again(string title);
void makeUpper(char word[]);
void getReverse(char word[], char reverse[]);
char* find(char *str, char  what);
bool equal(char word[], char reverse[]);
int size(char word[]);

char* clean_str(char word[]);

int main()
{
    char word[256] = {}, reversedWord[256] = {};
    do
    {
        getInput(word);
        cout << "Original word: " << word << "\n";

        makeUpper(word);
        cout << "Upper word: " << word << "\n";

        char *clean_word = clean_str(word);

        getReverse(clean_word,reversedWord);


        cout << "\n\nclean word : " << clean_word << "\n";
        cout << "\n\nReversed word: " << reversedWord << "\n";

        if(equal(clean_word, reversedWord))
            cout<<"You have a palindrome!"<<endl;
        else
            cout<<"You do not have a palindrome!"<<endl;

        delete[] clean_word;
    }while(again("Do you want to do this again? "));



    return 0;
}

char* clean_str(char word[]){

    char *ptr = word;
    char *newstr = new char[256];
    char *temp = newstr;

    for (int i = 0; i < 256; i++){
        *(newstr + i) = 0;
    }

    while (*ptr != '\0'){

        if (*ptr != ' ' && (*ptr >= 'A' && *ptr <= 'Z')){
            *newstr = *ptr;
            newstr++;
        }
        ptr++;

    }

    return temp;

}


void getInput(char word[])
{
    cout<<"Please enter the string to check: ";
    cin.getline(word, 256);

}

bool again(string title)
{
    string answer;
    cout<<endl<<title;
    cin>>answer;
    cin.ignore();
    return toupper(answer[0]) == 'Y';
}


void makeUpper(char word[])
{
    char *ptr = word;
    while(*ptr != '\0'){ //while(*ptr != '\0')
        if(*ptr>='a' && *ptr<='z')
            *ptr -= 32;
        ptr++;
    }
}


void getReverse(char word[], char reversed[])
{
    char *ptr = find(word, '\0')-1, *ptr2 = reversed;
    while(ptr != word-1)
    {
        *ptr2 = *ptr;
        ptr--;
        ptr2++;
    }
    *ptr2 = '\0';
}

char* find(char *str, char  what)
{
    char *ptr = str;
    while(*ptr != what && *ptr != '\0')
        ptr++;

    return *ptr == what ? ptr : NULL;
}

bool equal(char word[], char reverse[])
{
    int total;
    char *ptr = word;
    if((total = size(word)) != size(reverse))
        return false;
    for(char *ptr2 = reverse;  *ptr != '\0' && *ptr == *ptr2; ptr++, ptr2++);
    return *ptr == '\0';
}

int size(char word[])
{
    int total = 0;
    char* ptr = word;
    while(*ptr != '\0')//while(!ptr)
    {
        ptr++;
        total++;
    }
    return total;
}
