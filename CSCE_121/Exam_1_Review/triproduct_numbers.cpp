#include <iostream>
using namespace std;

int main() {
    int triproduct;
    int num = 0;

    cout << "Enter a positive number: ";
    cin >> triproduct;

    while (num * (num + 1) * (num + 2) < triproduct) {
        num++;
    }

    if (num * (num + 1) * (num + 2) == triproduct) {
        cout << "This number is a triproduct";
    }
    else {
        cout << "This number is not a triproduct";
    }

    return 0;
}
