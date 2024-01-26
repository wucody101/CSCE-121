#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (a >= 10 && a <= b && b < 10000) {
		return true;
	}
	else {
		return false;
	}
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	char stat = 'N';
	int dig;
	int prevdig;

	dig = number % 10;
	number /= 10;
	prevdig = dig;

	while (number != 0) {
		dig = number % 10;
		number /= 10;

		if (dig > prevdig) {			// if valley, then ruins the pattern
			if (stat == 'V') {
				return 'N';
			}
			stat = 'V';
		}
		else if (dig < prevdig) {		// if mountain, then ruins the pattern
			if (stat == 'M') {
				return 'N';
			}
			stat = 'M';
		}
		else if (dig == prevdig) {
			return 'N';
		}

		prevdig = dig;
	}
	

	return stat;
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int i;
	int Mcount = 0;
	int Vcount = 0;
	
	for (i = a; i <= b; ++i) {
		if (classify_mv_range_type(i) == 'M') {
			++Mcount;
		}
		else if (classify_mv_range_type(i) == 'V') {
			++Vcount;
		}
	}

	cout << "There are " << Mcount << " mountain ranges and " << Vcount << " valley ranges between " << a << " and "; 
	cout << b << "." << endl;

}
