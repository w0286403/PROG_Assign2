//
// Created by zackg on 2022-11-02.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;
#ifndef ASSIGNMENT_2_STUDENT_H
#define ASSIGNMENT_2_STUDENT_H

class Student{
private:
    string name;
    int numOfCourses;
    vector<string> *courseList;
    friend ostream& operator<<(ostream&, Student&);
public:
    Student();
    ~Student();
    void setName(string);
    void addCourse(string);
    string print();
    void reset();
    Student&operator=(const Student);

};



#endif //ASSIGNMENT_2_STUDENT_H
