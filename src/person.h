#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

// Abstract Base Class
class Person {
// Protected attributes so derived classes can access them but cannot be accessed directly outside the class
protected:
    string name;
    string ID;
    string email;

public:
    // Constructor
    Person(const string& name, const string& ID, const string& email);

    // Virtual Destructor
    virtual ~Person();

    // Pure virtual functions (to be implemented by derived classes)
    virtual void displayInfo() const = 0;
    virtual string getRole() const = 0;
    virtual void sendNotification(const string& message) const = 0;

    // Getters
    string getName() const;
    string getID() const;
    string getEmail() const;

    // Operator Overloading
    bool operator == (const Person& other) const; // Equality operator
};


#endif //PERSON_H
