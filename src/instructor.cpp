#include "instructor.h"
#include <iostream>
using namespace std;

// Constructor
Instructor::Instructor(const string& name, const string& ID, const string& email, const string& employeeID, const string& department)
    : Person(name, ID, email), employeeID(employeeID), department(department) {}

// Override displayInfo
void Instructor::displayInfo() const {
    // Display instructor information
    cout << "Name: " << getName() << ", ID: " << getID() << ", Email: " << getEmail() 
         << ", Employee ID: " << employeeID << ", Department: " << department << endl;
}

// Override getRole
string Instructor::getRole() const {
    return "Instructor";
}

// Override sendNotification
void Instructor::sendNotification(const string& message) const {
    cout << "Notification to " << getName() << ": " << message << endl;
}

// Create an assignment
void Instructor::createAssignment(const string& assignment) {
    cout << getName() << " has created an assignment: " << assignment << endl;
}

// Grade a submission
void Instructor::gradeSubmission(const string& submission) {
    cout << getName() << " has graded the submission: " << submission << endl;
}

// Monitor student progress
void Instructor::monitorStudentProgress() const {
    cout << getName() << " is monitoring student progress." << endl;
}

// Issue a certification
void Instructor::issueCertification(const string& studentID) {
    cout << getName() << " has issued a certification to student ID: " << studentID << endl;
}

// New method to receive notification
void Instructor::receiveNotification(const Notification& notification) {
    cout << "Received Notification: " << notification.getMessage() << " on " << notification.getDateSent() << endl;
}

// Implement the assignment operator
Instructor& Instructor::operator=(const Instructor& other) {
    if (this != &other) {
        Person::operator=(other); // Call base class assignment
        employeeID = other.employeeID;
        department = other.department;
        assignedCourses = other.assignedCourses;
    }
    return *this;
}

// Implement the equality operator
bool Instructor::operator==(const Instructor& other) const {
    return Person::operator==(other) && employeeID == other.employeeID && department == other.department;
}

// Implement the stream insertion operator
ostream& operator<<(ostream& os, const Instructor& instructor) {
    os << static_cast<const Person&>(instructor) << ", Employee ID: " << instructor.employeeID 
       << ", Department: " << instructor.department;
    return os;
}

// Implement the stream extraction operator
istream& operator>>(istream& is, Instructor& instructor) {
    is >> static_cast<Person&>(instructor) >> instructor.employeeID >> instructor.department;
    return is;
}

Instructor::~Instructor() {}
