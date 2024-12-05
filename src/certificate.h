#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include <string>
using namespace std;

// Forward declarations
class Course;
class Student;

// Certificate Class
class Certificate {
private:
    string certificateID; // Unique identifier for the certificate
    string issueDate;     // Date the certificate was issued
    string courseTitle;   // Title of the course
    string recipient;     // Name of the recipient

    Course* course;       // Association with Course
    Student* student;     // Association with Student

public:
    // Constructor
    Certificate(const string& certID, const string& date, const string& title, const string& recipient, Course* course, Student* student);

    // Method to display certificate information
    void displayCertificateInfo() const; // Display the details of the certificate

    // Assignment operator
    // This operator allows for the assignment of one Certificate object to another.
    // It performs a deep copy of the certificate ID, issue date, course title, recipient, course, and student.
    // Parameters:
    //   const Certificate& other: The Certificate object to be copied from.
    // Returns:
    //   A reference to the current Certificate object.
    Certificate& operator=(const Certificate& other);

    // Equality operator
    // This operator checks if two Certificate objects are equal based on their ID, issue date, course title, and recipient.
    // Parameters:
    //   const Certificate& other: The Certificate object to compare with.
    // Returns:
    //   true if the certificates are equal, false otherwise.
    bool operator==(const Certificate& other) const;

    // Stream insertion operator
    // This operator outputs the details of the certificate to the provided output stream.
    // Parameters:
    //   ostream& os: The output stream to write to.
    //   const Certificate& certificate: The Certificate object to output.
    // Returns:
    //   The output stream after writing the certificate details.
    friend ostream& operator<<(ostream& os, const Certificate& certificate);

    // Stream extraction operator
    // This operator reads certificate details from the input stream into the Certificate object.
    // Parameters:
    //   istream& is: The input stream to read from.
    //   Certificate& certificate: The Certificate object to populate.
    // Returns:
    //   The input stream after reading the certificate details.
    friend istream& operator>>(istream& is, Certificate& certificate);
};

#endif //CERTIFICATE_H
