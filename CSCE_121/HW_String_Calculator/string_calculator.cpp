#include <iostream>
#include <string>
#include "./string_calculator.h"
#include <stdexcept>

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement

    if (!isdigit(digit)) {
        throw std::invalid_argument("There is a non-digit character");
    }

    return digit - '0';
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement

    if (decimal >= 10) {
        throw std::invalid_argument("Input is invalid");
    }

    return static_cast<char>(decimal + '0');
}

string trim_leading_zeros(string num) {
    // TODO(student): implement

    string trimmed;
    int length = num.size();
    int count = 0;

    for (int position = 0; position < length; position++) {
        if (num.at(position) == '0') {
            count++;
        }
        else {
            break;
        }
    }

    if (count == length) {
        return "0";
    }

    trimmed = num.substr(count, length - count);

    if (trimmed == "") {
        return "0";
    }


    return trimmed;
}

string add(string lhs, string rhs) {
    // TODO(student): implement

    string zero;
    zero = "0";

    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);
    
    while (lhs.size() > rhs.size()) {
        rhs = zero + rhs;
    }

    while (rhs.size() > lhs.size()) {
        lhs = zero + lhs;
    }

    int carry = 0;
    int value;
    int lhsdig;
    int rhsdig;
    char lhschar;
    char rhschar;
    string finalsum;
    char addeddig;
    char lastcarry;
    lastcarry = '1';

    for (int i = lhs.size() - 1; i >= 0; i-- ) {
        lhschar = lhs.at(i);
        rhschar = rhs.at(i);

        lhsdig = digit_to_decimal(lhschar);
        rhsdig = digit_to_decimal(rhschar);

        value = lhsdig + rhsdig + carry;
        carry = value / 10;
        value = value % 10;

        addeddig = decimal_to_digit(value);
        finalsum = addeddig + finalsum;
    }

    if (carry > 0) {
        finalsum = lastcarry + finalsum;
    }

    return finalsum;
}

/* make a for loop from right to left
add digit and divide for tens and ones
add 1 or 0 to the next addition step
put ones digit in the final value*/


string multiply(string lhs, string rhs) {
    // TODO(student): implement

    int carry = 0;
    int value;
    int ldig;
    int sdig;
    char lchar;
    char carryadd;
    char schar;
    char addeddig;
    string finalproduct = "0";
    string sum;
    string addingsum;
    string larger;
    string smaller;


    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    if (lhs.size() > rhs.size() || rhs.size() == lhs.size()) {
        larger = lhs;
        smaller = rhs;
    }
    else if (rhs.size() > lhs.size()) {
        larger = rhs;
        smaller = lhs;
    }
    
    for (int i = smaller.size() - 1; i >= 0; i-- ) {
        sum = "0";
        carry = 0;

        for (int k = larger.size() - 1; k >= 0; k--) {
            lchar = larger.at(k);
            schar = smaller.at(i);

            ldig = digit_to_decimal(lchar);
            sdig = digit_to_decimal(schar);

            value = ldig * sdig + carry;
            carry = value / 10;
            value = value % 10;
                
            addeddig = decimal_to_digit(value);
            sum = addeddig + sum;
        }

        for (int j = smaller.size() - 1; j > i; j--) {
            sum = sum + "0";
        }

        if (carry > 0) {
            carryadd = decimal_to_digit(carry);
            sum = carryadd + sum;
        }

        //cout << sum << endl;

        finalproduct = add(sum, finalproduct);

        //cout << finalproduct << endl;

    }

    finalproduct = finalproduct.substr(0, finalproduct.size() - 1);
    return finalproduct;
}

/* make a loop from right to left
multiply digit and divide for carry and ones
then repeat for the next digits
add all them up*/
