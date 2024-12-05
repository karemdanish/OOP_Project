#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "person.h"
#include <vector>
#include <string>
#include "notifications.h"
using namespace std;

// Derived Class
// The Instructor class inherits from the Person class, adding specific attributes and methods
// related to instructors in the system.
class Instructor : public Person {
private:
    string employeeID;               // Unique identifier for the instructor
    string department;                // Department of the instructor
    vector<string> assignedCourses;   // List of courses assigned to the instructor

public:
    // Constructor
    Instructor(const string& name, const string& ID, const string& email, const string& employeeID, const string& department);

    // Override displayInfo
    // This method displays the instructor's information, including their name, ID, email, employee ID, and department.
    void displayInfo() const;

    // Override getRole
    // This method returns the role of the instructor in the system.
    string getRole() const;

    // Override sendNotification
    // This method sends a notification message to the instructor.
    void sendNotification(const string& message) const override;

    // Equality operator
    // This operator checks if two Instructor objects are equal based on their attributes.
    // Parameters:
    //   const Instructor& other: The Instructor object to compare with.
    // Returns:
    //   true if the instructors are equal, false otherwise.
    bool operator==(const Instructor& other) const;

    // Stream insertion operator
    // This operator outputs the details of the instructor to the provided output stream.
    // Parameters:
    //   ostream& os: The output stream to write to.
    //   const Instructor& instructor: The Instructor object to output.
    // Returns:
    //   The output stream after writing the instructor details.
    friend ostream& operator<<(ostream& os, const Instructor& instructor);

    // Stream extraction operator
    // This operator reads instructor details from the input stream into the Instructor object.
    // Parameters:
    //   istream& is: The input stream to read from.
    //   Instructor& instructor: The Instructor object to populate.
    // Returns:
    //   The input stream after reading the instructor details.
    friend istream& operator>>(istream& is, Instructor& instructor);

    void createAssignment(const string& assignment);
    void gradeSubmission(const string& submission);
    void monitorStudentProgress() const;
    void issueCertification(const string& studentID);
    void receiveNotification(const Notification& notification);

    virtual ~Instructor() {} // Virtual destructor
};

#endif //INSTRUCTOR_H
