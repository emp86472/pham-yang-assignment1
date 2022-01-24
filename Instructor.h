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
    Student* getArr();

    //additional functions
    void setInstructorUsername(string name);
    void setInstructorPassword(string pw);
    void setInstructorName(string name);

private:
    static Student arr[21];
    string fullName;
    string userName;
    string password;

}; //Instructor

#endif
