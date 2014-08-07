
#include "mixednumber.h"

mixedNumber::mixedNumber()
{

}

mixedNumber& mixedNumber::operator= ( double dec){

    if (dec > 0){
        int whole = trunc(dec);

        double decDecimal = abs(trunc(dec) - dec);
        int number_to_raise = get_num_of_places(decDecimal);

        int numerator = decDecimal * pow(10, number_to_raise);
        int denominator =  pow(10, number_to_raise);

        numerator = (denominator * whole) + numerator;

        this->setFraction(numerator, denominator);
        return *this;

    }else {

        int whole = trunc(dec);

        double decDecimal = abs(trunc(dec) - dec);

        int number_to_raise = get_num_of_places(decDecimal);
        int numerator = decDecimal * pow(10, number_to_raise) * -1;
        int denominator =  pow(10, number_to_raise);

        numerator = (denominator * whole) + numerator;

        this->setFraction(numerator, denominator);

        return *this;
    }

}

mixedNumber::mixedNumber(int w, int n, int d)
{
    setFraction(d*w+n,d);
}

mixedNumber::mixedNumber(const fraction &other)
{
    copy(other);
}

mixedNumber::~mixedNumber()
{

}

mixedNumber::mixedNumber(const mixedNumber &other)
{
    copy(other);
}

mixedNumber& mixedNumber::operator=(const mixedNumber &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

mixedNumber& mixedNumber::operator=(const fraction &other)
{
    copy(other);
}


void mixedNumber::copy(const mixedNumber &other)
{
    setFraction(other.getNum(), other.getDenom());
}


void mixedNumber::copy(const fraction &other)
{
    setFraction(other.getNum(), other.getDenom());
}

void mixedNumber::setValue(int w, int n, int d)
{
    setFraction(d*w+n, d);
}

ostream& operator<<(ostream& out, const mixedNumber &x)
{
    int whole = x.getNum()/x.getDenom(),
            num = abs(x.getNum()) % x.getDenom();
    if(whole != 0)
        out<<whole<<" ";

    if (num != 0)
        out<<num<<"/"<<x.getDenom();

    if(num == 0 && whole == 0)
        out << "0";

    return out;
}


istream& operator>>(istream& in,  mixedNumber &x)
{
    int whole = 0, num = 0, denom = 1;
    char junk;
    in>>whole;

    x.setFraction(whole, 1);

    if ( in.peek() != '\0' || in.eof()){ //if we have not reached the end of line or end of input. So i can catch whole number easily
        if(in.peek() == '/'){ //For example if i just type in "4", then i have end of input and/or end of line '\0'

                num = whole;    //Then i dont need to go through the rest of the if statements
                whole = 0;
                in>>junk;

                if ( isdigit(in.peek()) ){

                    in>>denom;
                    x.setFraction(denom*whole+num, denom);
                }else{
                    in.putback(junk);
                }



		 return in;

        }
        else if(in.peek() == ' '){

            char space = in.get();
            if((in.peek() >='0' && in.peek() <= '9') || (in.peek() == '-' || in.peek() == '+'))
                {
                    in >>num>>junk>>denom;
                }
                else{
                    in.unget();

                }

            int wwhole = whole;
            int nnum = whole <= 0 ? abs(num)*-1 : abs(num);
            int ddenom = abs(denom);

            x.setFraction(ddenom*wwhole+nnum, ddenom);
            return in;

        }
    }

    return in;
}
