//
// Created by zackg on 2022-11-02.
//
#include "../inc/Student.h"

using namespace std;

Student::Student() {
    numOfCourses = 0;
    courseList = new vector<string>;
    cout << "DEFAULT CONSTRUCTOR FIRED" << endl;
}

Student::~Student() {
    cout << "DESTRUCTOR FIRED" << endl;
    reset();
    if (courseList != nullptr){
        courseList = nullptr;
        delete[] courseList;
    }
}

void Student::reset() {
    courseList->clear();
    numOfCourses = 0;
}

string Student::print() {
    string output = "Student name: " + name;
    output += "\nNumber of courses: " + to_string(numOfCourses);
    output += "Course names: \n";
    for(const auto& itr:*courseList){
        output += itr;
        output += "\n";
    }
    return output;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::addCourse(string courseName) {
    courseList->push_back(courseName);
    numOfCourses++;
}

ostream &operator<<(ostream &output, Student &x) {
    output << x.print();
    return output;
}

