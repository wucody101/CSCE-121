#include <iostream>
using namespace std;

bool isVowel(char word) {
    switch(word) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int moreImportant(char word1[], char word2[]) {
    
    int length1 = 0;
    int length2 = 0;
    int i = 0;
    int j = 0;
    while (word1[i] != '\0') {
        length1++;
        word1[i] = tolower(word1[i]);
        i++;
    }
    while (word2[j] != '\0') {
        length2++;
        word2[j] = tolower(word2[j]);
        j++;
    }

    int shorter;
    int longer;
    int longerword;
    if (length1 > length2) {
        longer = length1;
        shorter = length2;
        longerword = 1;
    }
    else {
        longer = length2;
        shorter = length1;
        longerword = 2;
    }

    int score1 = 0;
    int score2 = 0;
    for (int k = 0; k < shorter; k++) {
        if (isVowel(word1[k]) && !isVowel(word2[k])) {
            score1 += 3;
        }
        else if (!isVowel(word1[k]) && isVowel(word2[k])) {
            score2 += 3;
        }
        else if ((isVowel(word1[k]) && isVowel(word2[k])) || (!isVowel(word1[k]) && !isVowel(word2[k]))) {
            if (word1[k] > word2[k]) {
                score1++;
            }
            else if (word1[k] < word2[k]) {
                score2++;
            }
        }
        else if (word1[k] == word2[k]) {
            continue;
        }
    }

    for (int m = shorter; m < longer; m++) {
        if (longerword == 1) {
            if (isVowel(word1[m])) {
                score1 += 2;
            }
            else if (!isVowel(word1[m])) {
                score1 += 1;
            }
        }
         if (longerword == 2) {
            if (isVowel(word2[m])) {
                score2 += 2;
            }
            else if (!isVowel(word2[m])) {
                score2 += 1;
            }
        }
    }

    int winner;
    if (score1 > score2) {
        winner = 1; 
    }
    else {
        winner = 2;
    }

    return winner;
}

int main() {
    const int size = 50;
    char word1[size];
    char word2[size];
    cout << "Enter word 1: ";
    cin >> word1;
    cout << "Enter word 2: ";
    cin >> word2;
    cout << moreImportant(word1, word2);

    return 0;
}
