//
// Created by zackg on 2022-11-02.
//
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

#ifndef ASSIGNMENT_2_STUDENT_H
#define ASSIGNMENT_2_STUDENT_H
using namespace std;
class Student{
private:
    //Three student variables
    string name;
    int numOfCourses;
    vector<string> *courseList;
    friend ostream& operator<<(ostream&, Student&); //Friend function for output
public:
    Student(); //default constructor
    ~Student(); //Destructor
    Student(const Student&); //copy constructor
    void setName(string);
    void addCourse(const string&);
    void reset();
    Student& operator=(const Student&); //overloading assignment operator
};

#endif //ASSIGNMENT_2_STUDENT_H
