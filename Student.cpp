#include <string>
#include <iostream> //idk if i actually need these in this file

#include "Student.h" //this is necessary tho

using namespace std; //think we'll need this for printing stuff out

//no need to declare class again, just initialize methods!
Student::Student() {
    //dont need default values for member variables?
} //Student

bool Student::login(string username, string password) {

} //login

string Student::getStudentName() {
    return fullName;
} //getStudentName

int Student::getProjectGrade() {
    return projectGrade;
} //getProjectGrade

int Student::getQuizGrade() {
    return quizGrade;
} //getQuizGrade()
int Student::getMidtermGrade() {
    return midtermGrade;
} //getMidtermGrade

int Student::getFinalGrade() {
    return finalGrade;
} //getFinalGrade

double Student::getOverallGrade() {
    //calculated by previous grades
} //getOverallGrade

//additional functions
void Student::setStudentName(string name) {
    fullName = name;
} //setStudentName

void Student::setProjectGrade(int grade) {
    projectGrade = grade;
} //setProjectGrade

void Student::setQuizGrade(int grade) {
    quizGrade = grade;
} //setQuizGrade

void Student::setMidtermGrade(int grade) {
    midtermGrade = grade;
} //setMidtermGrade

void Student::setFinalGrade(int grade) {
    finalGrade = grade;
} //setFinalGrade