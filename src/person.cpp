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