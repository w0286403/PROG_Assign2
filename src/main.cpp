#include "../inc/Student.h"
using namespace std;

int main() {
    bool willContinue = true;
    string courseName, studentName;
    string continued;

    do {
//FOR FIRST STUDENT
        cout << "Please enter the name of the first student" << endl;
        getline(cin, studentName);

        Student std1; //Create first student
        std1.setName(studentName); //Assign name

        do { //loop until user is done entering courses
            cout << "Please enter a course for student " << studentName << " or 'exit' when done." << endl;
            getline(cin,courseName);

            if (courseName != "exit"){
                std1.addCourse(courseName);//add the coursename in the courselist
            }

        } while (courseName != "exit");

        cout << std1 << endl; //output the first student

//FOR SECOND STUDENT
        cout << "Please enter the name of the second student" << endl;
        getline(cin, studentName);

        Student std2(std1);//Create student with copy constructor
        std2.setName(studentName);

        cout << std2 << endl; //output student 2

        std1.reset(); // reset student 1 and output 1&2 to show a deep copy took place
        cout << std1 << endl;
        cout << std2 << endl;

//FOR THIRD STUDENT
        cout << "Please enter the name of the third student" << endl;
        getline(cin, studentName);
        Student std3;
        std3.setName(studentName);

        std3 = std2;//Use assignment op to assign all properties to student three
        cout << std3 << endl; //Output student 3

        std3.addCourse("Another Course"); //Add another course to student 3 to show deep copy took place
        cout << std3 << endl;
        cout << std2 << endl;

//FOR LOOPING THROUGH ENTIRE PROGRAM
        cout << "\n\nDo you want to go again? (Y/N)" << endl;
        getline(cin, continued);
        if (continued == "N"){
            willContinue = false;
        }
    }while(willContinue);

    return 0;
}
