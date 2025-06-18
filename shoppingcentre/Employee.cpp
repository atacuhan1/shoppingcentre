#include <iostream>
#include <cstring>
#include "Employee.h"

Employee::Employee() {
    firstName = new char[100];
    lastName = new char[100];
    strcpy(firstName,"Undefined");
    strcpy(lastName,"Undefined");
    SSN = -1;
}

Employee::Employee(const char * firstname, const char * lastname) {
    firstName = new char[100];
    lastName = new char[100];
    strcpy(firstName,firstname);
    strcpy(lastName,lastname);
    SSN = -1;
}

Employee::Employee(const Employee &emp) {
    SSN = emp.SSN;
    firstName = new char[100];
    lastName = new char[100];
    strcpy(firstName,emp.firstName);
    strcpy(lastName,emp.lastName);
}

Employee & Employee::operator=(const Employee& emp) {
    if (this!=&emp) {
        delete[] firstName;
        delete[] lastName;

        firstName = new char[100];
        strcpy(firstName,emp.firstName);

        lastName = new char[100];
        strcpy(lastName,emp.lastName);

        SSN = emp.SSN;
    }
    return *this;
}

Employee::~Employee() {
    delete[] firstName;
    delete[] lastName;
}


void Employee::setSSN(int ssn) {
    SSN = ssn;
}

void Employee::setFirstname(const char * firstname) {
    delete[] firstName;
    firstName = new char[100];
    strcpy(firstName,firstname);
}

void Employee::setLastname(const char * lastname) {
    delete[] lastName;
    lastName = new char[100];
    strcpy(lastName,lastname);
}

const char *Employee::getFirstname() const{
    return firstName;
}

const char *Employee::getLastname() const {
    return lastName;
}

void Employee::printEmployee() const{
    cout << firstName << " " << lastName  << " | SSN: " << SSN << endl;
}

bool Employee::checkName(const char *keyword) const {

    if (strstr(firstName,keyword) || strstr(lastName,keyword)){ // checks if the keyword in the firstname or lastname
    return true;
}
    return false;
}






