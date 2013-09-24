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

/*Project 12 Ch 5
  Kelvin Silva
  

#include <iostream>

using namespace std;

void Convert(int Big, double small, int choice, double &ResultBig, double &ResultSmall);


int main()
{
    int choice = 0;
    double big = 0, small = 0, resultbig = 0, resultsmall = 0;
    while (choice != 5){
        cout << "\nMenu:\n1. Metric length to English length"
             <<       "\n2. English Length to Metric length"
             <<       "\n3. Metric weight to English weight"
             <<       "\n4. English weight to Metric Weight"
             <<       "\n5. Quit\nChoice: ";

        cin >> choice;

        switch(choice){

            case 1:
                cout << "\n\nEnter Meters: ";
                cin >> big;
                cout << "\nEnter Centimeters: ";
                cin >> small;
                Convert(big, small, choice, resultbig, resultsmall);
                cout << "Feet: " << resultbig << "Inches: " << resultsmall;

            break;
            case 2:
                cout << "\n\nEnter Feet: ";
                cin >> big;
                cout << "\nEnter Inches: ";
                cin >> small;
                Convert(big, small, choice, resultbig, resultsmall);
                cout << "Meters: " << resultbig << "Centimeters: " << resultsmall;
            break;
            case 3:
                cout << "\n\nEnter Kilogram: ";
                cin >> big;
                cout << "\nEnter Grams: ";
                cin >> small;
                Convert(big, small, choice, resultbig, resultsmall);
                cout << "Pounds: " << resultbig << "Ounces: " << resultsmall;
            break;
            case 4:
                cout << "\n\nEnter Pounds: ";
                cin >> big;
                cout << "\nEnter Ounces: ";
                cin >> small;
                Convert(big, small, choice, resultbig, resultsmall);
                cout << "Kilograms: " << resultbig << "Grams: " << resultsmall;
            break;
            case 5:

            break;
            default:
                cout << "\nEnter 1-5.\n";
            break;

        }
    }
    return 0;
}

void Convert(int Big, double small, int choice, double &ResultBig, double &ResultSmall){

    switch(choice){

        case 1:

            ResultBig =  static_cast<double>(Big) * 3.28;
            ResultSmall = static_cast<double>(small)*0.393701;
        break;
        case 2:

            ResultBig =  static_cast<double>(Big) * 0.3048;
            ResultSmall = static_cast<double>(small)*2.54;
        break;
        case 3:

             ResultBig =  static_cast<double>(Big) * 2.20462;
             ResultSmall = static_cast<double>(small)*0.035274;
        break;
        case 4:

            ResultBig =  static_cast<double>(Big) * 0.453592;
            ResultSmall = static_cast<double>(small)*28.3495;
        break;
    }

}
*/
