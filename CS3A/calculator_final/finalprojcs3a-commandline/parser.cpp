#include "parser.h"
#include "token_definition.h"


map <char, int> Parser::precedence_operator = init_map();

void Parser::clear_parser(){
    queue<token> empty;
    swap(output_queue, empty);

    stack<char>emptystk;
    swap(operator_stack, emptystk);

    algebraic = "";
    rpn = "";

}

queue <token> Parser::get_output_queue(){

    return output_queue;

}

string Parser::get_rpn_str(){
    return rpn;
}

void Parser::set_string(string st){
    algebraic = st;
}

void Parser::parse_algebraic(){

    string stre = algebraic;

    stringstream ss;
    ss.str(stre);

    mixedNumber temp;
    token temp_tok;

    ss >> temp;
    temp_tok.setNumber(temp);
    output_queue.push(temp_tok);

    while (ss.good()){ //While there are tokens to be read

            //If we encounter any operator such as +-*/
        if( ss.peek() == '+' || ss.peek() == '-' || ss.peek() == '/' || ss.peek() == '^' || ss.peek() == '*' ){

            //Then for every operator that the stack currently has, make sure to check the precedence of this operator with any operator on the stack.
            //If the precedence of the operator being read is less than any on the stack, pop the operator on stack to output queue.
            while( operator_stack.size() > 0 && (precedence_operator[ ss.peek() ] <= precedence_operator[ operator_stack.top() ]) ){

                temp_tok.setChar(operator_stack.top());
                output_queue.push( temp_tok );
                operator_stack.pop();
            }
            operator_stack.push(ss.get());

            if (ss.peek() !='('){ //Immediately read the next token, This is to take care of - signs to be read
                ss>>temp;
                temp_tok.setNumber(temp);
                output_queue.push(temp_tok);
            }

        }else if (isdigit(ss.peek())){ //if our token is a number, read in the number as per mixedNumber >> operator
            ss >> temp;
            temp_tok.setNumber(temp);
            output_queue.push(temp_tok);

        }else if (ss.peek() == '('){ //if ther eis a left parenthesis, pushto stack

            operator_stack.push(ss.get());


        }else if (ss.peek() == ')'){ //If we reach a right parenthesis, throw it away, then push all operations from stack to output queue until left parenthesis is reached
            ss.get();
            while(operator_stack.top() != '(' && operator_stack.size() > 0){
                    temp_tok.setChar(operator_stack.top());
                    output_queue.push(temp_tok);
                    operator_stack.pop();
            }
           // try{
                if (operator_stack.top() == '('){ //Throw away left parenthesis
                    operator_stack.pop();
                }else {
                   // throw MISMATCH_PARENTH; NOTE: errores will be checked in util_calc_funcs look_for_error function
                }
           // }
           /* catch(ERRORS err){
                if (err == MISMATCH_PARENTH)
                    cout << "Miasmatched parenthesis, ignoring parenthsis.";

                exit(1);
              }*/
        }
    }
   // try{
        while (operator_stack.size() > 0){ //Once there are no more tokens to be read, push all operators from stack to output queue
            //if (operator_stack.top() == '(' || operator_stack.top() == ')')
             //   throw MISMATCH_PARENTH;

            temp_tok.setChar(operator_stack.top());
            output_queue.push(temp_tok);
            operator_stack.pop();

        }
   // }
  /*  catch (ERRORS err){
        if (err == MISMATCH_PARENTH)
            cout << "Miasmatched parenthesis, ignoring parenthsis.";

            //exit(1);
    }*/

    //Assign output queue to rpn string representation
    output_queue_assign_to_rpn_str(output_queue);

}

void Parser::output_queue_assign_to_rpn_str(queue<token>& out_queue){ //Put all things in queue on string.
    int x = out_queue.size(); //Get queue size
    stringstream sss;
    for (int i = 0; i < x; i++){ //Iterate for as many elements in the queue.
            sss << out_queue.front() << ' '; //Insert the elements in front of queue into string
            out_queue.push(out_queue.front()); //Copy the front element to the back
            out_queue.pop(); //Pop front element

    } //Once the loop is finished, the output queue remains the same.
    rpn = sss.str(); //Assign contents of stream to string.

}
