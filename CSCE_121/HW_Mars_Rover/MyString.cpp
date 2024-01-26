// TODO: Implement this source file
#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>
#include "MyString.h"

MyString::MyString() : string(nullptr), sizenum(0), capacitynum(1) {
    sizenum = 0;
    capacitynum = 1;
    string = new char[capacitynum];
    string[0] = '\0';
}

MyString::MyString(const MyString& copy) : string(nullptr), sizenum(0), capacitynum(1) {
    delete[] string;
    capacitynum = copy.capacitynum;
    sizenum = copy.sizenum;
    string = new char[capacitynum];
    for (size_t i = 0; i < sizenum; i++) {
        string[i] = copy.string[i];
    }
    string[sizenum] = '\0';
}

MyString::MyString(const char* copy) : string(nullptr), sizenum(0), capacitynum(1) {
    sizenum = 0;
    while (copy[sizenum] != '\0') {
        sizenum++;
    }
    capacitynum = sizenum + 1;
    string = new char[capacitynum];
    for (size_t i = 0; i < sizenum; i++) {
        string[i] = copy[i];
    }
    string[sizenum] = '\0';
}

MyString::~MyString() {
    if (string != nullptr) {
        delete[] string;
        string = nullptr;
    }
    sizenum = 0;
    capacitynum = 0;
}

size_t MyString::capacity() const noexcept{
    return capacitynum;
}

size_t MyString::size() const noexcept{
    return sizenum;
}

size_t MyString::length() const noexcept{
    return sizenum;
}

const char* MyString::data() const noexcept{
    return string;
}

bool MyString::empty() const noexcept{
    if (sizenum == 0) {
        return true;
    }
    else {
        return false;
    }
}

const char& MyString::front() const {
    return string[0];
}

const char& MyString::at(size_t pos) const{
    if (pos >= sizenum) {
        throw std::out_of_range("Position is out of range");
    }
    return string[pos];

}

size_t MyString::find(const MyString& copy, size_t pos) const noexcept{
    bool match = true;
    for (size_t i = pos; i < sizenum; i++) {
        if (string[i] == copy.string[0]) {
            for (size_t j = 0; j < copy.size(); j++) {
                if (string[j + i] != copy.at(j)) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
    }

    return -1;
}

MyString& MyString::operator=(const MyString& copy) {
    sizenum = copy.sizenum;
    capacitynum = copy.capacitynum;
    this->resize(sizenum);
    for (size_t i = 0;i < sizenum; i++) {
        string[i] = copy.at(i);
    }
    string[sizenum] = '\0';
    return *this;
}

MyString& MyString::operator+=(const MyString& add) {
    size_t old = sizenum;
    this->resize(add.sizenum + sizenum);
    for (size_t i = 0; i < add.sizenum; i++) {
        string[i + old] = add.at(i);
    }
    string[sizenum] = '\0';
    return *this;    

}

void MyString::resize(size_t n) {
    char* new_string = new char[n + 1];
    for (size_t i = 0; i < sizenum; i++) {
        new_string[i] = string[i];
    }
    new_string[n] = '\0';
    delete[] string;
    string = new_string;
    sizenum = n;
    capacitynum = n + 1;
}

void MyString::clear() noexcept{
    if (string != nullptr) {
        delete[] string;
        string = nullptr;
    }
    sizenum = 0;
    capacitynum = 1;
    string = new char[1];
    string[0] = '\0';
}

std::ostream& operator<<(std::ostream& os, const MyString& string) {
    std::string final = "";
    for (size_t i = 0; i < string.size(); i++) {
        final += string.at(i);
    }
    os << final;
    return os;
}

bool operator==(const MyString& lhs, const MyString& rhs) noexcept {
    if (lhs.size() != rhs.size()) {
        return false; 
    }

    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs.at(i) != rhs.at(i)) {
            return false;
        }
    }

    return true;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
    MyString final;
    final += lhs;
    final += rhs;
    return final;
}
