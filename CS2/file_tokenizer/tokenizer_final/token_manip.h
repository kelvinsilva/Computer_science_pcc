#ifndef TOKEN_MANIP_H_
#define TOKEN_MANIP_H_

#include <fstream>

#define TOKEN_MAX_SIZE 64
#define TOKEN_MAX_COUNT 8192 //Make sure token max count is bigger than tokens in the text file
#define BLOCK_MAX_SIZE 512


//Contains all functions for token manipulation

//Type 1 = alpha numeric, type 2 = punctuation, type 3 white spce, type 4 newline
//Type 0 is token count

/*Global variables*/
extern char ALPHA_NUMERIC_TEST[]; //= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";
extern char PUNCTUATION_TEST[]; //= ",<.>/?;:'\"[{]}\\|_-+=~`!@#$%^&*()";
extern char WHITE_SPACE_TEST[]; //= " ";
extern char TEST_NEWLINE[]; //= "\n";

//Lower level token manipulation functions
int Find(char key, char source[], int startpos);    //Find key in source from startpos, returns index of found
int FindAny(char key[], char source[], int startpos);   //Finds any occurence of key in source from startpos, returns next position after found
int FindNotAny(char key[], char source[], int startpos);    //Finds any disoccurence of key in source from startpos, return snext position after found

//Higher level token manipulation functions

//return value is the position of the end of first occurence of char_set was found in source for baby_grep
int baby_grep /*zorg*/(char source[], char destination[], char char_set[], int start_pos);

bool GetNextToken(char block[], char token[], int &pos, int &type);     //Obtains next token from block and stores into token from pos, returning type
int TokenizeBlock(char block[], char char_table[][TOKEN_MAX_SIZE], int statistics[], int &row_ct);     //Goes through block calling GetNextToken in succession, storing results in char_table
int TokenizeFile(std::fstream &read_file, char char_table[][TOKEN_MAX_SIZE], int statistics[]);     //Calls TokenizeBlock in succession, reading data from text file

#endif // TOKEN_MANIP_H_
