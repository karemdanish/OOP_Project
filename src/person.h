#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

// Abstract Base Class
class Person
{
protected:
    string name;
    string ID;
    string email;

public:
    // Constructor
    Person(const string &name, const string &ID, const string &email);

    // Copy constructor
    Person(const Person &other);

    // Virtual Destructor
    virtual ~Person();

    // Pure virtual functions (to be implemented by derived classes)
    virtual void displayInfo() const = 0;
    virtual string getRole() const = 0;
    virtual void sendNotification(const string &message) const = 0;

    // Getters
    string getName() const;
    string getID() const;
    string getEmail() const;

    // Operator Overloading
    // Equality operator
    bool operator==(const Person &other) const;

    // Assignment operator
    Person &operator=(const Person &other);

    // Stream insertion operator
    friend ostream &operator<<(ostream &os, const Person &person);

    // Stream extraction operator
    friend istream &operator>>(istream &is, Person &person);
};

#endif // PERSON_H