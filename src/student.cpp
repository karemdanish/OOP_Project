#include "student.h"
#include "notifications.h"
#include <iostream>
using namespace std;

// Constructor
Student::Student(const string& name, const string& ID, const string& email, const string& studentID, const string& enrollmentDate)
    : Person(name, ID, email), studentID(studentID), enrollmentDate(enrollmentDate) {}

// Copy constructor
Student::Student(const Student &other)
    : Person(other), // Call base class copy constructor
      studentID(other.studentID),
      enrollmentDate(other.enrollmentDate),
      completedCourses(other.completedCourses)
{
}

// Destructor (if you have any dynamically allocated resources)
Student::~Student()
{
    // If no dynamically allocated resources, this can be default
    // But it's good practice to define it explicitly
}

// Override displayInfo
void Student::displayInfo() const {
    // Display student information
    cout << "Name: " << getName() << ", ID: " << getID() << ", Email: " << getEmail() 
         << ", Student ID: " << studentID << ", Enrollment Date: " << enrollmentDate << endl;
}
// Override getRole
string Student::getRole() const {
    return "Student";
}

// Override sendNotification
void Student::sendNotification(const string& message) const {
    cout << "Notification to " << getName() << ": " << message << endl;
}

// Enroll in a course
void Student::enrollInCourse(const string& course) {
    completedCourses.push_back(course);
    cout << getName() << " has enrolled in " << course << endl;
}

// Submit an assignment
void Student::submitAssignment(const string& assignment) {
    cout << getName() << " has submitted the assignment: " << assignment << endl;
}

// Check progress
void Student::checkProgress() const {
    cout << getName() << "'s completed courses: ";
    for (const auto& course : completedCourses) {
        cout << course << " ";
    }
    cout << endl;
}

// View certifications
void Student::viewCertifications() const {
    cout << getName() << "'s certifications: [List of certifications]" << endl; // Placeholder
}

// New method to receive notification
void Student::receiveNotification(const Notification& notification) {
    cout << "Notification received: " << notification.getMessage() << endl;
}

// Implement the assignment operator
Student &Student::operator=(const Student &other)
{
    if (this != &other)
    { // Protect against self-assignment
        // Call base class assignment operator
        Person::operator=(other);

        // Copy member variables
        studentID = other.studentID;
        enrollmentDate = other.enrollmentDate;

        // Deep copy the completedCourses vector
        completedCourses = other.completedCourses;
    }
    return *this;
}
// Implement the equality operator
bool Student::operator==(const Student& other) const {
    return Person::operator==(other) && studentID == other.studentID && enrollmentDate == other.enrollmentDate;
}

// Implement the stream insertion operator
ostream& operator<<(ostream& os, const Student& student) {
    os << static_cast<const Person&>(student) << ", Student ID: " << student.studentID 
       << ", Enrollment Date: " << student.enrollmentDate;
    return os;
}

// Implement the stream extraction operator
istream& operator>>(istream& is, Student& student) {
    is >> static_cast<Person&>(student) >> student.studentID >> student.enrollmentDate;
    return is;
}

// Implement the subscript operator
string& Student::operator[](int index) {
    return completedCourses[index]; // Assuming completedCourses is a vector<string>
}

// Implement the + operator
Student& Student::operator+(const string& course) {
    completedCourses.push_back(course);
    return *this;
}

// Implement the - operator
Student& Student::operator-(const string& course) {
    auto it = find(completedCourses.begin(), completedCourses.end(), course);
    if (it != completedCourses.end()) {
        completedCourses.erase(it);
    }
    return *this;
}

// Implement the | operator for union
vector<string> Student::operator|(const Student& other) const {
    vector<string> unionCourses = completedCourses;
    for (const auto& course : other.completedCourses) {
        if (find(unionCourses.begin(), unionCourses.end(), course) == unionCourses.end()) {
            unionCourses.push_back(course);
        }
    }
    return unionCourses;
}

// Implement the & operator for intersection
vector<string> Student::operator&(const Student& other) const {
    vector<string> intersectionCourses;
    for (const auto& course : completedCourses) {
        if (find(other.completedCourses.begin(), other.completedCourses.end(), course) != other.completedCourses.end()) {
            intersectionCourses.push_back(course);
        }
    }
    return intersectionCourses;
}
