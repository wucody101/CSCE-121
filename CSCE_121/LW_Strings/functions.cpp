# include "functions.h"
// add any includes
#include <string>

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {
    // TODO
    string obfuscated;
    cout << "Please enter obfuscated sentence: ";
    cin >> obfuscated;

    string details;
    cout << "Please enter deobfuscation details: ";
    cin >> details;

    string deobfuscated = obfuscated;
    string space = " ";
    int spaceposition = 0;

    for (size_t i = 0; i < details.size(); i++) {
        spaceposition += details.at(i) - '0';
        deobfuscated = deobfuscated.insert(spaceposition + i, space);
    }

    cout << "Deobfuscated sentence: " << deobfuscated << endl; 
}

void wordFilter() {
    // TODO
    string sentence;
    cout << "Please enter the sentence: ";
    getline(cin, sentence);

    string filter;
    cout << "Please enter the filter word: ";
    cin >> filter;

    string replacement;
    for (size_t k = 0; k < filter.size(); k++){
        replacement.insert(k, "#"); 
    }

    size_t finding = sentence.find(filter);
    int i = 0;
    while (finding != string::npos) {
        sentence.replace(finding, filter.size(), replacement);
        finding = sentence.find(filter);
        i++;
    }

    cout << "Filtered sentence: " << sentence << endl;
}

void passwordConverter() {
    // TODO
}

void wordCalculator() {
    // TODO
}

void palindromeCounter() {
    // TODO
}
