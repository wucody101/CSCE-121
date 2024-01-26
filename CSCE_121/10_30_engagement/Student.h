#ifndef STUDENT_H
#define STUDENT_H

class Student {
    private:
        std::string name;
        int id;
        std::string status;
        std::string major;
         
    public:
        Student();
        Student(std::string name, int id, std::string status, std::string major);
        Student(std::string name);
        std::string getName() const;
	    void setName(std::string name);
        int getId() const;
        void setId(int id);
        std::string getStatus() const;
	    void setStatus(std::string status);
        std::string getMajor() const;
	    void setMajor(std::string major);
};

#endif