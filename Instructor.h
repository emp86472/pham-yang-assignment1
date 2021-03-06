#include <string>
#include "Student.h"

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

using namespace std;

class Instructor {

public:
    //static Student arr[20];
    Instructor();
    bool login(string pw);
    string getInstructorUsername();
    string getInstructorName();
    static Student getStudent(string username);
    static Student getMinStudent(int gradeType);
    static Student getMaxStudent(int gradeType);
    static double getAvg(int gradeType);
    //static Student* getArr();

    //additional functions
    void setInstructorUsername(string name);
    void setInstructorPassword(string pw);
    void setInstructorName(string name);
    static void printGradeStats(int gradeType);
    static Student arr[21];

private:
    string fullName;
    string userName;
    string password;

}; //Instructor

#endif
