#include <vector>
#include <iostream>
#include <string>
#include "Section.h"

int Section::getID() const {
    return id;
}

void Section::setId(int id) {
    this->id = id;
}

std::string Section::getTime() const {
    return time;
}

void Section::setTime(std::string time) {
    this->time = time;
}

std::vector<Student> Section::getStudentList() const{
    return studentList;
}

void Section::setStudentList(std::vector<Student> studentList){
    this->studentList = studentList;
};