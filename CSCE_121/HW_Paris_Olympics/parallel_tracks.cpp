#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO
  for (unsigned int i = 0; i < SIZE; ++i) {
	ary[i] = 0.0;
  }
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO
  for (unsigned int i = 0; i < SIZE; ++i) {
	ary[i] = 0;
  }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
	//TODO
	for (unsigned int i = 0; i < SIZE; ++i) {
		strcpy(ary[i], "N/A");
	}
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
	// TODO

	int start = 0;
	int end = strlen(str) - 1;
	while (isspace(str[start])) {
		start++;
	}

	if (start > end) {
		str[0] = '\0';
		return;
	}

	while (isspace(str[end])) {
		end--;
	}

	for (int i = start; i <= end; i++) {
		str[i - start] = str[i];
	}

	str[end - start + 1] = '\0';
}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) 
{
  //TODO
  double time;
  char country[STRING_SIZE];
  unsigned int number;
  char lastname[STRING_SIZE];
  unsigned int i;
  
  for (i = 0; i < SIZE; i++) {
	cin >> time;
	if (time <= 0) {
		return false;
	}
	timeArray[i] = time;

	cin >> country;
	if (strlen(country) != 3) {
		return false;
	}
	unsigned int j = 0;
	while (country[j] != '\0') {
		if (!isupper(country[j]) || !isalpha(country[j])) {
			return false;
		}
		j++;
	}
	strcpy(countryArray[i], country);

	cin >> number;
	if (number > 100) {
		return false;
	}
	numberArray[i] = number;

	cin >> lastname;
	trim(lastname);
	if (strlen(lastname) <= 1) {
		return false;
	}
	unsigned int b = 0;
	while (lastname[b] != '\0') {
		if (!isalpha(lastname[b])) {
			return false;
		}
		b++;
	}
	strcpy(lastnameArray[i], lastname);
  }

  return true; // set so it will compile
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO
	int rank = 1;
	for (unsigned int k = 0; k < SIZE; ++k) {
		rankArray[k] = 0;
	}
	for (unsigned int j = 0; j < SIZE; ++j){

		for (unsigned int i = 0; i < SIZE; ++i) {
			if (timeArray[i] < timeArray[j]) {
				rank++;
			}
		}
		rankArray[j] = rank;
		rank = 1;
	}
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}
