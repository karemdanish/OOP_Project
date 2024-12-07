#include "person.h"
#include <iostream>
using namespace std;

// Constructor
Person::Person(const string &name, const string &ID, const string &email)
    : name(name), ID(ID), email(email) {}

// Copy constructor
Person::Person(const Person &other)
    : name(other.name), ID(other.ID), email(other.email) {}

// Virtual Destructor
Person::~Person() {}

// Getters
string Person::getName() const
{
    return name;
}

string Person::getID() const
{
    return ID;
}

string Person::getEmail() const
{
    return email;
}

// Equality operator
bool Person::operator==(const Person &other) const
{
    return (name == other.name && ID == other.ID && email == other.email);
}

// Assignment operator
Person &Person::operator=(const Person &other)
{
    if (this != &other)
    {
        name = other.name;
        ID = other.ID;
        email = other.email;
    }
    return *this;
}

// Stream insertion operator
ostream &operator<<(ostream &os, const Person &person)
{
    os << "Name: " << person.name << ", ID: " << person.ID << ", Email: " << person.email;
    return os;
}

// Stream extraction operator
istream &operator>>(istream &is, Person &person)
{
    is >> person.name >> person.ID >> person.email;
    return is;
}