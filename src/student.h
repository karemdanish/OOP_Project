#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <vector>
#include <string>
#include "notifications.h"

class Student : public Person
{
private:
    string studentID;                // Unique identifier for the student
    string enrollmentDate;           // Date the student enrolled
    vector<string> completedCourses; // List of courses completed by the student

public:
    // Constructor
    Student(const string &name, const string &ID, const string &email,
            const string &studentID, const string &enrollmentDate);

    // Copy constructor
    Student(const Student &other);

    // Destructor
    virtual ~Student() override;

    // Override pure virtual functions from Person
    void displayInfo() const override;
    string getRole() const override;
    void sendNotification(const string &message) const override;

    // Other methods remain the same as in previous implementation
    void enrollInCourse(const string &course);
    void submitAssignment(const string &assignment);
    void checkProgress() const;
    void viewCertifications() const;
    void receiveNotification(const Notification &notification);

    // Operator overloads remain the same
    bool operator==(const Student &other) const;
    friend ostream &operator<<(ostream &os, const Student &student);
    friend istream &operator>>(istream &is, Student &student);
    string &operator[](int index);
    Student &operator+(const string &course);
    Student &operator-(const string &course);
    vector<string> operator|(const Student &other) const;
    vector<string> operator&(const Student &other) const;
};

#endif // STUDENT_H