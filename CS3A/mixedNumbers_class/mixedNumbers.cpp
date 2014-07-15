
#include "mixedNumbers.h"

mixedNumber::mixedNumber()
{
    whole = 0;
    num = 0;
    denom = 1;
}

mixedNumber::mixedNumber(long w, long n, long d){

    whole = w;
    num = n;
    denom = abs(d);

}

mixedNumber::mixedNumber( bool sbit, long w, long n, long d){

    whole = sbit ? w*-1 : w;
    num = sbit ? n*-1 : n;
    denom = abs(d);

}

mixedNumber::~mixedNumber(){

};


void mixedNumber::reduce()
{
    int div, newNum;
    newNum = denom * whole + num;
    div = gcd(newNum, denom);
    newNum /= div;
    denom /= div;
    whole = newNum / denom;
    num = newNum % denom;
}

long mixedNumber::gcd(int p, int q)
{
    return q == 0 ? p : gcd(q, p%q);
}

/*
int mixedNumber::gcd(int p, int q)
{
    int r;
    while((r = p%q) != 0)
    {
        p = q;
        q = r;
    }
    return q;
)

    return
}
*/

void mixedNumber::output()
{
    if(whole == 0 && num == 0)
        cout<<0;
    else
      if(whole == 0)
        cout<<num<<"/"<<denom;
      else
         if(num == 0)
                cout<<whole;
         else
                cout<<whole<<" "<<num<<"/"<<denom;
}

long mixedNumber::getWhole(){
    return whole;

}

long mixedNumber::getNumerator(){
    return num;
}

long mixedNumber::getDenominator(){
    return denom;
}

/////////////////////////////////////////////////////////////

void mixedNumber::setWhole(long w){
    whole = w;
}

void mixedNumber::setNumerator(long q){
    num = q;
}

void mixedNumber::setDenominator(long q){
    //lets make sure that the denominator is positive.
    denom = abs(q);
}

mixedNumber& mixedNumber::operator= (const mixedNumber& y){

    this->whole = y.whole;
    this->num = y.num;
    this->setDenominator( y.denom);

    return *this;

}
//Originally implemented as double_to_fraction
mixedNumber& mixedNumber::operator= ( double dec){

    if (dec > 0){


        this->whole = trunc(dec);
        double decDecimal = abs(trunc(dec) - dec);
        int number_to_raise = get_num_of_places(decDecimal);
        int numerator = decDecimal * pow(10, number_to_raise);
        int denominator =  pow(10, number_to_raise);

        this->num = numerator;
        this->setDenominator( denominator);

        return *this;

    }else {

        this->whole = trunc(dec);

        double decDecimal = abs(trunc(dec) - dec);

        int number_to_raise = get_num_of_places(decDecimal);
        int numerator = decDecimal * pow(10, number_to_raise) * -1;
        int denominator =  pow(10, number_to_raise);

        this->num = numerator;
        this->setDenominator( denominator);

        return *this;
    }

}


double mixedNumber::getDecimalVal(){

    mixedNumber temp = this->getImproper();
    return (double)temp.getNumerator()/temp.getDenominator();

}


mixedNumber mixedNumber::getImproper(){

    mixedNumber ret_val;

    if (whole == 0){

                ret_val.setNumerator(num);
                ret_val.setDenominator(denom);
                ret_val.setWhole(0);
    }else {

               int nume = whole*denom;
               nume += num;
               ret_val.setNumerator(nume);
               ret_val.setDenominator(denom);
               ret_val.setWhole(0);

    }

    return ret_val;
}



mixedNumber operator+ (mixedNumber &x, mixedNumber &y){

    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num)*y.denom + (y.whole*y.denom+y.num)*x.denom;
    ans.setDenominator( x.denom * y.denom);
    ans.reduce();

    return ans;
}

mixedNumber operator- (mixedNumber &x, mixedNumber &y){

    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num)*y.denom - (y.whole*y.denom+y.num)*x.denom;
    ans.setDenominator( x.denom * y.denom );
    ans.reduce();
    return ans;
}

mixedNumber operator* (mixedNumber &x, mixedNumber &y){

    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num) * (y.whole*y.denom+y.num);
    ans.setDenominator( x.denom * y.denom );
    ans.reduce();
    return ans;
}

mixedNumber operator/ (mixedNumber &x, mixedNumber &y){

    mixedNumber ans;
    ans.num = (x.whole*x.denom+x.num) * y.denom;
    ans.setDenominator( x.denom * (y.whole*y.denom+y.num) );
    ans.reduce();
    return ans;
}

mixedNumber operator^ (mixedNumber &x, mixedNumber &y){

    double frac_to_convert = pow(x.getDecimalVal(), y.getDecimalVal());

    mixedNumber ret_val;
    ret_val = frac_to_convert;

    return ret_val;
}

int get_num_of_places(double dec){

    int counter = 0;
    int integer_val = 0;

    do {

        integer_val = trunc(dec);
        dec = abs(integer_val - dec);

        dec *= 10;
        counter++;

    }while ( !((int)floor((float)dec) == (int)ceil((float)dec)) && (counter != 7) ); //counter!=7, to DEFAULT at most 7 decimal places.
                                                                                    //Any more will put too much error, bit overrun

    return counter;

}


/*double mixedNumber::decimal_val_set(){

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

}*/

