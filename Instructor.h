#include <string>

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor {

public:
    bool login(string username, string password);
    string getInstructorName();
    Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    double getAvg(int gradeType);

    //additional functions
    void setInstructorName(string fullName);

private:
    string fullName;

}; //Instructor
