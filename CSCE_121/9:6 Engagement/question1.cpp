#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the array amount: ";
    cin >> n;
    int array[n];

    for (int i=0; i < n; i++){
        cout << "Enter array digit: ";
        cin >> array[i];
        cout << array[i] << endl;
    }

    return 0;
}
