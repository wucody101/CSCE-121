#include <iostream>
#include <string>
#include <vector>
#include "Section.h"
using namespace std;

int main(){

    Section sec;
    sec.setId(500);
    sec.setTime("01:50PM - MWF");

    Student harry;
    harry.setName("Harry Potter");
    Student hermione("Hermione Granger");

    vector<Student> students;
    students.push_back(harry);
    students.push_back(hermione);
    sec.setStudentList(students);

    cout << "Section: " << sec.getID() << endl;
    cout << "Time: " << sec.getTime() << endl;
    cout << "Students: " << endl;
    for (int i=0; i < sec.getStudentList().size(); i++){
        cout << sec.getStudentList().at(i).getName() << endl;
    }

}