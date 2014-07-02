#ifndef STRING_MANIP_H_
#define STRING_MANIP_H_

//Contains all functions for string manipulation

int StrLen(char A[]);
void StrCpy(char dest[], char source[]);
int StrCmp(char firstp[], char secondp[]);
void StrCat(char destination[], char source[]);
void SubStr(char source[], char destination[], int startpos, int endpos);
char ToLower(char key);
char ToUpper(char key);
bool GT(char str1[], char str2[]);
bool LT(char str1[], char str2[]);
bool EQ(char str1[], char str2);

#endif // STRING_MANIP_H_
