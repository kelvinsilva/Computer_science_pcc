//Kelvin Silva
//The fraction parsing module was rewritten, and is inside parse_frac.cpp/h as well as POWE function added for powers
//Can only do calculation between two numbers and/or mixed fractions
//The add, sub, mult, div and POWE functions were not rewritten for negative numbers. All rules of negative numbers are followed naturally.
//If the fraction is typed as -5 1/6, then the program multiplies the numerator (1 in 1/6) by -1 if whole number is negative.

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "mixednumber.h"
#include "parse_frac.h"

using namespace std;

bool getLine(string &line);
void getInput(const string &line, mixedNumber &x, char &op,mixedNumber &y);
void trim(string &line);
mixedNumber getValue(string &line);
void output(mixedNumber x, char op, mixedNumber y, mixedNumber z);
void calculate(const mixedNumber &x, char op, const mixedNumber &y, mixedNumber &z);

mixedNumber add(const mixedNumber &x, const mixedNumber &y);
mixedNumber sub(const mixedNumber &x, const mixedNumber &y);
mixedNumber mult(const mixedNumber &x, const mixedNumber &y);
mixedNumber div(const mixedNumber &x, const mixedNumber &y);
mixedNumber POWE(const mixedNumber &x, const mixedNumber &y); //Power function written


mixedNumber getImproper(mixedNumber frac); //Auxiliarry function to make power calculation easier
mixedNumber double_to_fraction(double dec); //Auxiliarry function to make power calculation easier
double getDecimal(mixedNumber frac);
int get_num_of_places(double dec); //Used in converting a double to a fraction



int main()
{
    mixedNumber x, y, z;
    char op;
    string line;
    while(getLine(line))
    {

        op = parse_line(line, x, y, op) ? op : -1; //Parse line new module rewritten. Assign to operator value of -1 if function returns 0 (fail to parse)
                                                    //Else maintain original value of op.
                                                    cout << "\nop: " << op << "\n";
        calculate(x,op,y,z);
        output(x,op,y,z);
    }
    return 0;
}

mixedNumber add(const mixedNumber &x, const mixedNumber &y)
{
    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num)*y.denom + (y.whole*y.denom+y.num)*x.denom;
    ans.denom = x.denom * y.denom;
    ans.reduce();
    return ans;
}

mixedNumber sub(const mixedNumber &x, const mixedNumber &y)
{
    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num)*y.denom - (y.whole*y.denom+y.num)*x.denom;
    ans.denom = x.denom * y.denom;
    ans.reduce();
    return ans;
}

mixedNumber mult(const mixedNumber &x, const mixedNumber &y)
{
    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num) * (y.whole*y.denom+y.num);
    ans.denom = x.denom * y.denom;
    ans.reduce();
    return ans;
}

mixedNumber div(const mixedNumber &x, const mixedNumber &y)
{
    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num) * y.denom;
    ans.denom = x.denom * (y.whole*y.denom+y.num);
    ans.reduce();
    return ans;
}

int get_num_of_places(double dec){

 int counter = 0;
    int integer_val = 0;

    do {

        integer_val = trunc(dec);

        dec = abs(integer_val - dec);
        dec *= 10;

        counter++;

    }while (  !((int)floor((float)dec) == (int)ceil((float)dec)) && (counter != 7) ); //counter!=7, to DEFAULT at most 7 decimal places.
                                                                                      //Any more will put too much error, bit overrun

    return counter;

}

mixedNumber POWE(const mixedNumber &x, const mixedNumber &y){

    mixedNumber ans;
    mixedNumber x_temp = getImproper(x);
    mixedNumber y_temp = getImproper(y);


    mixedNumber power_root = getImproper(y);
    power_root.whole = 0;
    power_root.num = 1;

    double dec_to_raise_root = getDecimal(power_root);

    double numer_temp = pow(x_temp.num, dec_to_raise_root);
    double denom_temp = pow(x_temp.denom, dec_to_raise_root);

    double frac_to_convert = numer_temp / denom_temp;

    frac_to_convert = pow(frac_to_convert, y_temp.num);

    mixedNumber ret_val = double_to_fraction(frac_to_convert);

    return ret_val;



   /* ans.num = pow(x_temp.num, y_temp.num);
    ans.denom = pow(x_temp.denom, y_temp.num);
    y_temp.num = 1;
    y_temp.whole = 0;


    double decans, decy;
    decans = getDecimal(ans);
    decy = getDecimal(y_temp);

    double answer = pow(decans, decy);*/


    /*mixedNumber ret_val;

    int num_to_raise = get_num_of_places( answer );

    int numerwhole = ( abs(trunc(answer) - answer) * pow(10, num_to_raise));

    ret_val.whole = trunc(answer);
    ret_val.num = numerwhole;
    ret_val.denom = pow(10, num_to_raise);

    return ret_val;*/

}



void calculate(const mixedNumber &x, char op, const mixedNumber &y, mixedNumber &z)
{
    switch(op)
    {
        case '+' : z = add(x,y);
                   break;
        case '-' : z = sub(x, y);
                   break;
        case '*' : z = mult(x, y);
                   break;
        case '/' : z = div(x, y);
                    break;
        case '^' : z = POWE(x, y);
                    break;
        default  : cout<<"unknown operator!"<<endl;
    }
}


void output(mixedNumber x, char op, mixedNumber y, mixedNumber z)
{
    x.output();
    cout<<" "<<op<<" ";
    y.output();
    cout<<" =  ";
    z.output();
    cout<<endl;
}


void trim(string &line)
{
    while(line[0] == ' ')
        line.erase(0,1);
    while(line[line.size()-1] == ' ')
        line.erase(line.size()-1);
}

bool getLine(string &line)
{
    cout<<"Input: ";
    getline(cin,line);
    trim(line);
    return line != "";
}



double getDecimal(mixedNumber frac){
    mixedNumber ret_val = getImproper(frac);
    return (double)ret_val.num/ret_val.denom;
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
