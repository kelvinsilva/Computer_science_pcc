//Kelvin Silva
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> my_stk;
    string line = "";
    string linecmp = "";

    cout << "Enter line for palindrom cmp: ";
    getline(cin, line);

    for (int i = 0; i < line.size(); i++){
        my_stk.push(line[i]);
    }

    for (int i = 0; i < line.size(); i++){
        linecmp.push_back(my_stk.top());
        my_stk.pop();
    }

    if (line == linecmp){
        cout << linecmp << "\nIs a palindrome";

    }else{
        cout << linecmp << "\nIs Not a palindrome";
    }

    return 0;
}
