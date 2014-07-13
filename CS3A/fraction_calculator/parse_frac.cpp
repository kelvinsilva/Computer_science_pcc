#include "parse_frac.h"
//Kelvin Silva

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
int find_size_array(int tokens[]){

    int i = 0;
    for ( ;tokens[i]!= 0; i++){ //token array of size 256 is all initialized to zero. When a zero is reached in token stack, then it is end of calculation

    }
    return i;

}
//for usage in interpret tokens
//In our binary array of name temp (int temp[2]), we need to siphon tokens from my_toks into the temp array. Seed feed starts this process
void seedfeed(int tokens[], int &ct, int temp[]){


    temp[1] = tokens[ct++];
    temp[0] = temp[1];
    temp[1] = tokens[ct++];

}
//Each successive call to feed after seedfeed, erases contents of temp[0] and replaces with temp[1]. Another token from my_toks is placed into temp[1];
void feed (int tokens[], int &ct, int temp[]){

    temp[0] = temp[1];
    temp[1] = tokens[ct++];
}
//This function is to count how many total operators there are. A / symbol in a fraction counts as an operator. 5/7 has 1 operator. -5 5/6 / 5/6 has 4 operators/
//I use this function in interpret tokens. If there its only one operator, then i use a simple algorithm to transform tokenization into mixed numbers
//If there is more than 1 operator, then we use the more complicated way. (see interpret_tokens)
int count_operators (int * my_toks){
    int ret_val = 0;
    for (int i = 0; my_toks[i] != 0; i++){

        if (ispunct(my_toks[i])){
            ret_val++;
        }
    }
    return ret_val;
}

