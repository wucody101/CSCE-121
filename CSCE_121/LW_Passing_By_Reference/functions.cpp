#include <iostream>
#include "functions.h"
using namespace std;

void function_one(int i, int& j) {
	// TODO: implement function_one so that it takes two integer arguments i and j, adds 2 to i,
    // adds 1 to j, (after execution of the function, only j is changed)

    i += 2;
    j += 1;
}

void function_two(example& foo) {
    // TODO: implement function_two so that it takes an argument of type example, and increments
    // its integer by 1 (should persist after the function)

    foo.value += 1;
}

void function_three(int* k, int& l) {
    // TODO: implement function_three so that it increments both variables by one (both changes must
    // persist after the function call)

    *k += 1;
    l += 1;
}

void function_four(/* TODO: fill with the appropriate arguments */) {
    // TODO: implement function_four so that it increments every value by two and then sets lowest /
    // highest to the min / max of the array (all changes must persist after the function call)
}
