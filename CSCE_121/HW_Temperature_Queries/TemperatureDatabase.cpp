# include "TemperatureDatabase.h"
# include <fstream>
# include <sstream>
# include <iostream>

using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	std::ifstream inputFS;
	inputFS.clear();
	inputFS.open(filename);

	if (!inputFS.is_open()) {
    	cout << "Failed to open " << filename;
		return;
    }

	string line;
	string holderID;
	int holderYear;
	int holderMonth;
	double holderTemp;

	while (getline(inputFS, line)) {
		std::stringstream ss(line);

		ss >> holderID >> holderYear >> holderMonth >> holderTemp;
		if (ss.fail()) {
			cout << "Error: Invalid other input" << endl;
			continue;
 		}

		if (holderYear > 2023 || holderYear < 1800) {
			cout << "Error: Invalid year " << holderYear << endl;
			continue;
		}

		if (holderMonth < 1 || holderMonth > 12) {
			cout << "Error: Invalid month " << holderMonth << endl;
			continue;
		}

		if (holderTemp > 50 || holderTemp < -50) {
			cout << "Error: Invalid temperature " << holderTemp << endl;
			continue;
		}

		records.insert(holderID, holderYear, holderMonth, holderTemp);
	}
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// TODO: implement this function
}
