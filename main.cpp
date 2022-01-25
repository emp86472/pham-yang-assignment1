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
            cout << "Enter credentials to log in," << endl;
            cout << "\tEnter username: ";
            string username;
            cin >> username;
            endl;
            cout << "\tEnter password: ";
            string password;
            cin >> password;
            endl;
            int location = 0;
            int iteration = 0;
            for (int i = 0; i < 3; i++) {
                if (iarr[i].getInstructorUsername() == username) {
                    location = i;
                }
                iteration = i;
            } // for
            if (location != iteration) {// no such username
                cout << "login as Instructor failed." << endl;
                continue;
            } // for
            if (iarr[location].login(password) == false) { // incorrecct password
                cout << "Login as instructor failed" << endl;
                continue;
            } // if
            cout << "You are now logged in as instructor "
                 << iarr[location].getinstructorName() << "." << endl;
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
                        string studentUsername;
                        cin >> studentusername;
                        string studentName = getStudent(studentUsername).getStudentName();
                        int projectGrade = getStudent(studentUsername).getProjectGrade();

                        if (projectGrade == -1) { // checks for valid username
                            cout << "Student username is not valid.";
                            continue;
                        } // if

                        int quizGrade = getStudent(studentUsername).getQuizGrade();
                        int midtermGrade = getStudent(studentUsername).getMidtermGrade();
                        int finalGrade = getStudent(studentUsername).getFinalGrade();
                        double overallGrade = getStudent(studentUsername).getOverallGrade();

                        cout << "Student name: " << studentName << "%" << endl;
                        cout << "Project    " << projectGrade << "%"<< endl;
                        cout << "Quiz       " << quizGrade << "%" << endl;
                        cout << "Midterm    " << midtermGrade << "%" << endl;
                        cout << "Final      " << finalGrade << "%" << endl;
                        cout << "Overall    " << overallGrade << "%" << endl;
                        cout << "\n";
                        break;
                    } // while
                    break;
                } // if

                if (option == 2) { // view stats
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
                        cout << "\n";

                        if (type == 1) {
                            cout << "Project grade stats," << endl;
                            cout << "min  " << getMinStudent(1).getProjectGrade() << "% ("
                                 << getMinStudent(1).getStudentName() << ")" << endl;
                            cout << "max  " << getMaxStudent(1).getProjectGrade() << "% ("
                                 << getMaxStudent(1).getStudentName() << ")" << endl;
                            cout << "avg  " << getAvg(1) << "%" << endl;
                            break;
                        } // if

                        if (type == 2) {
                            cout << "Quiz grade stats," << endl;
                            cout << "min  " << getMinStudent(2).getQuizGrade() << "% ("
                                 << getMinStudent(2).getStudentName() << ")" << endl;
                            cout << "max  " << getMaxStudent(2).getQuizGrade() << "% ("
                                 << getMaxStudent(2).getStudentName() << ")" << endl;
                            cout << "avg  " << getAvg(2) << "%" << endl;
                            break;
                        }

                        if (type == 3) {
                            cout << "Midterm grade stats," << endl;
                            cout << "min  " << getMinStudent(3).getMidtermGrade() << "% ("
                                 << getMinStudent(3).getStudentName() << ")" << endl;
                            cout << "max  " << getMaxStudent(3).getMidtermGrade() << "% ("
                                 << getMaxStudent(3).getStudentName() << ")" << endl;
                            cout << "avg  " << getAvg(3) << "%" << endl;
                            break;
                        }

                        if (type == 4) {
                            cout << "Final grade stats," << endl;
                            cout << "min  " << getMinStudent(4).getFinalGrade() << "% ("
                                 << getMinStudent(4).getStudentName() << ")" << endl;
                            cout << "max  " << getMaxStudent(4).getFinalGrade() << "% ("
                                 << getMaxStudent(4).getStudentName() << ")" << endl;
                            cout << "avg  " << getAvg(4) << "%" << endl;
                            break;
                        }

                        if (type == 5) {
                            cout << "Overall grade stats," << endl;
                            cout << "min  " << getMinStudent(5).getOverallGrade() << "% ("
                                 << getMinStudent(5).getStudentName() << ")" << endl;
                            cout << "max  " << getMaxStudent(5).getOverallGrade() << "% ("
                                 << getMaxStudent(5).getStudentName() << ")" << endl;
                            cout << "avg  " << getAvg(5) << "%" << endl;
                            break;
                        }
                        else {
                            cout << "Invalid option. Please enter a valid option." << endl;
                        } // else
                    } // while
                    break;
                } // if
                else {
                    cout << "Invalid option. Please enter a valid option.";
                } // else
            } // while



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
