#ifndef PARSE_FRAC_H_
#define PARSE_FRAC_H_

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include "mixednumber.h"


using namespace std;

int * tokenize_str(string str); //Convert string into integral tokens for operation
string clean(string str);   //Clean string of any whitespaces NOT between two numbers
int find_size_array(int tokens[]);  //Finds the size of the array of integral tokens
//binary slot temp functions
void seedfeed(int tokens[], int &ct, int temp[]); //Seed the temp
void feed (int tokens[], int &ct, int temp[]); //Feed from token into temp.
//

int count_operators (int * my_toks);
void interpret_tokens(mixedNumber &num_one, mixedNumber &num_two, char &op, int tokens[], int num_operators); //Convert integral token values into mixed number and operation

//Master function below:
int parse_line(string line, mixedNumber &num_one, mixedNumber &num_two, char &op); //Combine all above functions to give back mixed number, and operation.



#endif // PARSE_FRAC_H_
