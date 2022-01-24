#include <string>
#include <iostream> //idk if i actually need these in this file

#include "Instructor.h" //necessary
#include "Student.h"

using namespace std; //printing out things

Student Instructor::arr[] = {};

bool Instructor::login(string username, string password) {
    return true;
} //login

Instructor::Instructor() {
    //no need for default vars?
} //Instructor

string Instructor::getInstructorName() {
    return fullName;
} //getInstructorName

Student Instructor::getStudent(string username) {

    for (int i = 0; i < 20; i++) {
        if(arr[i].getStudentUsername().compare(username) == 0) {
            return arr[i];
        } // if found username
    } // for
    return arr[20];

} //getStudent

Student Instructor::getMinStudent(int gradeType) {

    if (gradeType == 1) { // finds student with lowest project score
        int currentGrade = arr[1].getProjectGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getProjectGrade() < currentGrade) {
                location = i;
                currentGrade = arr[i].getProjectGrade();
            } // if
        } // for
        return arr[location];
    } // if

    if (gradeType == 2) { // finds student with lowest quiz score
        int currentGrade = arr[1].getQuizGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getQuizGrade() < currentGrade) {
                location = i;
                currentGrade = arr[i].getQuizGrade();
            } // if
        } // for
        return arr[location];
    } // if

    if (gradeType == 3) { // finds student with lowest midterm score
        int currentGrade = arr[1].getMidtermGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getMidtermGrade() < currentGrade) {
                location = i;
                currentGrade = arr[i].getMidtermGrade();
            } // if
        } // for
        return arr[location];
    } // if

    if (gradeType == 4) { // finds student with lowest final score
        int currentGrade = arr[1].getFinalGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getFinalGrade() < currentGrade) {
                location = i;
                currentGrade = arr[i].getFinalGrade();
            } // if
        } // for
        return arr[location];
    } // if

    if (gradeType == 5) { // finds student with lowest overall score
        double currentGrade = arr[1].getOverallGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getOverallGrade() < currentGrade) {
                location = i;
                currentGrade = arr[i].getOverallGrade();
            } // if
        } // for
        return arr[location];
    } // if
    return arr[20];

} //getMinStudent

Student Instructor::getMaxStudent(int gradeType) {


    if (gradeType == 1) { // finds student with highest project score
        int currentGrade = arr[1].getProjectGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getProjectGrade() > currentGrade) {
                location = i;
                currentGrade = arr[i].getProjectGrade();
            } // if
        } // for
        return arr[location];
    } // if

    if (gradeType == 2) { // finds student with highest quiz score
        int currentGrade = arr[1].getQuizGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getQuizGrade() > currentGrade) {
                location = i;
                currentGrade = arr[i].getQuizGrade();
            } // if
        } // for
        return arr[location];
    } // if

    if (gradeType == 3) { // finds student with highest midterm score
        int currentGrade = arr[1].getMidtermGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getMidtermGrade() > currentGrade) {
                location = i;
                currentGrade = arr[i].getMidtermGrade();
            } // if
        } // for
        return arr[location];
    } // if

    if (gradeType == 4) { // finds student with highest final score
        int currentGrade = arr[1].getFinalGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getFinalGrade() > currentGrade) {
                location = i;
                currentGrade = arr[i].getFinalGrade();
            } // if
        } // for
        return arr[location];
    } // if

    if (gradeType == 5) { // finds student with highest overall score
        double currentGrade = arr[1].getOverallGrade();
        int location = 0;
        for (int i = 0; i < 20; i++) {
            if (arr[i].getOverallGrade() > currentGrade) {
                location = i;
                currentGrade = arr[i].getOverallGrade();
            } // if
        } // for
        return arr[location];
    } // if
    return arr[20];

} //getMaxStudent

double Instructor::getAvg(int gradeType) {

    if (gradeType == 1) { // average project
        double average = 0;
        for (int i = 0; i < 20; i++) {
            average += arr[i].getProjectGrade();
        } // for
        return average / 20;
    } // if

    if (gradeType == 2) { // average quiz
        double average = 0;
        for (int i = 0; i < 20; i++) {
            average += arr[i].getQuizGrade();
        } // for
        return average / 20;
    } // if

    if (gradeType == 3) { // average midterm
        double average = 0;
        for (int i = 0; i < 20; i++) {
            average += arr[i].getMidtermGrade();
        } // for
        return average / 20;
    } // if

    if (gradeType == 4) { // average final
        double average = 0;
        for (int i = 0; i < 20; i++) {
            average += arr[i].getFinalGrade();
        } // for
        return average / 20;
    } // if

    if (gradeType == 5) { // average overall
        double average = 0;
        for (int i = 0; i < 20; i++) {
            average += arr[i].getOverallGrade();
        } // for
        return average / 20;
    } // if
    return -1;
} //getAvg

    //additional functions
void Instructor::setInstructorUsername(string name) {
    userName = name;
} //setInstructorName

void Instructor::setInstructorPassword(string pw) {
    password = pw;
} //setInstructorName

void Instructor::setInstructorName(string name) {
    fullName = name;
} //setInstructorName
