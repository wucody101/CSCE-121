#include <iostream>
using namespace std;

bool isNumericPalindrome(int n) {
    
    if (n < 10 && n > -10) {
        return true;
    }
    
    n = abs(n);
    int num = n;
    int count = 0;
    while (num != 0) {
        num = num / 10;
        //cout << num << endl;
        count++;
    }
    //cout << count << endl;

    int numarray[count];
    for (int i = 0; i < count; i++) {
        numarray[i] = n % 10;
        n = n / 10;
        //cout << numarray[i] << endl;
    }

    for (int k = 0; k < count; k++) {
        if (numarray[k] != numarray[count - 1 - k]) {
            return false;
        }
    }

    return true;
}


int main() {
    int number;
    cout << "Enter a digit: ";
    cin >> number;
    
    if (isNumericPalindrome(number)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
