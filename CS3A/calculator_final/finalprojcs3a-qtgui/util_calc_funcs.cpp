#include "util_calc_funcs.h";


mixedNumber output_queue_rpn_calculation(queue <token> out_que){

    stack <mixedNumber> calc_stk; //prepare a temporary stack

    while(out_que.size() > 0){ //for every element in output queue

        if (out_que.front().IS_NUMBER == true){ //If you token is a mixednumber and Not an operator, then we push to the stack

            calc_stk.push( out_que.front().mix );
            out_que.pop();
        }else {         //If we reach an operator, push 2 elements off the stack, perform operation and put the result back on stack

            switch( (char)out_que.front().value ){

                case '+' :{

                    mixedNumber left;   //Example here:
                    left = calc_stk.top();  //obtain topmost element
                    calc_stk.pop();     //pop element
                    mixedNumber right;
                    right = calc_stk.top(); //assign next topmost element
                    calc_stk.pop(); //pop

                    calc_stk.push(left + right); //push the desired operation result back to the stack

                }break;

                case '-':{

                    mixedNumber left;
                    left = calc_stk.top();
                    calc_stk.pop();
                    mixedNumber right;
                    right = calc_stk.top();
                    calc_stk.pop();

                    calc_stk.push( right - left );

                }break;

                case '*':{
                    mixedNumber left;
                    left = calc_stk.top();
                    calc_stk.pop();
                    mixedNumber right;
                    right = calc_stk.top();
                    calc_stk.pop();

                    calc_stk.push(left * right);

                }break;

                case '/':{

                    mixedNumber left;
                    left = calc_stk.top();
                    calc_stk.pop();
                    mixedNumber right;
                    right = calc_stk.top();
                    calc_stk.pop();

                    calc_stk.push( right / left);

                }break;

                default:{
                    throw SYNTAX_ERROR; //Old
                }


            }
        out_que.pop();
        }

    }


    return calc_stk.top(); //After all operations are done, there is only 1 element on the stack, which is the answer

}

string clean(string str){ //Removes all whitespace, except those in between numbers, since they denote a mixed fraction

    string::iterator it;
    for ( it = str.begin() ; it < str.end(); it++ ){ //Usage of iterators for to use erase function and make string manipulation easier

        //for ever whitespace found...
        if (*it == ' '){

            //if the next character is a digit and the previous is a digit, then keep it
             if (isdigit(*(it+1)) && isdigit( (it == str.begin()) ? (*it) : (*(it-1))) ) //the ternary operator used here is to avoid it-1 calculation at beginning of string so as to not overrun boundary.
                 continue;//skip back to top;
            //if not, then remove.
            str.erase(it);
            it--;
        }


      }
    return str;
}

bool look_for_error(string str){

    size_t sz, ssz;
    sz = str.find_first_not_of("0123456789/*-+)( "); //If other stuff other than this is typed, then error
    ssz = str.find_first_of("+-*/");

    if (str[0] == '+' || str[0] == '*' | str[0] == '/'){
        return true;
    }
    string::iterator ait;

    if (string::npos != ssz){ //If we found an operator
        bool syntax_error = true; //Assume there is a syntax error
        ait = str.begin();
        ait += ssz;
        for (; ait < str.end(); ait++){ //There HAS to be another number in the expression or else syntax error
            if (isdigit(*ait)){
                syntax_error = false; //There isnt a syntax error
            }
        }
        if (syntax_error){
            return true;
        }
    }
    ait = str.begin();
    while(ait < str.end()){
        if (*ait == ' '){
            if (!isdigit(*( (ait != str.end() ? ++ait : ait) )) || (*( (ait != str.end() ? ++ait : ait) )) != '/' || !isdigit(*( (ait != str.end() ? ++ait : ait) ))  ){
                return true;
            }
        }
        ait++;
    }

    ait = str.begin();
    while(ait < str.end()){
        if (*ait == '+' || *ait == '*' || *ait == '/'){
            if (ispunct(*( (ait != str.end() ? ++ait : ait) )) && (*ait != '(' || *ait != ')' || *ait != '-')){
                return true;
            }
        }
        ait++;
    }

    string::iterator it;
    int leftp = 0, rightp = 0;
    for (it = str.begin(); it < str.end(); it++){ //test fo parenthesis syntax
        if (*it == ')'){
            rightp++;
        }else if(*it == '('){
            leftp++;
        }
    }
    if (leftp != rightp){ //Amount of left parenthesis must match right parenthesis
        return true;
    }

    bool fnd = false;
    for (it = str.begin(); it < str.end(); it++){ //Make sure left and right parenthesis match, i.e check for: "5+)-8("
        if (*it == '('){
            fnd = true;
        }
        if (*it == ')'){ //We can only find a right parenthesis if the above sttatement was true.
            if (fnd == false){
                return true;
            }
        }
    }




    /*size_t szm;

    for(it = str.begin(); it < str.end(); it++){
        szm = str.find()
    }*/

    if (sz != string::npos || ssz == string::npos){ //If we dont find any operators parenthesis or numbers, then its an error.

        return true;
    }

    return false;
}

