#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "mixednumber.h"


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
mixedNumber POWE(const mixedNumber &x, const mixedNumber &y);

mixedNumber getImproper(mixedNumber frac);
mixedNumber double_to_fraction(double dec);

double getDecimal(mixedNumber frac);
int get_num_of_places(double dec);


int main()
{
    mixedNumber x, y, z;
    char op;
    string line;
    while(getLine(line))
    {
        getInput(line, x, op, y);
        calculate(x,op,y,z);
        output(x,op,y,z);
        //z = getImproper(y);
        //cout << "whole: " << z.whole << " numer: " << z.num << " denom: " << z.denom;
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


    cout << "x_temp num: " << x_temp.num << endl;
    cout << "y_temp.num: " << y_temp.num << endl;

    mixedNumber power_root = getImproper(y);
    power_root.whole = 0;
    power_root.num = 1;

    double dec_to_raise_root = getDecimal(power_root);
    cout << "dec to raise roodt" << dec_to_raise_root << endl;

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


mixedNumber getValue(string &line)
{
    stringstream ss;
    char junk;
    mixedNumber x;
    x.whole = 0;
    x.num = 0;
    x.denom = 1;
    ss<<line;
    if(line.find(' ') < line.size()) //Do I have a true mixed number
        ss>>x.whole>>x.num>>junk>>x.denom;//Yes, read in
    else
        if(line.find('/') < line.size()) //If not, then do I have just a fraction
        {
            x.whole = 0;
            ss>>x.num>>junk>>x.denom; //If so, read it in
        }
        else //If not, all I have is a whole number, so read it in.
        {
            x.num = 0;
            x.denom = 1;
            ss>>x.whole;
        }
    return x;
}

void getInput(const string &line, mixedNumber &x, char &op,mixedNumber &y)
{
    char data;
    string first, second;
    stringstream ss;
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;

    ss << line;
    ss >> num1;


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
