#ifndef PARSER_CLASS_H_
#define PARSER_CLASS_H_
//Kelvin Silva
#include "mixedNumber.h"
#include "token_definition.h"
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

enum ERROR{MISMATCH_PARENTH, SYNTAX_ERROR}; //Old

class Parser{


    private:

        queue <token> output_queue; //Output queue that contains the reversed polish notation expression
        stack <char> operator_stack; //Stack used to manipulate operators. Do not access outside class
        string algebraic, rpn;
        static map <char, int> precedence_operator; //Stores the precedence map for each operator

        static map<char, int> init_map() { //Prepare precedence map for parsing
            map <char,int> some_map;
            some_map['+'] = 2;
            some_map['-'] = 2;
            some_map['*'] = 3;
            some_map['/'] = 3;

            return some_map;
        }


        void output_queue_assign_to_rpn_str(queue<token>& output_queue);

    public:



        void parse_algebraic();
        queue <token> get_output_queue();
        string get_rpn_str();
        void set_string(string st); //Set the string to parse into rpn
        void clear_parser();


};



#endif // PARSER_CLASS_H_
