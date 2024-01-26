#include <iostream>
using namespace std;

bool isHappy(int n) {
    
    int number = 0;
    while (number != 4 && number != 1) {
        number = 0;
        while (n != 0) {
            number += (n % 10) * (n % 10);
            n = n / 10;
        }
        n = number;
    }

    if (number == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int test;
    cout << "Enter a number: ";
    cin >> test;
    if (isHappy(test)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    
    return 0;
}
