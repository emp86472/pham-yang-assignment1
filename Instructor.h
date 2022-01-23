#include <string>
#include "Student.h"

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

using namespace std;

class Instructor {

public:
    //static Student arr[20];
    bool login(string username, string password);
    string getInstructorName();
    Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    double getAvg(int gradeType);

    //additional functions
    void setInstructorName(string fullName);

private:
    static Student arr[20];
    string fullName;

}; //Instructor

#endif
