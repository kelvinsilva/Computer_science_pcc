#include <iostream>
#include "parser.h"
#include "util_calc_funcs.h"

using namespace std;

int main()
{
    string str = "";
    Parser main_parser;

    cout << "Enter algebraic expression: ";
    getline(cin, str);

    str = clean(str);
    while ( look_for_error(str) ){
        str = "";
        str = clean(str);
        cout << "\nSyntax Error, reenter expression:\n";
        getline(cin, str);

    }

    main_parser.set_string(str);
    main_parser.parse_algebraic();
    cout << "Rpn expression: " << main_parser.get_rpn_str();
    mixedNumber ans;
    ans = output_queue_rpn_calculation(main_parser.get_output_queue());
    cout << "\nResult: " << ans;


    return 0;
}
