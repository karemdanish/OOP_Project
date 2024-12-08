#include "instructor.h"
#include "notifications.h"
#include <fstream>
#include <iostream>
using namespace std;

// Constructor
Instructor::Instructor(const string &name, const string &ID, const string &email,
                       const string &employeeID, const string &department)
    : Person(name, ID, email), employeeID(employeeID), department(department) {}

// Copy constructor
Instructor::Instructor(const Instructor &other)
    : Person(other),
      employeeID(other.employeeID),
      department(other.department),
      assignedCourses(other.assignedCourses) {}

// Destructor
Instructor::~Instructor()
{
    // No dynamic memory to clean up, but keeping it virtual
}

// Override displayInfo
void Instructor::displayInfo() const
{
    // Use base class output and add instructor-specific details
    cout << "Instructor Information:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getID() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Department: " << department << endl;
}

// Override getRole
string Instructor::getRole() const
{
    return "Instructor";
}

// Override sendNotification
void Instructor::sendNotification(const string &message) const
{
    cout << "Notification for Instructor " << getName() << ": " << message << endl;
}

// Create an assignment
void Instructor::createAssignment(const string &assignment)
{
    cout << getName() << " has created an assignment: " << assignment << endl;
}

// Grade a submission
void Instructor::gradeSubmission(const string &submission)
{
    cout << getName() << " has graded the submission: " << submission << endl;
}

// Monitor student progress
void Instructor::monitorStudentProgress() const
{
    cout << getName() << " is monitoring student progress." << endl;
}

// Issue a certification
void Instructor::issueCertification(const string &studentID)
{
    cout << getName() << " has issued a certification to student ID: " << studentID << endl;
}

// Receive notification
void Instructor::receiveNotification(const Notification &notification)
{
    cout << "Notification received by " << getName() << ": "
         << notification.getMessage() << endl;
}

void Instructor::saveToFile(ofstream &outFile) const
{
    outFile << employeeID << "," << department << endl; // Save instructor details
}

void Instructor::loadFromFile(ifstream &inFile)
{
    string line;
    if (getline(inFile, line))
    {
        size_t pos = 0;
        pos = line.find(',');
        employeeID = line.substr(0, pos);
        line.erase(0, pos + 1);

        department = line; // Remaining part is the department
    }
}

// Implement the equality operator
bool Instructor::operator==(const Instructor &other) const
{
    return Person::operator==(other) &&
           employeeID == other.employeeID &&
           department == other.department;
}

// Implement the stream insertion operator
ostream &operator<<(ostream &os, const Instructor &instructor)
{
    os << static_cast<const Person &>(instructor)
       << ", Employee ID: " << instructor.employeeID
       << ", Department: " << instructor.department;
    return os;
}

// Implement the stream extraction operator
istream &operator>>(istream &is, Instructor &instructor)
{
    is >> static_cast<Person &>(instructor) >> instructor.employeeID >> instructor.department;
    return is;
}

