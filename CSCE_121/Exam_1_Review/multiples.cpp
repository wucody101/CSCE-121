#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int k;
    int l;
    int count = 0;
    int num = 1;

    cout << "Enter n, k, and l: ";
    cin >> n;
    cin >> k;
    cin >> l;

    while (count != n) {
        if (num % k == 0 || num % l == 0) {
            cout << num << " ";
            count++;
        }
        num++;
    }

    return 0;
}
