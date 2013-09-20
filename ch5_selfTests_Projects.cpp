/* kelvin Silva*/

/*

Ch 5 Self Test Exercises...


1.  Hello
    Goodbye
    One more time:
    Hello
    End of Program.

2. No, void doesnt need return.

3. no effect, return is used for early termination?

4. #include <iostream>
    void productout(int n, int n1, int n2);
    int main(){

        using namespace std;
        int n1, n2, n3;
        cout << "Enter 3 integers: ";
        cin >> n1 >> n2 >> n3;
        productout(n1, n2, n3);
        return 0;

    }

    void productout(int n, int n1, int n2){
        using namespace std;
        cout << "Product of three numbers" << n1 << n2<<n3;

    }

5. It is system dependent

6. it is a statement. function that returns a value is an expression

7.  10 20 30
    1 2 3
    1 20 3

8. Enter two integers- 5, 19
    int reverse the numbers are: 5, 5

9. part 1 value in function call = 111
par 2 ref in function call = 222
n1 after function call = 1
n2 after function call = 2


10. void zero_both( int &n1, int &n2){
        n1 = 0;
        n2 = 0;
    }

11. void add_tax(double rate, double &const){

        cpst = cost + (taxrate/100.0)*cost;
}

12. Yes, if you return a value you can call by reference and call by values

13. No

14. Yes

15. void order(int &n1, int &n2);

16. double sqrt(double n);

17. test one function at a time incrementally. then you will know which function the bug happened at

18. it is a program written for the purpose of testing a function

19.

#include <iostream>

void introduction();

int main(){

    using namespace std;

    introduction();
    cout << "End of test.\n";

}

void introduction(){

    using namespace std;
    cout << "this program outputs retail price of item at supermarket";

}

20.

#include <iostream>

void add_tax(double tax_rate, double &const);

int main(){

    using namespace std;
    double cost, tax_rate;
    char ans;

    cout << "enter cost and tax rate";
    cin >> cost >> tax_rate;
    add_tax(tax_rate, cost);

    cout << "After call\n";
    cout << tax_rate;

    return 0;

}

void add_tax(double tax_rate, double &cost){

    cost = cost + ( tax_rate/100.0 ) * cost;

}

21. a stub is a placeholder for a function

22.

double stub(double stub){

    return stub;

}

23. assert(z != 0);

24. debugger is a tool that lets you control flow of a program

25. add cout << statements to debug.
