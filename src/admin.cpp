#include "admin.h"
#include <iostream>
using namespace std;

// Constructor
Admin::Admin(const string& name, const string& ID, const string& email, const string& adminID, const vector<string>& privileges, const string& department)
    : Person(name, ID, email), adminID(adminID), privileges(privileges), department(department) {}

// Override displayInfo
void Admin::displayInfo() const {
    // Display admin information
    cout << "Admin Name: " << getName() << endl;
    cout << "Admin ID: " << adminID << endl;
    cout << "Department: " << department << endl;
    // Display privileges
    cout << "Privileges: ";
    for (const auto& privilege : privileges) {
        cout << privilege << " ";
    }
    cout << endl;
}

// Override getRole
string Admin::getRole() const {
    return "Admin";
}

// Override sendNotification
void Admin::sendNotification(const string& message) const {
    // Implementation for sending notifications
    cout << "Notification sent: " << message << endl;
}

// Additional functions
void Admin::addCourse(const string& course) {
    // Implementation for adding a course
}

void Admin::removeCourse(const string& course) {
    // Implementation for removing a course
}

void Admin::assignInstructor(const string& instructor) {
    // Implementation for assigning an instructor
}

void Admin::generateReports() const {
    // Implementation for generating reports
}

void Admin::manageCertificates() const {
    // Implementation for managing certificates
}

// Implement the assignment operator
Admin& Admin::operator=(const Admin& other) {
    if (this != &other) {
        Person::operator=(other); // Call base class assignment
        adminID = other.adminID;
        privileges = other.privileges; // Assuming deep copy is needed
        department = other.department;
    }
    return *this;
}

// Implement the equality operator
bool Admin::operator==(const Admin& other) const {
    return Person::operator==(other) && adminID == other.adminID && department == other.department;
}

// Implement the stream insertion operator
ostream& operator<<(ostream& os, const Admin& admin) {
    os << static_cast<const Person&>(admin) << ", Admin ID: " << admin.adminID 
       << ", Department: " << admin.department;
    return os;
}

// Implement the stream extraction operator
istream& operator>>(istream& is, Admin& admin) {
    is >> static_cast<Person&>(admin) >> admin.adminID >> admin.department;
    return is;
}

Admin::~Admin() {}
