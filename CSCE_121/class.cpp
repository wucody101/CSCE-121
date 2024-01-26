#include <string>
#include <iostream>
#include <sstream>

int main(){
   std::stringstream output;
   std::string outputString;
	output << "hd";
   output >> outputString;
   std::cout << outputString;
	output << "k";
   output >> outputString;
   std::cout << outputString;
}
