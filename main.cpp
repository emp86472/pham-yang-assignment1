#include <iostream>
#include <fstream>
#include <sstream>

#include "Instructor.h"
#include "Student.h"
using namespace std;
//need includes to read txt files!


int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Usage: main [instructor_file] [student_file]" << endl;
        return 0;
    } //if

    ifstream iFile;
    iFile.open(argv[1]); //instructor file
    ifstream sFile;
    sFile.open(argv[2]); //student file

    Instructor iarr[3] = {};
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
            string d;
            int n;
            ss >> s;
            sarr[i].setStudentUsername(s);
            ss >> s;
            sarr[i].setStudentPassword(s);
            ss >> s;
            ss >> d;
            sarr[i].setStudentName(s + " " + d);
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
            string d;
            ss >> s;
            ss >> d;
            iarr[i].setInstructorUsername(s + " " + d);
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
        if (x == 2) {
            cout << "Enter credentials to log in," << endl;
            cout << "\tEnter username: ";
            string username;
            cin >> username;
            cout << "\tEnter password: ";
            string password;
            cin >> password;
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
                if (s == "y") {
                    student.printGrades();
                } //if
            } else {
                cout << "Login as student failed." << endl;
                cout << endl;
            } //if

        } else if (x == 1) {
            cout << "Enter credentials to log in," << endl;
            cout << "\tEnter username: ";
            string username;
            cin >> username;
            cout << "\tEnter password: ";
            string password;
            cin >> password;
            cout << endl;
            int location = 0;
            int iteration = 0;
            for (int i = 0; i < 3; i++) {
                if (iarr[i].getInstructorUsername() == username) {
                    location = i;
                }
                iteration = i;
            } // for
            if (location != iteration) {// no such username
                cout << "Login as instructor failed." << endl;
                cout << endl;
                continue;
            } // for
            if (iarr[location].login(password)) { // incorrecct password
                cout << "Login as instructor failed" << endl;
                cout << endl;
                continue;
            } // if
            cout << "You are now logged in as instructor "
                 << iarr[location].getInstructorName() << "." << endl;
            cout << "\n";
            while(true) {
                cout << "Query options," << endl;
                cout << "\t" << "1 - view grades of a student" << endl;
                cout << "\t" << "2 - view stats" << endl;
                int option;
                cout << "Enter option number: ";
                cin >> option;
                cout << endl;
                cout << "\n";

                if (option == 1) { // view grade
                    while (true) {
                        cout << "Enter student username to view grades: ";
                        string sUsername;
                        cin >> sUsername;
                        Student student = Instructor::getStudent(sUsername);
                        string studentName = student.getStudentName();

                        if (studentName.length() == 0) { // checks for valid username
                            cout << "Student username is not valid." << endl;
                            continue;
                        } // if
                        student.printGrades();
                        break;
                    } // while
                } else if (option == 2) { // view stats
                    while(true) {
                        cout << "Grade types," << endl;
                        cout << "   1 - Project grade" << endl;
                        cout << "   2 - Quiz grade" << endl;
                        cout << "   3 - Midterm grade" << endl;
                        cout << "   4 - Final grade" << endl;
                        cout << "   5 - Overall grade" << endl;
                        cout << "Select a grade type to view stats: ";
                        int type;
                        cin >> type;
                        cout << "\n" << endl;

                        if (type <= 5 && type >= 1) {
                            Instructor::printGradeStats(type);
                            break;
                        } else {
                            cout << "Invalid option. Please enter a valid option." << endl;
                        } //if
                    } // while
                } else {
                    cout << "Invalid option. Please enter a valid option." << endl;
                    continue;
                } // else
                break;
            } // while
        } else if (x == 3) {
            break;
        } else {
            cout << "Invalid option. Please enter a valid option." << endl;
            cout << endl;
        } //if

    } //while
    return 0;
} //main
