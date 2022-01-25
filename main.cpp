#include <iostream>
#include <fstream>
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

    Instructor iarr[2] = {};
    Student * sarr = &Instructor::arr[0];

    if (iFile.is_open() && sFile.is_open()) {
        cout << "Parsing instructors and students information success." << endl;

        string line;
        string slines[20];
        for (int i = 0; getline(sFile, line); i++) {
            slines[i] = line;
        } //for
        for (int i = 0; i < 20; i++) {
            stringstream ss;
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
            stringstream ss;
            ss << ilines[i];
            string s;
            ss >> s;
            iarr[i].setInstructorUsername(s);
            ss >> s;
            iarr[i].setInstructorPassword(s);
            ss >> s;
            iarr[i].setInstructorName(s);
        } //for
    } else {
        if (!iFile.is_open()) {
            cout << "Error: cannot parse instructors information from ";
            cout << argv[1] << endl;
            cout << endl;
        } //if
        if (!sFile.is_open()) {
            cout << "Error: cannot parse students information from ";
            cout << argv[2] << endl;
            cout << endl;
        } //if
        return 0;
    } //if
    sFile.close();
    iFile.close();

    //cout << "we made it here!" << endl;

    //main loop
    while (true) {
        cout << "User types," << endl;
        cout << "\t1 - Instructor" << endl;
        cout << "\t2 - Student" << endl;
        cout << "Select a login user type or enter 3 to exit: ";
        int x;
        cin >> x;
        cout << endl;
        cout << endl;
        if (x == 1) {
            cout << "Enter credentials to log in," << endl;
            cout << "\tEnter username: ";
            string username;
            cin >> username;
            cout << endl;
            cout << "\tEnter password: ";
            string password;
            cin >> password;
            cout << endl;
            cout << endl;
            Student student = Instructor::getStudent(username);
            if (student.login(password)) {
                cout << "You are now logged in as ";
                cout << student.getStudentName();
                cout << "\n\n";
                cout << "Do you want to view grades (y/n)? ";
                string s;
                cin >> s;
                cout << endl;
                cout << endl;
                if (s == "y") {
                    student.printGrades();
                    cout << endl;
                    cout << endl;
                } //if
                continue;
            } else {
                cout << "Login as student failed." << endl;
                continue;
            } //if

        } else if (x == 2) {

        } else if (x == 3) {
            break;
        } else {
            cout << "Invalid option. Please enter a valid option." << endl;
            continue;
        } //if
        break; //remove this


    } //while
    return 0;
} //main
