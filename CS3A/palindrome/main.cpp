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

int main()
{
    char word[256] = {}, reversedWord[256] = {};
    do
    {
        getInput(word);
        makeUpper(word);
        getReverse(word,reversedWord);
        if(equal(word, reversedWord))
            cout<<"You have a palindrome!"<<endl;
        else
            cout<<"You do not have a palindrome!"<<endl;
    }while(again("Do you want to do this again? "));
    return 0;
}


void getInput(char word[])
{
    cout<<"Please enter the string to check: ";
    cin>>word;
}

bool again(string title)
{
    string answer;
    cout<<endl<<title;
    getline(cin,answer);
    return toupper(answer[0]) == 'Y';
}


void makeUpper(char word[])
{
    char *ptr = word;
    while(*ptr) //while(*ptr != '\0')
        if(*ptr>='a' && *ptr<='z')
            *ptr -= 32;
}


void getReverse(char word[], char reversed[])
{
    char *ptr = find(word, '\0'), *ptr2 = reversed;
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
    if((total == size(word)) != size(reverse))
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
