#ifndef SECTION_H
#define SECTION_H

#include <vector>
#include "Student.h"

class Section{
    int id;
    std::string time;
    std::vector<Student> studentList;

  public:
    int getID() const;
    void setId(int id);
    std::string getTime() const;
	  void setTime(std::string time);
    std::vector<Student> getStudentList() const;
	  void setStudentList(std::vector<Student> studentList);

};
#endif