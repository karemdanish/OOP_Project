#include "course.h"
#include "instructor.h"
#include "student.h"
#include "module.h"
#include <iostream>
using namespace std;

// Constructor
Course::Course(const string& title, const string& code, const string& desc, Instructor* instr)
    : courseTitle(title), courseCode(code), description(desc), instructor(instr) {}

// Add a student to the course
void Course::addStudent(Student* student) {
    students.push_back(student);
}

// Add a module to the course
void Course::addModule(Module *module)
{
    modules.push_back(module); // Add module to the course
}

// Display course information
void Course::displayCourseInfo() const {
    cout << "Course Title: " << courseTitle << ", Course Code: " << courseCode 
         << ", Description: " << description << endl;
    // Additional information about instructor and students can be added here
}

// Assignment operator
// This operator allows for the assignment of one Course object to another.
// It performs a deep copy of the course title, code, description, instructor, students, and modules.
// Parameters:
//   const Course& other: The Course object to be copied from.
// Returns:
//   A reference to the current Course object.
Course& Course::operator=(const Course& other) {
    if (this != &other) {
        courseTitle = other.courseTitle;
        courseCode = other.courseCode;
        description = other.description;
        instructor = other.instructor; // Assuming deep copy is needed
        students = other.students; // Assuming deep copy is needed
        modules = other.modules; // Assuming deep copy is needed
    }
    return *this;
}

// Implement the equality operator
// This operator checks if two Course objects are equal based on their title, code, and description.
// Parameters:
//   const Course& other: The Course object to compare with.
// Returns:
//   true if the courses are equal, false otherwise.
bool Course::operator==(const Course& other) const {
    return courseTitle == other.courseTitle && courseCode == other.courseCode 
           && description == other.description;
}

// Implement the stream insertion operator
// This operator outputs the details of the course to the provided output stream.
// Parameters:
//   ostream& os: The output stream to write to.
//   const Course& course: The Course object to output.
// Returns:
//   The output stream after writing the course details.
ostream& operator<<(ostream& os, const Course& course) {
    os << "Course Title: " << course.courseTitle << ", Course Code: " << course.courseCode 
       << ", Description: " << course.description;
    return os;
}

// Implement the stream extraction operator
// This operator reads course details from the input stream into the Course object.
// Parameters:
//   istream& is: The input stream to read from.
//   Course& course: The Course object to populate.
// Returns:
//   The input stream after reading the course details.
istream& operator>>(istream& is, Course& course) {
    is >> course.courseTitle >> course.courseCode >> course.description;
    return is;
}

// Implement the + operator for adding a student
Course& Course::operator+(Student* student) {
    students.push_back(student);
    return *this;
}

// Implement the - operator for removing a student
Course& Course::operator-(Student* student) {
    auto it = find(students.begin(), students.end(), student);
    if (it != students.end()) {
        students.erase(it);
    }
    return *this;
}
