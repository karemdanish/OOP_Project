#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "person.h"
#include <vector>
#include <string>
#include "notifications.h"

class Instructor : public Person
{
private:
    string employeeID;              // Unique identifier for the instructor
    string department;              // Department of the instructor
    vector<string> assignedCourses; // List of courses assigned to the instructor

public:
    // Constructor
    Instructor(const string &name, const string &ID, const string &email,
               const string &employeeID, const string &department);

    // Copy constructor
    Instructor(const Instructor &other);

    // Destructor
    virtual ~Instructor() override;

    // Override pure virtual functions from Person
    void displayInfo() const override;
    string getRole() const override;
    void sendNotification(const string &message) const override;

    // Other methods
    void createAssignment(const string &assignment);
    void gradeSubmission(const string &submission);
    void monitorStudentProgress() const;
    void issueCertification(const string &studentID);
    void receiveNotification(const Notification &notification);

    // Operator overloads
    bool operator==(const Instructor &other) const;
    friend ostream &operator<<(ostream &os, const Instructor &instructor);
    friend istream &operator>>(istream &is, Instructor &instructor);
};

#endif // INSTRUCTOR_H