/*

Self Test Exercises Kelvin Silva
Ch 4

1.  sqrt(16.0) = 4.0
    sqrt(16) = 4
    pow(2.0, 3.0) = 8.0
    pow(2, 3) = 8
    pow(1.1, 2) = 1.21

2.  sqrt(x+y)
    pow(x, y+7)
    sqrt(area+fudge);
    sqrt(time+tide)/nobody
    ((-1)*b+sqrt((pow(b, 2) - 4*a*c))) / (2*a)
    abs(x-y)

3.
    #include <cmath>
    #include <iostream>
    using namespace std;
    int main(){

        cout << sqrt(PI);
        return 0;

    }

4. ????

# include <iostream> //Works
 # include <iostream> //Works c++ ignores whitespace in some instances


5. output: Wow

6. int triple(int x, int y, int z){
        return x*y*z;
    }

7. double fun(int x , double z ){

        return (x+z) / 2;
    }

8. char func(double x){

    char retval;
    if (x > 0)
        retval = 'p';
    else
        retval = 'n'

    return retval;

    }

9. when function is called, a temporary copy of the variable is made for modification and use.
    the original variable is untouched.

10. Predefined functions are often part of c++ standard and are 99.9% tested and approved.
    use made functions are specific to the programmer and may not always work.

11. bool in_order(int x, int y, int z){
        bool retval = false;
        if(x < y && y < z){
            retval = true;
        }

        return retval;
    }

12. bool even(int x){
        bool retval = false;
        if (x % 2 == 0){

            retval = true
        }
        return retval;
}

13. bool isdigit(char x){
    if (x == 10.0)
        return true;

    }

14. bool is_root_of(int x, int y){

        bool retval = false;
        if (x == sqrt(y))
            retval = true;
        return retval;
    }

15. Describe the function prototype and its purpose

16. Hide unneeded details from the programmer so that he does not get distracted from the task at hand

17. The programmer knows what the function does but not how it works

18. check parameters passed, check parameter values during program execution, check return value, check usage of return value
    Pass all different kinds of parameters to test if all cases work

19. Yes

20. Declare variables used nearest the place that they are used.

21. No errors

22. no error but bad style

23.  double read_filter(){
        double val = 0;
        cin >> val;
        if (val > 0)
            return val;
        else
            return 0;

    }

24. int score(double points);

25. double the_answer (double data1, double data2)

26. second definition. since its closer. the first value gets typecasted to double

27. first definition. first vaue typecasted to double

28, cannot be done

29. because the using directive ontop of main is for the whole file i.e global scope.

Programming project 1

//Kelvin Silva
    #include <iostream>

    const double LITGAL = .264179;
    double mpg(double, double);

    using namespace std;

    int main(){

       int mi, lit;

       while (mi > 0){
       cout << "\nEnter Miles traveled, type -1 to quit";
       cin >> mi;
       cout << "\nEnter Liters used";
       cin >> lit;

       cout << "\nYour mpg was " << mpg(mi, lit);
       }

        return 0;

    }

    double mpg(double mi, double lit){

        return (LITGAL*(lit/mi))*mi;     //Find lit per mi, convert lit/mi to gal/mi and multiply by total mi..
    }

//Project 3 Ch4 Kelvin Silva
#include <iostream>
 
using namespace std;
 
double stockprice(int sharenum, int whole, int num, int den);
 
int main(){
 
    bool running = true;
    char cont = 0;
 
    int owned;
    int den, num, whole;
 
    do{
 
        cout << "Enter number of shares owned: ";
        cin >> owned;
        cout << "\nEnter whole number: ";
        cin >> whole;
        cout << "\nEnter numerator: ";
        cin >> num;
        cout << "\nEnter denominator: ";
        cin >> den;
 
        cout << "Total value of holdings is: " << stockprice(owned, whole, num, den) << endl;
 
        cout << "Continue? (y/n)\n: ";
        cin >> cont;
        if (cont == 'n' || cont == 'N')
            running = false;
 
    }while (running);
 
    return 0;
}
 
double stockprice(int sharenum, int whole, int num, int den){
 
    double frac = static_cast<double>(num)/static_cast<double>(den); //Obtain decimal portion
    frac += static_cast<double>(whole); //Add whole portion to decimal portion.
 
    return frac*sharenum;
}
 
 
//Project 4 Kelvin Silva
#include <iostream>
 
using namespace std;
 
double inflat(double yesterday, double today);
 
int main(){
 
    bool running = true;
    char cont = 0;
 
    double today, yesterday;
 
    do{
 
        cout << "Enter price of item one year ago ";
        cin >> yesterday;
        cout << "\nEnter price of item today ";
        cin >> today;
 
        cout << "Inflation: " << inflat(yesterday, today);
 
        cout << "Continue? (y/n)\n: ";
        cin >> cont;
        if (cont == 'n' || cont == 'N')
            running = false;
 
    }while (running);
 
    return 0;
}
 
double inflat(double yesterday, double today){
 
 
    return (today - yesterday)/yesterday;
 
}
 ***************************************************
//Project 11 Kelvin Silva
//If x is negative then return opposite of X
//OPTIONAL: take square root of x^2 for abs value
int abs(int x){
 
    if(x <= 0){
        return x*-1;
    }else return x;
}
 
float abs(float x){
    if (x <= 0){
        return x*(-1.0);
    }else return x;
 
}
 
double abs(double x){
    if (x <= 0){
        return x*(-1.0);
    }else return x;
}
 
long abs(long x){
    if(x <= 0){
        return x*-1;
    }else return x;
}
//Project 12 Kelvin Silva
//Take max of 2 numbers then evaluate that max with the third
//Return the maximum value;
double max(double a, double b){
 
    double retval = b;
    if (a > b)
        retval = a;
    return retval;
}
 
double max(double a1, double b1, double c1){
    double retval =  max(a1, max(b1, c1));
    return retval;
}

    */

