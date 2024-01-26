#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"
#include <sstream>

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    
    // TODO(student): implement the UI
    
    try {
        string equation;
        string lhs;
        string rhs;
        string operation;

        do {
            cout << ">>";
            getline(cin, equation);
            std::istringstream parts(equation);

            parts >> lhs;
            parts >> operation;
            parts >> rhs;

            if (lhs == "q" || lhs == "quit") {
                cout << endl << "farvel!" << endl << endl;
                return 0;
            }

            if (operation == "+") {
                cout << endl << "ans =" << endl << endl << "    " << add(lhs, rhs) << endl << endl;
            }
            if (operation == "*") {
                cout << endl << "ans =" << endl << endl << "    " << multiply(lhs, rhs) << endl << endl;
            }
        } while (lhs != "q" || lhs != "quit");

    }
    catch (const std::invalid_argument& err) {
        cout << err.what() << endl;
    }

    return 0;
}
