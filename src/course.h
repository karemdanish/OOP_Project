#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "module.h" 
using namespace std;

// Forward declarations
class Instructor; 
class Student;
class Module;

// Course Class
class Course {
private:
    string courseTitle;      // Course title
    string courseCode;       // Course code
    string description;      // Course description
    Instructor* instructor;  // Aggregation with Instructor
    vector<Student*> students; // Association with Student
    vector<Module*> modules;  // Composition with Module
    vector<Instructor *> instructors; // Instructors list

public:
    // Constructor
    Course(const string& title, const string& code, const string& desc, Instructor* instr);

    // Methods
    Instructor *findInstructorByID(const string &id);
    Student *findStudentByID(const string &id);
    void addStudent(Student* student); // Add a student to the course
    void addModule(Module* module);     // Add a module to the course
    void displayCourseInfo() const;     // Display course information
    // File handling methods
    void saveToFile(ofstream &outFile) const; // Save course data to file
    void loadFromFile(ifstream &inFile);

    // Assignment operator
    Course& operator=(const Course& other); // Assign one course to another

    // Equality operator
    bool operator==(const Course& other) const; // Check if two courses are equal

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Course& course); // Output course details

    // Stream extraction operator
    friend istream& operator>>(istream& is, Course& course); // Input course details

    // Add student to course using + operator
    Course& operator+(Student* student); // Add a student to the course

    // Remove student from course using - operator
    Course& operator-(Student* student); // Remove a student from the course
};

#endif //COURSE_H
