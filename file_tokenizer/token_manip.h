#ifndef TOKEN_MANIP_H_
#define TOKEN_MANIP_H_

#define TOKEN_MAX_SIZE 64
#define TOKEN_MAX_COUNT 8192 //Make sure token max count is bigger than tokens in the text file
#define BLOCK_MAX_SIZE 512

//Type 1 = alpha numeric, type 2 = punctuation, type 3 white spce, type 4 newline
//Type 0 is token count

extern char ALPHA_NUMERIC_TEST[]; //= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";
extern char PUNCTUATION_TEST[]; //= ",<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";
extern char WHITE_SPACE_TEST[]; //= " ";
extern char TEST_NEWLINE[]; //= "\n";


int Find(char key, char source[], int startpos);
int FindAny(char key[], char source[], int startpos);
int FindNotAny(char key[], char source[], int startpos);

//return value is the position of the end of first occurence of char_set was found in source
int baby_grep /*zorg*/(char source[], char destination[], char char_set[], int start_pos);
bool GetNextToken(char block[], char token[], int &pos, int &type);
int TokenizeBlock(char block[], char char_table[][TOKEN_MAX_SIZE], int statistics[], int &row_ct);

#endif // TOKEN_MANIP_H_
