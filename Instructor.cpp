#include <string>
#include <iostream> //idk if i actually need these in this file

#include "Instructor.h" //necessary

using namespace std; //printing out things

bool Instructor::login(string username, string password) {

} //login

Instructor::Instructor() {
    //no need for default vars?
} //Instructor

string Instructor::getInstructorName() {
    return fullName;
} //getInstructorName

Student Instructor::getStudent(string username) {

} //getStudent

Student Instructor::getMinStudent(int gradeType) {

} //getMinStudent

Student Instructor::getMaxStudent(int gradeType) {

} //getMaxStudent

double Instructor::getAvg(int gradeType) {

} //getAvg

    //additional functions
void setInstructorName(string name) {
    fullName = name;
} //setInstructorName