void interpret_tokens(mixedNumber &num_one, mixedNumber &num_two, char &op, int tokens[], int num_operators){

    int ct = 0;
    int temp[2] = {}; //Tokens will be siphoned into this array of two.
    bool division_flag[2] = {false, false}; //these values correspond to temp [0] and temp[1] respectively. I could have use a struct to combine into 1.
    //Division flag is set if the respective temp[] slot has come across a /.  when both flags are set, it indicates that the next / that i come across, is an operator, not a signal for numerator and denominator
    //After i come across my operator, then both flags are set to false, and my next / must signal a numerator and denominator.
    bool div_is_operator = false; //Flag to be set.

    int siz = find_size_array(tokens); //Get size to know how many times to iterate through tokens

    //Values to be assigned to mixed numbers structure
    int numers[2] = {};
    int denoms[2] = {1, 1};
    int wholes[2] = {};
    //Keep count of how many fractions, or mixed number we come across. Highest value for this will be 2 since there are only two input values.
    int mix_ct = 0;

    seedfeed(tokens, ct, temp); // Start the seed of temp[] array. Call only once!

    if (num_operators > 1){ //Dealing with fractions, COMPLICATED WAY
        for (int i = 0; ct <= siz+1; i++){ //We go ct <= siz+1, because I want to read in a trailing 0 token.

            //If any temps come across a division sign, and the flags have not been set, then we set the flag.
            if (temp[0] == '/' && !division_flag[0]){
                division_flag[0] = true;

            }
            if (temp[1] == '/'  && !division_flag[1]){
                division_flag[1] = true;

            }
            //////////////////////////
            //See line 120 for setting of division flag.

            if (temp[0] == '/' && !div_is_operator){ //If the division sign is not an operator and temp is a /, then assign numerator and denominator accordingly
                denoms[mix_ct] = temp[1];   // if temp[0] = /, then that means in 5/6, temp[0] = / and temp[1] = 6, in this pattern, 5 is denominator.
            }

            if (temp[1] == '/' && !div_is_operator){ //Likewise the respective pattern occurs for numerators
                numers[mix_ct] = temp[0];

            }else if (temp[0] == '+' ||temp[0] == '*' ||temp[0] == '-'  || temp[0] == '^' || (temp[0] == '/' && div_is_operator) ){ //If neither is an operator of "/" and division IS an operator... Set OP to appropriate operator, move to next mixed number.
                op = temp[1];
                mix_ct++;
                feed(tokens, ct, temp); //We feed only once here because temp[0] has an operator. We need to get rid of operators
                div_is_operator = false; //The next division sign i come across is going to be a fraction. Since we already hit the operator
                continue;

            }else if (temp[1] == '+' ||temp[1] == '*' ||temp[1] == '-'  || temp[1] == '^' || (temp[1] == '/' && div_is_operator) ) {
                op = temp[1];
                mix_ct++;
                feed(tokens, ct, temp); //we feed twice becaise temp[1] is operator. I want to flush out both temps to bring in new tokens.
                feed(tokens, ct, temp);
                div_is_operator = false;
                continue;
           }

            if (division_flag[0] && division_flag[1]){
                div_is_operator = true;
                division_flag[0] = false;
                division_flag[1] = false;

            }


            if (temp[1] == ' '){ //If i get a whitespace, then the number in temp[0] HAS to be a mixed number since the pattern for typign mixed number is as follows:
                    // 5 5/6 ONLY a pattern like this is the way we type mixed numbers. So when feeding, the 5 HAS to be in temp[0], thile temp[1] HAS to have whitespace.
                    //It is the only pattern available to type and recognize.
                wholes[mix_ct] = temp[0];
                feed(tokens, ct, temp); //Feed twice to flush
                feed(tokens, ct, temp);
                continue;
            }
            //This if is a special case for something like 1/2/3, where it is 1/2 / 3, where 1/2 is a mixed number and 3 is a whole number with operator of '/'
            //In this special pattern, the last number is ALWAYS at the end or ALWAYS near the operator.
            if ((temp[1] == '+' ||temp[1] == '*' ||temp[1] == '-'|| (temp[1] == '/' && div_is_operator) || temp[1] == '^') || (temp[1] == 0 && !div_is_operator )){
                wholes[mix_ct] = temp[0];

            }

            feed(tokens, ct, temp); //Feed next token. If the if statements above have a continue, this is skipped

        }
    }else if (num_operators == 1){ //dealing with regular expression, SIMPLE WAY

        //Look at this for an easy understanding of how the algorithm works.
        //If i have 2 + 4, then temp[0] is going to be 2, and temp[1] is going to be a + sign. So we assign temp[0] for a whole number, and temp[1] for a operator.
        //Then we feed and we KNOW that temp[1] is going to have the new token. What is left now that we have eaten 1 token?
        //After eating 1 token temp[0] will be the operator, and temp[1] will be the new value. We dont care about temp[0] since we already assigned operator, so we dont check it.
        //We care about temp[1] since it has a new value, so then we assign temp[1] to whole[1].
        wholes[0] = temp[0];
        op = temp[1];
        feed(tokens, ct, temp);
        wholes[1] = temp[1];

    }

    num_one.num = wholes[0] < 0 ? numers[0] * -1 : numers[0]; //If the whole number is negative in a mixed fraction, then assign negative numerator, else leave numerator original value
    num_two.num = wholes[1] < 0 ? numers[1] * -1 : numers[1]; //If the whole number is negative in a mixed fraction, then assign negative numerator, else leave numerator original value
    num_one.denom = denoms[0];
    num_two.denom = denoms[1];
    num_one.whole = wholes[0];
    num_two.whole = wholes[1];



}

