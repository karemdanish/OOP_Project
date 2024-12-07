#include "student.h"
#include "notifications.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructor
Student::Student(const string &name, const string &ID, const string &email,
                 const string &studentID, const string &enrollmentDate)
    : Person(name, ID, email), studentID(studentID), enrollmentDate(enrollmentDate) {}

// Copy constructor
Student::Student(const Student &other)
    : Person(other), // Call base class copy constructor
      studentID(other.studentID),
      enrollmentDate(other.enrollmentDate),
      completedCourses(other.completedCourses)
{
}

// Destructor
Student::~Student()
{
    // No dynamic memory to clean up, but keeping it virtual
}

// Override displayInfo with more detailed implementation
void Student::displayInfo() const
{
    // Use base class output and add student-specific details
    cout << "Student Information:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getID() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Enrollment Date: " << enrollmentDate << endl;
}

// Override getRole
string Student::getRole() const
{
    return "Student";
}

// Override sendNotification
void Student::sendNotification(const string &message) const
{
    cout << "Notification for Student " << getName() << ": " << message << endl;
}

// Rest of the implementation remains the same as in previous version
// (enrollInCourse, submitAssignment, checkProgress, etc. methods)
void Student::enrollInCourse(const string &course)
{
    completedCourses.push_back(course);
    cout << getName() << " has enrolled in " << course << endl;
}

void Student::submitAssignment(const string &assignment)
{
    cout << getName() << " has submitted the assignment: " << assignment << endl;
}

void Student::checkProgress() const
{
    cout << getName() << "'s completed courses: ";
    for (const auto &course : completedCourses)
    {
        cout << course << " ";
    }
    cout << endl;
}

void Student::viewCertifications() const
{
    cout << getName() << "'s certifications: [List of certifications]" << endl;
}

void Student::receiveNotification(const Notification &notification)
{
    cout << "Notification received by " << getName() << ": "
         << notification.getMessage() << endl;
}

// Implement the equality operator
bool Student::operator==(const Student &other) const
{
    return Person::operator==(other) &&
           studentID == other.studentID &&
           enrollmentDate == other.enrollmentDate;
}

// Implement the stream insertion operator
ostream &operator<<(ostream &os, const Student &student)
{
    os << static_cast<const Person &>(student)
       << ", Student ID: " << student.studentID
       << ", Enrollment Date: " << student.enrollmentDate;
    return os;
}

// Implement the stream extraction operator
istream &operator>>(istream &is, Student &student)
{
    is >> static_cast<Person &>(student) >> student.studentID >> student.enrollmentDate;
    return is;
}

// Implement the subscript operator
string &Student::operator[](int index)
{
    return completedCourses[index];
}

// Implement the + operator
Student &Student::operator+(const string &course)
{
    completedCourses.push_back(course);
    return *this;
}

// Implement the - operator
Student &Student::operator-(const string &course)
{
    auto it = find(completedCourses.begin(), completedCourses.end(), course);
    if (it != completedCourses.end())
    {
        completedCourses.erase(it);
    }
    return *this;
}

// Implement the | operator for union
vector<string> Student::operator|(const Student &other) const
{
    vector<string> unionCourses = completedCourses;
    for (const auto &course : other.completedCourses)
    {
        if (find(unionCourses.begin(), unionCourses.end(), course) == unionCourses.end())
        {
            unionCourses.push_back(course);
        }
    }
    return unionCourses;
}

// Implement the & operator for intersection
vector<string> Student::operator&(const Student &other) const
{
    vector<string> intersectionCourses;
    for (const auto &course : completedCourses)
    {
        if (find(other.completedCourses.begin(), other.completedCourses.end(), course) != other.completedCourses.end())
        {
            intersectionCourses.push_back(course);
        }
    }
    return intersectionCourses;
}