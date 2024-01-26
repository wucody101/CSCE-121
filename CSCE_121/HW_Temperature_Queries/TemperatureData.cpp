# include "TemperatureData.h"
# include <sstream>
using std::string;

TemperatureData::TemperatureData() : id(""), year(0), month(0), temperature(0.0) /* TODO */ {
	// TODO: implement this function
	id = "";
	year = 0;
	month = 0;
	temperature = 0.0;
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) : id(id), year(year), month(month), temperature(temperature) /* TODO */ {
	// TODO: implement this function
}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
	// TODO: implement this function
	//if id is less than b.id what do you return
	//else if id is greater than b.id what do you return

	//if year is less than b.year what to return
	//else if year is greater than
	if (this->id.length() < b.id.length()) {
		return true;
	}
	else if (this->id.length() < b.id.length()) {
		return false;
	}
	else {
		for (int i = 0; i < b.id.length(); i++) {
			if (static_cast<int>(this->id[i]) < static_cast<int>(b.id[i])) {
				return true;
			}
			else if (static_cast<int>(this->id[i]) > static_cast<int>(b.id[i])) {
				return false;
			}
		}
	}
	if (this->id == b.id && this->year > b.year) {
		return false;
	}
	else if (this->id == b.id && this->year < b.year) {
		return true;
	}
	if (this->year == b.year && this->month >= b.month) {
		return false;
	}
	return true;
}

