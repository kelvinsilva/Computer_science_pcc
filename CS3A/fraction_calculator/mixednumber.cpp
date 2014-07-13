#include "mixednumber.h"

mixedNumber::mixedNumber()
{
    whole = 0;
    num = 0;
    denom = 1;
}

void mixedNumber::reduce()
{
    int div, newNum;
    newNum = abs(denom * whole + num);
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
