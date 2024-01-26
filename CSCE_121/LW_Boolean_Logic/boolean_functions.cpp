#include <iostream>
#include "boolean_functions.h"

using std::cin, std::cout, std::endl, std::boolalpha;

void printNOT()
{
    // TODO: replace ?s with 0 or 1
    cout << "--- print NOT ---" << endl;

    cout << " x | NOT x" << endl;
    cout << "---+-------" << endl;
    cout << " 0 |   1" << endl;
    cout << " 1 |   0" << endl;

    cout << endl;
}

void printOR()
{
    // TODO: replace ?s with 0 or 1
    cout << "--- print OR ---" << endl;

    cout << " x | y | x OR y" << endl;
    cout << "---+---+--------" << endl;
    cout << " 0 | 0 |   0" << endl;
    cout << " 0 | 1 |   1" << endl;
    cout << " 1 | 0 |   1" << endl;
    cout << " 1 | 1 |   1" << endl;

    cout << endl;
}

void printAND()
{
    // TODO: replace ?s with 0 or 1
    cout << "--- print AND ---" << endl;

    cout << " x | y | x AND y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    0" << endl;
    cout << " 1 | 0 |    0" << endl;
    cout << " 1 | 1 |    1" << endl;

    cout << endl;
}

void printXOR()
{
    // TODO: replace ?s with 0 or 1
    cout << "--- print XOR ---" << endl;

    cout << " x | y | x XOR y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    1" << endl;
    cout << " 1 | 0 |    1" << endl;
    cout << " 1 | 1 |    0" << endl;

    cout << endl;
}

bool booleanLogic1(bool x, bool y, bool z)
{
    cout << "--- Boolean Logic 1 ---" << endl;

    bool value = false; // TODO: Fill this in

    if (x == true || y == true || z == true) {
        value = true;
    }

    cout << boolalpha << x << " OR " << y << " OR " << z << " = " << value << endl;

    cout << endl;
    return value;
}

bool booleanLogic2(bool x, bool y, bool z)
{
    cout << "--- Boolean Logic 2 ---" << endl;

    bool value = false; // TODO: Fill this in
    
    if (x && y && z) {
        value = true;
    }

    cout << boolalpha << x << " AND " << y << " AND " << z << " = " << value << endl;

    cout << endl;
    return value;
}

bool booleanLogic3(bool x, bool y, bool z)
{
    cout << "--- Boolean Logic 3 ---" << endl;

    bool value = false; // TODO: Fill this in
    
    if (x ^ y ^ z) {
        value = true;
    }
    
    cout << boolalpha << x << " XOR " << y << " XOR " << z << " = " << value << endl;

    cout << endl;
    return value;
}

// this function counts the letters in str
unsigned int countLetters(std::string str) 
{
    // TODO: fix error
    cout << "--- count Letters ---" << endl;

    unsigned int count = 0;
    for (unsigned int i=0; i<str.size(); ++i) {
        if (isalpha(str.at(i))) {
            count++;
        }
    }
    return count;
}

bool f(bool x, bool y, bool z)
{
    cout << "--- f ---" << endl;

    bool boolVal = false; // TODO: Fill this in
    if ((y == true && z == true) || (x == false && (y == true || z == true)) || (x == true && (y == false && z == false))) {
        boolVal = true;
    }

    return boolVal;
}

void setAssignments(bool &w, bool &x, bool &y, bool &z)
// You'll learn what the & means in the function signature later this semester
// You don't need to calculate the value
{
    cout << "--- set Assignments ---" << endl;

    // TODO: Assign boolean values the four variables so that
    //   the boolean formula calcualtes to true
    w = true;
    x = true;
    y = false;
    z = false;
}



