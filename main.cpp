#include <iostream>
#include <ifstream>
#include <sstream>

#include "Instructor.h"
#include "Student.h"
using namespace std;
//need includes to read txt files!

int main(int argc, char *argv[]) {
    /**
     * we should read txt files here and use
     * our classes and methods to print out stuff
     * our main loop
     */
    if (argc != 3) {
        cout << "Usage: main [instructor_file] [student_file]" << endl;
        return 0;
    } //if

    ifstream iFile;
    iFile.open(argv[1]); //instructor file
    ifstream sFile;
    sFile.open(argv[2]); //student file

    Instructor instructor;
    Instructor iarr[3] = {};
    Student * sarr = instructor.getArr();

    if (iFile.is_open() && sFile.is_open()) {
        cout << "Parsing instructors and students information success." << endl;

        string line;
        string slines[20];
        for (int i = 0; getline(sFile, line); i++) {
            slines[i] = line;
        } //for
        for (int i = 0; i < 20; i++) {
            stringsstream ss;
            ss << slines[i];
            string s;
            int n;
            ss >> s;
            sarr[i].setStudentUsername(s);
            ss >> s;
            sarr[i].setStudentPassword(s);
            ss >> s;
            sarr[i].setStudentName(s);
            ss >> n;
            sarr[i].setProjectGrade(n);
            ss >> n;
            sarr[i].setQuizGrade(n);
            ss >> n;
            sarr[i].setMidtermGrade(n);
            ss >> n;
            sarr[i].setFinalGrade(n);
        } //for
        string ilines[3];
        for (int i = 0; getline(iFile, line); i++) {
            ilines[i] = line;
        } //for
        for (int i = 0; i < 3; i++) {
            stringsstream ss;
            ss << ilines[i];
            string s;
            int n;
            ss >> s;
            iarr[i].setInstructorUsername(s);
            ss >> s;
            iarr[i].setInstructorPassword(s);
            ss >> s;
            iarr[i].setInstructorName(s);
        } //for

    } else {
        if (!iFile.is_open()) {
            cout << "Error: cannot parse instructors information from " + argv[1] << endl;
        } //if
        if (!sFile.is_open()) {
            cout << "Error: cannot parse students information from " + argv[2] << endl;
        } //if
        return 0;

    } //if




} //main
