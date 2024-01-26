#include <iostream>
using namespace std;

bool hasFailingGrade(double grades[], unsigned int size) {
    bool hasFailing = false;
    for (unsigned int i = 0; i < size; ++i) {
        if (grades[i] < 60) {
            hasFailing = true;
        }
    }

    return hasFailing;
}

int main() {
    unsigned int size;
    cout << "Enter array size: ";
    cin >> size;
    
    double grades[size];
    int num;
    cout << "Enter grades: ";
    for (int i = 0; i < size; i++) {
        cin >> num;
        grades[i] = num; 
    }

     if (hasFailingGrade(grades, size)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
