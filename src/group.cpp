#include "group.h"

// Initialize static members
string Group::groupID = "";
vector<string> Group::members;

void Group::createGroup(const string& id) {
    groupID = id;
    members.clear(); // Clear any existing members
    cout << "Group created with ID: " << groupID << endl;
}

void Group::addMember(const string& member) {
    members.push_back(member);
    cout << member << " has been added to the group." << endl;
}

void Group::removeMember(const string& member) {
    auto it = find(members.begin(), members.end(), member);
    if (it != members.end()) {
        members.erase(it);
        cout << member << " has been removed from the group." << endl;
    } else {
        cout << member << " is not in the group." << endl;
    }
}

void Group::displayGroupInfo() {
    cout << "Group ID: " << groupID << endl;
    cout << "Members: ";
    for (const auto& member : members) {
        cout << member << " ";
    }
    cout << endl;
}
