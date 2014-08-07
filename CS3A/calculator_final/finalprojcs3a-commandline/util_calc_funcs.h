#ifndef UTIL_CALC_FUNCS_H
#define UTIL_CALC_FUNCS_H
//Kelvin Silva
#include <iostream>
#include "parser.h"

using namespace std;

mixedNumber output_queue_rpn_calculation(queue <token> out_que); //Operate on the output queue and return final answer
string clean(string str); //Take out any whitespaces other than the whitespaces between numbers.
bool look_for_error(string str); /*Look for any error patterns such as
                                   "8 (/1", "8 +)8-9(" */

#endif // UTIL_CALC_FUNCS_H
