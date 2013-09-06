
//Kelvin Silva Cs002 Barkeshli
    /*

    Self test exercise 2.1, 2.2, 2.3, 2.4, 2.5
                        pp 49, 59, 72, 82, 91, 96

    1.
        int feet = 0;
        int inches(0);

    2.
        int count = 09;
        double distance = 1.5;

    3.
        sum += n1+n2;

    4.
        length += 8.3;

    5.
        product *= n;

    6.
        #include <iostream>

        int main(){
            int i;
            std::cout<<i;
            return 0;
        }

        --> The output was 3294832 because the computer
            "grabs memory" from the stack and that particular location
            had a left-over value from another operation or program.

    7.
        a. int car_speed;
        b. float employee_salary;
        c. float highest_score;

    8.
        cout << "The answer to the question of\nLife, the universe....";

    9.
        cout << "Type in a whole number: ";
        cin >> the_number;

    10.
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);

    11.
        #include <iostream>
        int main(){
            std::cout << "Hello world";
        }

    12.
        #include <iostream>
        using namespace std;
        int main(){
           int x, y;
           cout << "Enter the first number to sum: ";
           cin >> x;
           cout << "\nEnter the second number to sum: ";
           cin >> y;
           cout << "\nx = " << x << "\ny = " << y << "\nThe sum  is " <<  << (x+y);

           return 0;

        }

    13.
        cout << "\n\t";

    14.
        #include <iostream>
        using namespace std;
        int main(){
           cout << "1.\t" << "1.000\n";
           cout << "2.\t" << "1.414\n";
           cout << "3.\t" << "1.732\n";
           cout << "4.\t" << "2.000\n";
           cout << "5.\t" << "2.236\n";

           return 0;

        }

    15.
        a. 3*X
        B. 3*X + Y
        c. (x+y)/7
        d. (3*x + y)/(z+2)

    16.
        output: bcbc

    17.
        output: (1/3)*3 is equal to 0

    18.
        #include <iostream>
        using namespace std;

        int main(){
            int x, y;
            cin >> x >> y;
            cout << "x / y = " << x/y << " remainder : " << x%y;

            return 0;
        }

    19.
        a. f = 52
        b. 9/5 = 1.8 but gets truncated to 1. He wanted to obtain 1.8 from (9/5) but recieved 1 instead
        c. f = (9.0/5.0) * c + 32;

    20.
        output: 030406

    21.
        if (score > 100)
            cout << "high";
        else
            cout << "low";

    22.
        if (savings > expenses){

            cout << "Solvent ";
            savings -= expenses;
            expenses = 0;
        } else {

            cout << "bankrupt";
        }

    23.
        if (exam > 60 && programs_done > 10)
            cout << "Passed";
        else
            cout << "failed";

    24.
        if (temperature >= 100 || pressure >= 200)
            cout << "warning";
        else
            cout << "Ok";

    25.
        (x < -1) || (x > 2)

    26.
        (x > 1) && (x<3)

    27.
        a. 0 is false;
        b. 1 is true;
        c. -1 is true;

    28.
        10
        7
        4
        1

    29.
        no output

    30.
        10
        7
        4
        1

    31.
        -42

    32.
        while checks condition upon entry
        do while checks condition upon exit

    33.
        infinite loop

    34.
        #include <iostream>
        using namespace std;
        int main(){

            int x = 1;
            while( x <= 20 ){
                cout << x << "\n";
                x++;
            }

        return 0;
        }

    35.
        if (x < 0){

            x = 7;
            cout << "x is now positive.";
        } else {

            x = -7;
            cout << "X is now negative";
        }

    36.
        output: Self-Test Exercise

    37.
        #include <iostream>
        using namespace std;
        int main(){

            double gallons;
            cout << "Enter gallons of water: ";
            cin >> gallons;

            cout << "\n\nLiters = " << gallons*3.78533;

            return 0;
        }

    Ch 2. Programming projects

    1. Project 1

    //divide ounces by 35273.92 to figure out metric tons of box
    //metric ton constant divided by ounces yields number of those ounces
    //that are needed to meet the constant (number of boxes required to make 1 metric ton).

    #include <iostream>
    using namespace std;

    int main(){

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(10);

        double ounces = 1;
        while ((int)ounces != 0){



            cout << "Enter ounces of breakfast ceral box, type 0 to quit: ";
            cin >> ounces;
            cout << "Cereal box-Metric tons: " << ounces / 35273.92;
            cout << "\nNumber of cereal boxes to wield 1 metric ton " << (35723.92 / ounces);



        }

        return 0;
    }
    ***************************

    3. Project 3

    //Given annual salary, compute pay raise of 7.6%
    //Multiple by .076 and add it back to get total, only do this for 6 months.
    // The other 6 months have no pay raise

    #include <iostream>
    using namespace std;

    int main(){

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(10);

        double salary = 0;
        const double increase = .076;

        while ((int)salary != -1){

            cout << "\n\nEnter annual salary, type -1 to quit: ";
            cin >> salary;



            if (salary != -1){ //If this if wasnt here, then if salary == -1 the below would get
                              //executed and then the loop would quit. I wanted the loop to quit right away.
                salary = salary / 12.0;  // Figure out monthly salary
                cout << "7.6% pay increase for 6 months\nAnnual Salary: " << 6*salary + (6 * (salary + salary*increase))
                     << "\nMonthly Salary for 6 months: " << salary + salary*increase;

            }

        }

        return 0;
    }

    *********************************
    6. Project 6

    //Kelvin silva
    //Basic arithmetic
    //Retrieve certain numbers and if numbers n are less than regulatiions r then we have room to put more people.
    //Subtract n from r and we have number of people needed to meet or exceed the regulation.
    //If n > r we have exceeded regulations so n - r will be the number of people needed to be removed to be <= r;

    #include <iostream>
    using namespace std;

    int main(){

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);

        double amt_people = 0;
        double room_capacity = 0;

        while ((int)amt_people != -1){

            cout << "\n\nEnter number of people entering room, type -1 to quit: ";
            cin >> amt_people;

            if (amt_people != -1)   //If this if wasnt here, then if salary == -1 the below would get
                                    //executed and then the loop would quit. I wanted the loop to quit right away.
                cout << "\n\nEnter room capacity: ";
                cin >> room_capacity;

                if (amt_people > room_capacity){

                    cout << "You exceeded the regulations: " << amt_people - room_capacity
                         << " must be removed to meet the regulations";
                }else {
                    cout << "You meet the regulation: " << (room_capacity - amt_people)
                         << " people are required to fill the room to max capacity";
                }

        }

        return 0;
    }

    10. Project 10

    //Kelvin Silva
    //Keep track of negative numbers in 1 variable and positive numbers in another
    //Simple if statement to determine if a number entered should be added to positive or negative variable
    //Then once 10 entries have been added (for loop) we cout each integer.
    #include <iostream>
    using namespace std;

    int main(){

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);

        int total_neg = 0, total_pos = 0;
        int current = 0;

        for (int i = 0; i < 10; i++){

            cout << "\nEnter a number: ";
            cin >> current;
            cout << 10- i << " entries to go...";

            if (current < 0){
                total_neg += current;
            }else total_pos += current;

        }

        cout << "\nTotal positive: " << total_pos << "\nTotal neg: " << total_neg;

        return 0;
    }

    12. Project 12

    //We add a certain threshold (guess) and we subtract it also. each of those two operations will provide an area in between
    //Keep halving and taking the average of the guesses and we approach the square root of sqr.

    #include <iostream>
    using namespace std;

    int main(){

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(10);


        double sqr, r, guess;
        cout << "Enter square root to compute: ";
        cin >> sqr;
        guess = sqr/2;

        for (int i = 0; i < 10; i++){

            r = sqr/guess;
            guess = (guess + r) /2;
        }
        cout <<"\nSquare root: " << guess;
        return 0;
    }

    */

    /*

    Self Test Exercises 3.1 pp 116

    1.
        a. true
        b. true
        c. true
        d. true
        e. false
        f. true
        g. false
        h. error
        i. true
        j. error
        k. false
        l. 1

    2. Branching statements (ifs) and Iterative statements (loops)


    3.
        C++ will evaluate from left to right
        (2 < x) & (x < 3)

    4.
        NO

    5.
        output:
            Start
            Hello from the second if.
            End
            Start again
            End Again

    6.
        output:
            large

    7.
        output:
            small

    8.
        output:
            medium

    9.
        output:
            Start
            Second Output
            End

    10.
        output:
            Start
            Third Output
            End

    11.
        output:
            100
            End

    12.
        if (n < 0)
            cout << "n < 0";
        else if (n > 100)
            cout << "n > 100";
        else
            cout << "0 < n < 100";
    13.
        output:
            3 2 1 0

    14.
        output:
            2 1 7 5

    15.
        output:
            Roast woms

    16.
        ouput:
            Onion ice cream

    17.
        ouput:
            Chocolate ice cream
            Onion ice cream

    18.
        Bon appetit

    19.
        output:
            42 22

    20.
        output:
            1
            1
            2
            2
            3
            2
            1

    21.
        output:
            2
            1
            0

    22.
        output:
            2
            1

    23.
        output:
            1
            2
            3
            4

    24.
        output:
            1
            2
            3

    25.
        output:
            2
            4
            6
            8

    26.
        output:
            Hello 10
            Hello 8
            Hello 6
            Hello 4
            Hello 2
    27.
        output:
            2.0 1.5 1.0 0.5

    28.
        a.
            double x = 0;
            for (int i = 0; i < 10; i++){
                x += (double)1/i
            }

        b.
            int temp = 0;
            for (int i = 0; i < test_num; i++){
                cin >> temp;
                test_score += temp;
            }

        c.
            int temp = 0;
            for (int i = 0; i < sick_num; i++){
                cin >> temp;
                sick_total += temp;
            }

        d.
           for (int x = 0; x < 1000; x++){
                cout << f(x) << "\n"; //f() return value is couted

    29.
        a.
            for (int i = 2; i <= 10; i++){
                if(1 < 5 && != 2)
                    cout << 'x';
            }

        b.
            for (int i = i; i <= 10; i += 3){
                cout << 'x';
            }

        c.
            for (long m = 100; ; m += 100){
                cout << 'x';

                if(m < 1000)
                    break;
            }

    30.
        1024 10
        the 10th digit in a binary string is the 1024's place

    31.
        1024

    32.
        infinite loop becaus anything mul by 0 is 0

    33.
        4 3 End Of loop

    34.
        4 3

    35.
        It breaks the flow of the pogram out of a loop or conditional statement.

    36.
        for (int i = 0 i < 10; i++){
            cout << "Hello World";
        }

    37.
        int x = 0;
        int count = 0;
        while (x != 0){
            cin >> x;
            if (x % 2 == 0){ //Count only even values
                count += x;
            }
        }

    38.
        10 * 10..1
        9 * 10..1
        8 * 10..1
        ....
        1 * 10..1

    39.
        Tracing a variable means
        observing the value of te variable as it changes throughout pogram execution

    40.
        Off by one error is when a programmer mis-anticipates  how many times a loop should run by 1 iteration.

    41.
        Do we need fence posts at each end? Dividing by 10 will not get us the last post to cover 100 meters.

*****************

Ch 3 Projects

1. Project 1

#include <iostream>

using namespace std;

int main(){

    char p1, p2;
    int winner = 0;

    while (p1 != 'q' || p2 != 'q'){
        cout << "Player 1 (p, r, s) press q to quit: ";
        cin >> p1;
        cout << "\nPlayer 2 (p, r, s) press q to quit: ";
        cin >> p2;

        if( p1 < 90 ) //If any character is upper case, then convert to lower case
            p1 += 32;
        if( p2 < 90 )
            p2 += 32;

        if ((p1 == 'p' && p2 == 'r') || (p1 == 'r' && p2 == 's') || (p1 == 's' && p1 == 'p') ){ //Cases where Player 1 wins
            winner = 1;
        }else winner = 2;   //Else, player 2 wins

        if (p1 == p2){ //If input is same then no winner
            cout << "No winnder";
        }else
        cout << "player " << winner << " wins";
    }

    return 0;

}

**************

2. Project 2

//for the first 1000 dollars the interest is 1.5 percent so we calculate 1.5% of 1000 dollars and add it to interest_due
//then we subtract 1000 dollars to get the remaining dollars which is mul by .01
#include <iostream>

using namespace std;

int main(){


    double interest_due = 0, amount_due = 0, minimum_payment = 0;
    double bal = 1;

    while (bal != 0){
        cout << "Enter amount balance, type 0 to quit: ";
        cin >> bal;
        amount_due = bal;

        if ( bal >= 1000 ){
            interest_due = (1000 * .015);

            if (bal > 1000) interest_due += (bal - 1000) * .01;
        }

        amount_due += interest_due;

        if (amount_due < 10.0){                 //minimum payment is total amount due if that is 10 dollars or less
            minimum_payment = amount_due;
        }else minimum_payment = .10 * amount_due;

        cout << "\nInterest due: " << interest_due
             << "\nTotal Amount due: " << amount_due
             << "\nMinimum Payment: " << minimum_payment;


        interest_due = 0, amount_due = 0, minimum_payment = 0;


    }

    return 0;

}

*/


