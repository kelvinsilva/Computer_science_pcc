#ifndef PARSE_FUNCS_H_
#define PARSE_FUNCS_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>

#include "mixedNumbers.h"

using namespace std;

bool fileExists(const char *filename);
string clean_name(string filename);
bool parse_mixedInput(const char *input, mixedNumber* &soln_array);
void parseCommandLine(int argc,char *argv[], ifstream *in, ofstream &out, char &operation, mixedNumber* &soln_matrix);
void promptOpen(ofstream &fo, string filename);

#endif // PARSE_FUNCS_H_
