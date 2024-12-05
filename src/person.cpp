#include "person.h"
#include <iostream>
using namespace std;

// Constructor
Person::Person(const string& name, const string& ID, const string& email)
    : name(name), ID(ID), email(email) {}

// Destructor
Person::~Person() {
    // Virtual destructor for proper clean up of derived objects
}

// Getters
string Person::getName() const {
    return name;
}

string Person::getID() const {
    return ID;
}

string Person::getEmail() const {
    return email;
}

// Operator Overloading
bool Person::operator==(const Person& other) const {
    return (name == other.name && ID == other.ID && email == other.email);
}

// Implement the assignment operator
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        ID = other.ID;
        email = other.email;
    }
    return *this;
}

// Implement the stream insertion operator
ostream& operator<<(ostream& os, const Person& person) {
    os << "Name: " << person.name << ", ID: " << person.ID << ", Email: " << person.email;
    return os;
}

// Implement the stream extraction operator
istream& operator>>(istream& is, Person& person) {
    is >> person.name >> person.ID >> person.email;
    return is;
}