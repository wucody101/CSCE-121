#include <iostream>
#include <string>
#include "Student.h"

Student::Student():
    name (""),
    id (0),
    status(""),
    major(""){ }

Student::Student(std::string name, int id, std::string status, std::string major):
    name (name),
    id (id),
    status(status),
    major(major){ }

Student::Student(std::string name):
    name (name),
    id (0),
    status(""),
    major(""){ }

std::string Student::getName() const {
    return name;
}

void Student::setName(std::string name) {
    this->name = name;
}

int Student::getId() const { 
    return id;
}

void Student::setId(int id){
    this->id = id;
}

std::string Student::getStatus() const {
    return status;
};

void Student::setStatus(std::string status) {
    this->status = status;
};

std::string Student::getMajor() const{
    return major;
};

void Student::setMajor(std::string major){
    this->major = major;
};


