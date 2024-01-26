#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the value for n: ";
    cin >> n;

    int narray[n];
    cout << "Enter n digits: ";
    for (int i = 0; i < n; i++) {
        cin >> narray[i];
    }

    int count = 1;
    for (int k = 1; k < n; k++) {
        if (narray[k] != narray[k - 1]) {
            count++;
        }
    }

    cout << "The sequence ";
    for (int j = 0; j < n; j++) {
        cout << narray[j] << " ";
    }
    cout << "has " << count << " segments.";

    return 0;
}
