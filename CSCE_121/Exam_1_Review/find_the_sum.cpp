#include <iostream>
using namespace std;

int main() {
    int n;
    int target;

    cout << "Enter a value for n: ";
    cin >> n;

    int numarray[n];
    cout << "Enter a list that is " << n << " numbers long: ";
    for (int i = 0; i < n; i++) {
        cin >> numarray[i];
    }

    cout << "Enter target number: ";
    cin >> target;

    int count = 0;
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            if (numarray[k] + numarray[j] == target) {
                cout << numarray[k] << " " << numarray[j] << endl;
                count++;
            }
        }
    }

    if (count == 0) {
        cout << "none";
    }
    
    return 0;
}
