#include <string>
#include "Student.h"

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

using namespace std;

class Instructor {

public:
    //static Student arr[20];
    Instructor();
    bool login(string username, string password);
    string getInstructorName();
    static Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    double getAvg(int gradeType);
    //static Student* getArr();

    //additional functions
    void setInstructorUsername(string name);
    void setInstructorPassword(string pw);
    void setInstructorName(string name);
    static Student arr[21];

private:
    string fullName;
    string userName;
    string password;

}; //Instructor

#endif
