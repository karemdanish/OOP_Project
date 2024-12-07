#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include <vector>
#include <string>
using namespace std;

// Derived Class
// The Admin class inherits from the Person class, adding specific attributes and methods
// related to administrators in the system.
class Admin : public Person { // Public inheritance
private:
    string adminID;               // Unique identifier for the admin
    vector<string> privileges;     // List of privileges
    string department;             // Department of the admin

public:
    // Constructor
    Admin(const string& name, const string& ID, const string& email, const string& adminID, const vector<string>& privileges, const string& department);

    ~Admin();
    
    // Override displayInfo
    // This method displays the admin's information, including their name, ID, email, admin ID, and department.
    void displayInfo() const;

    // Override getRole
    // This method returns the role of the admin in the system.
    string getRole() const;

    // Override sendNotification
    // This method sends a notification message to the admin.
    void sendNotification(const string& message) const;

    // Additional functions
    void addCourse(const string& course); // Add a course to the system
    void removeCourse(const string& course); // Remove a course from the system
    void assignInstructor(const string& instructor); // Assign an instructor to a course
    void generateReports() const; // Generate reports for the admin
    void manageCertificates() const; // Manage certificates issued by the admin

    // Assignment operator
    // This operator allows for the assignment of one Admin object to another.
    // It performs a deep copy of the admin ID, privileges, and department.
    // Parameters:
    //   const Admin& other: The Admin object to be copied from.
    // Returns:
    //   A reference to the current Admin object.
    Admin& operator=(const Admin& other);

    // Equality operator
    // This operator checks if two Admin objects are equal based on their attributes.
    // Parameters:
    //   const Admin& other: The Admin object to compare with.
    // Returns:
    //   true if the admins are equal, false otherwise.
    bool operator==(const Admin& other) const;

    // Stream insertion operator
    // This operator outputs the details of the admin to the provided output stream.
    // Parameters:
    //   ostream& os: The output stream to write to.
    //   const Admin& admin: The Admin object to output.
    // Returns:
    //   The output stream after writing the admin details.
    friend ostream& operator<<(ostream& os, const Admin& admin);

    // Stream extraction operator
    // This operator reads admin details from the input stream into the Admin object.
    // Parameters:
    //   istream& is: The input stream to read from.
    //   Admin& admin: The Admin object to populate.
    // Returns:
    //   The input stream after reading the admin details.
    friend istream& operator>>(istream& is, Admin& admin);

    // virtual ~Admin() {} // Virtual destructor
};

#endif // ADMIN_H
