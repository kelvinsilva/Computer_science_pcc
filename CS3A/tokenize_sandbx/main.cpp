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

mixedNumber double_to_fraction(double dec);

int get_num_of_places(double dec){

    int counter = 0;
    int integer_val = 0;
    bool bool_cond = true;
    do {

        integer_val = trunc(dec);

        dec = abs(integer_val - dec);

        dec *= 10;

        counter++;

    }while (  !((int)floor((float)dec) == (int)ceil((float)dec)) );

    return counter;

}

mixedNumber getImproper(mixedNumber frac)
{

    if (frac.whole == 0){
        mixedNumber ret_val;
            ret_val.whole = 0;
            ret_val.num = frac.num;
            ret_val.denom = frac.denom;
        return ret_val;
    }else {
        mixedNumber ret_val;
           ret_val.whole = 0;
           ret_val.num = frac.whole*frac.denom;
           ret_val.num += frac.num;
           ret_val.denom = frac.denom;
       return ret_val;

    }

}

double getDecimal(mixedNumber frac){
    mixedNumber ret_val = getImproper(frac);
    return (double)ret_val.num/ret_val.denom;
}



int * tokenize_str(string str){

    int *tokens = new int[256]();
    char temp_str[256]{};
    //char opers[256]{}; //if ct greater than 5 syntax error

    int token_ct = 0 ;
   // int opers_ct = 0;
    int temp_str_ct = 0;
    for (int i = 0; i < str.size(); i++){

       if ( ispunct(str[i]) && str[i] == '-' && isdigit(str[i+1]) ){

            temp_str[temp_str_ct] = str[i];
            temp_str_ct++;
       }
       if (isdigit(str[i])){

            temp_str[temp_str_ct] = str[i];
            temp_str_ct++;
       }
       if (iswspace(str[i]) && isdigit(str[i-1]) && isdigit(str[i+1])){
            tokens[token_ct] = str[i];
            token_ct++;
       }

       if (ispunct(str[i]) && str[i] == '-' && (isdigit(str[i+1]) && isdigit(str[i-1])) || (is) ){

            tokens[token_ct] = str[i];
            token_ct++;

       }

       if (ispunct(str[i]) && str[i] != '-'){
            tokens[token_ct] = str[i];
            token_ct++;
       }

       if (isdigit(str[i]) && (ispunct(str[i+1]) || iswspace(str[i+1]) || str[i+1] == '\0' )){
                tokens[token_ct] = atoi(temp_str);
                memset(temp_str, 0, 256);
                token_ct++;
                temp_str_ct = 0;

           if (str[i+1] == '\0'){
                break;
           }
       }



    }
    return tokens;
}

int main(){

    stringstream ss;
    string line = "1 - 1";
    int * my_toks = tokenize_str(line);

    for (int i = 0; i < 256; i++){
        cout << my_toks[i] << endl;
    }


    return 0;
}

mixedNumber double_to_fraction(double dec){

    if (dec > 0){

        mixedNumber temp;
        temp.whole = trunc(dec);
        double decDecimal = abs(trunc(dec) - dec);
        int number_to_raise = get_num_of_places(decDecimal);
        int numerator = decDecimal * pow(10, number_to_raise);
        int denominator =  pow(10, number_to_raise);

        temp.num = numerator;
        temp.denom = denominator;
        return temp;

    }else {
        mixedNumber temp;
        temp.whole = trunc(dec);
        double decDecimal = abs(trunc(dec) - dec);
        int number_to_raise = get_num_of_places(decDecimal);
        int numerator = decDecimal * pow(10, number_to_raise) * -1;
        int denominator =  pow(10, number_to_raise);

        temp.num = numerator;
        temp.denom = denominator;
        return temp;
    }



}
