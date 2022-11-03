//
// Created by zackg on 2022-11-02.
//

#include "../inc/Student.h"

using namespace std;

Student::Student() {
    cout << "DEFAULT CONSTRUCTOR FIRED" << endl;
    numOfCourses = 0; // set num of courses to 0
    courseList = new vector<string>; //declare the courselist on the heap
}

Student::~Student() {
    cout << "DESTRUCTOR FIRED" << endl;
    reset();//call reset function to clear
    if (courseList != nullptr){ //if courselist isn't null pointer, make it one and delete
        courseList = nullptr;
        delete courseList;
    }
}

Student::Student(const Student &student) {
    cout << "COPY CONSTRUCTOR FIRED" << endl;
    courseList = new vector<string>; //declare courselist on the heap
    numOfCourses = student.numOfCourses; //set num to the passing student
    courseList->insert(courseList->begin(),student.courseList->begin(),student.courseList->end()); //Insert the passing student's full courselist at the beginning of the constructed student's
}

void Student::reset() {
    courseList->clear(); //clear the vector down to 0
    numOfCourses = 0;
}

void Student::setName(string pName) {
    this->name = std::move(pName); //set the students name
}

void Student::addCourse(const string& courseName) {
    courseList->push_back(courseName); //add the coursename to the next spot in vector
    numOfCourses++;//increment the cnumber of courses
}

ostream &operator<<(ostream &output, Student &student) {
    //Concat all formatting info into the output stream which is being returned at bottom
    output << "Student name: " << student.name;
    output << "\nNumber of courses: " << to_string(student.numOfCourses);
    output << "\nCourse names: \n";
    for(const auto& itr:*student.courseList){
        output << itr;
        output << "\n";
    }
    return output;
}

Student& Student::operator=(const Student& student) {
    cout << "OVERLOADED = FIRED" << endl;
    if (this == &student){return *this;} //Takes care of the self assignment problem
    numOfCourses = student.numOfCourses;//new students num of courses is the passed num
    courseList->insert(courseList->begin(),student.courseList->begin(),student.courseList->end());//Insert the passing student's full courselist at the beginning of the constructed student's
    return *this; // return the student
}



