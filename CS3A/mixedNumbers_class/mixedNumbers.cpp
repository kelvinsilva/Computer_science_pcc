
#include "mixednumber.h"

mixedNumber::mixedNumber()
{
    whole = 0;
    num = 0;
    denom = 1;
}

mixedNumber::mixedNumber(long w, long n, long d){

    whole = n ? w : 0;
    num = n ? n : w;
    denom = abs(d);

}

mixedNumber::mixedNumber( bool sbit, long w, long n, long d){

    whole = n ? w : 0;
    num = n ? n : w;

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

long mixedNumber::getWhole() const{
    return whole;

}

long mixedNumber::getNumerator() const{
    return num;
}

long mixedNumber::getDenominator() const{
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

        this->reduce();

        return *this;

    }else {

        this->whole = trunc(dec);

        double decDecimal = abs(trunc(dec) - dec);

        int number_to_raise = get_num_of_places(decDecimal);
        int numerator = decDecimal * pow(10, number_to_raise) * -1;
        int denominator =  pow(10, number_to_raise);

        this->num = numerator;
        this->setDenominator( denominator);

        this->reduce();

        return *this;
    }

}


double mixedNumber::getDecimalVal() const{

    mixedNumber temp = this->getImproper();
    return (double)temp.getNumerator()/temp.getDenominator();

}


mixedNumber mixedNumber::getImproper() const{

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

mixedNumber& mixedNumber::operator+=(const mixedNumber &y){


    this->num = (this->whole*this->denom+this->num)*y.denom + (y.whole*y.denom+y.num)*this->denom;
    this->setDenominator( this->denom * y.denom);
    this->reduce();


    return *this;

}

mixedNumber& mixedNumber::operator-=(const mixedNumber &y){

    this->num = (this->whole*this->denom+this->num)*y.denom - (y.whole*y.denom+y.num)*this->denom;
    this->setDenominator( this->denom * y.denom);
    this->reduce();


    return *this;
}

mixedNumber& mixedNumber::operator*=(const mixedNumber &y){

    this->num = (this->whole*this->denom+this->num) * (y.whole*y.denom+y.num);
    this->setDenominator( this->denom * y.denom );
    this->reduce();

    return *this;
}

mixedNumber& mixedNumber::operator/=(const mixedNumber &y){

    this->num = (this->whole*this->denom+this->num) * y.denom;
    this->setDenominator( this->denom * (y.whole*y.denom+y.num) );
    this->reduce();
    return *this;

}

mixedNumber& mixedNumber::operator^=(const mixedNumber &y){


    double frac_to_convert = pow(this->getDecimalVal(), y.getDecimalVal());

    *this = frac_to_convert;

    return *this;
}

mixedNumber operator+ (mixedNumber x, const mixedNumber &y){

    x += y;
    return x;
}

mixedNumber operator- (mixedNumber x, const mixedNumber &y){

    x += y;
    return x;
}

mixedNumber operator* ( mixedNumber x, const mixedNumber &y){

    x *= y;
    return x;

}

mixedNumber operator/ ( mixedNumber x, const mixedNumber &y){

     x /= y;
     return x;
}

mixedNumber operator^ ( mixedNumber x, const mixedNumber &y){

    x ^= y;

    return x;
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

istream& operator>>(istream &in, mixedNumber &x)
{
    int whole = 0, num = 0, denom = 1;
    char junk;
    in>>whole;
    if(in.peek() == '/')
    {
        num = whole;
        whole = 0;
        in>>junk>>denom;
    }
    else
    {
        char space = in.get();
        if(in.peek() >='0' && in.peek() <= '9')
        {
            in >>num>>junk>>denom;
        }
        else
            in.unget();
    }
    x.whole = whole;
    x.num = num;
    x.denom = denom;
    x.reduce();
    return in;
}

ostream& operator<<(ostream &out, const mixedNumber &x)
{
   if(x.whole == 0)
       if(x.num == 0)
           out<<0;
       else
           out<<x.num<<"/"<<x.denom;
   else
       if(x.num == 0)
           out<<x.whole;
       else
           out<<x.whole<<" "<<x.num<<"/"<<x.denom;
   return out;
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
