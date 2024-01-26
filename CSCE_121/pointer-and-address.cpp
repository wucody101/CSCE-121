#include <iostream>
using namespace std;

int main(){

    int number1 = 10;
    int* n1 = &number1;

    int number2;
    number2 = *n1;

    int* n2;
    n2 = n1;

    cout << "n1 is " << n1 << endl;
    cout << "n2 is " << n2 << endl;
    cout << "number1 is " << number1 << "  " << *n1 << endl;
    cout << "number2 is " << number2 << "  " << *n2 << endl;  

}
