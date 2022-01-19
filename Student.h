#include <string>

#ifndef STUDENT_H
#define STUDENT_H

class Student {

public:
    Student();
    bool login(string username, string password);
    string getStudentName();
    int getProjectGrade();
    int getQuizGrade();
    int getMidtermGrade();
    int getFinalGrade();
    double getOverallGrade();

    //additional functions
    void setStudentName(string fullName);
    void setProjectGrade(int grade);
    void setQuizGrade(int grade);
    void setMidtermGrade(int grade);
    void setFinalGrade(int grade);

private:
    string fullName;
    int projectGrade;
    int quizGrade;
    int midtermGrade;
    int finalGrade;

}; //Student

#endif