//This function converts a string of characters into integral token values in int my_toks
//The ultimate true purpose of this function is to view expressions like 524352345 + 423424 and 1 + 1 in the same manner.
//If i were to analyze the string directly we must recall that each digit in a number has its character value.
//This function takes 524352345 and makes it into a single token, and 1 in 1+1 into a single token.
// in other words, 524352345 + 423424 has many tokens as a string, and 1 + 1 has only 3 tokens as a string.
//We convert both strings into simple tokenizations such that 524352345 + 423424 has 3 tokens and 1 + 1 has 3 tokens
//Then we can process the list of tokens in the interpret_tokens function viewing it in the same manner as a simple 1 + 1 expression.
int* tokenize_str(string str)
{

    int *tokens = new int[256](); //Clear all
    char temp_str[256];
    memset(temp_str, 0, 256); //Clear all



    int token_ct = 0 ;
   // int opers_ct = 0;
    int temp_str_ct = 0; //for use with char temp_str
    bool neg_bit = true;
    //bool picked_up_operator = false;

    //In this loop we have alot of conditionals which try to match patterns of how the user types in a number
    for (int i = 0; i < str.size(); i++){

        //For every character we are looking at....
        //If it is a digit, then
       if (isdigit(str[i])){

            temp_str[temp_str_ct] = str[i]; //put it inside a temporary chracter array.
            temp_str_ct++;
       }
       if (iswspace(str[i]) && isdigit(str[i-1]) && isdigit(str[i+1])){ //If it is a whitespace and the character before it is a digit, and the character after it is a digit
            tokens[token_ct] = str[i];  //Put the whitepspace in the tokens
            token_ct++; //Fill next token in list
       }

       if (ispunct(str[i]) && str[i] == '-'){ //if i have an operation of negative sign

             if  (iswspace(str[i+1]) || iswspace(str[i-1])){ //if my next character is a whitespace or previous character is a white space,
                                                            //(for example) 1 - 1, Whitespaces encover the + sign.
                //WARNING: this if may be obsolete with whitespace cleaning function above.
               tokens[token_ct] = str[i];   //Make it a minus sign in tokens
               token_ct++;
               neg_bit = false; //Set the neg bit so that we know that any other '-' in the expressiong denotes a negative number, not an operation

             }else if (isdigit(str[i+1]) && isdigit(str[i-1])){ //or if the numbers before and after it are digits
                       tokens[token_ct] = str[i];           //For example 1-1,
                       token_ct++;
                       neg_bit = false;
             }else if(isdigit(str[i-1]) && ispunct(str[i+1])){ //Or if i have a negative number next to a negative number.
                 tokens[token_ct] = str[i];     //Like 1--1
                 token_ct++;
                 neg_bit = false;
             }

       }
       //If negbit is set, but the character into the temporary string.
       //This temporary temp_str string holds my numerical value which i will later call atoi() on.
       //So i can catch a huge number like -183909 and convert it to an easy integral value token
       if ( ispunct(str[i]) && str[i] == '-' && isdigit(str[i+1]) && neg_bit ){

            temp_str[temp_str_ct] = str[i];
            temp_str_ct++;
       }

        //if I am anything other than a number, whitespace, or a negative number, i will put it in my_toks as an operation
        //Remember, negative sign has special cases for it to be an operator (look at above if statements). We are dealing with ^ + * and / here.
       if (ispunct(str[i]) && str[i] != '-'){

           tokens[token_ct] = str[i];
            token_ct++;
       }

        //If when i am reading in my string, i am ontop of a digit, and the next character is a punctuation (meaning, a operator), or a whitespace, or the end,
        //Process my string to convert into integral value token
       if (isdigit(str[i]) && (ispunct(str[i+1]) || iswspace(str[i+1]) || str[i+1] == '\0' )){
                tokens[token_ct] = atoi(temp_str); //Call atoi()
                memset(temp_str, 0, 256); //Clear the temp_str
                token_ct++; //go to next token
                temp_str_ct = 0; //Set the temp_str_ct back to zero

           if (str[i+1] == '\0'){ //If i am near the end of the string, I break off.
                break;
           }
       }

        neg_bit = true; //After reading each token, set neg_bit to its default state of true.

    }
    return tokens; //Give me back a pointer to integral token value
}

//This function encompasses all functions written.
int parse_line(string line, mixedNumber &num_one, mixedNumber &num_two, char &op){

    cout << clean(line)<<endl; //Clean the input string of any whitespaces that are NOT in between two numbers
    int * my_toks = tokenize_str(clean(line)); //Convert the string input into integral token values


    op = 0;            //ret val //Make sure my operator is zero

    int operator_count = count_operators(my_toks); //Count the operators that I have to determine if if have an error in my syntax (more than 5 operations),
    //And as well as to determine if i should use the simple algorithm or complicated algorithm
    if (operator_count > 5){
        cerr << "syntax Error";
        cin.get();
        return 0; //failure
    }
    //Interpret my integral tokens into an operation, and two mixed numbers
    interpret_tokens(num_one, num_two, op, my_toks, operator_count);
    //Remember, the operation, and mixed numbers are passed by reference, so their value is changed in interpret_tokens. No return value is needed.

    delete [] my_toks; //Clear memory

    return 1; //success
}


