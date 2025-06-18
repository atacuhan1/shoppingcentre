#include "Business.h"
#include "Employee.h"
#include <cstring>
#include <iostream>

using namespace std;

Business::Business() {
    business_name = new char [100];
    strcpy(business_name,"Undefined");
    size = -1;
    numberOfEmployees = 0;
}

Business::Business(const char * businessName,int bsize) {
    business_name = new char [100];
    strcpy(business_name,businessName);
    size = bsize;
    numberOfEmployees = 0;
}

Business::Business(const Business& bus) {
    business_name = new char[100];
    strcpy(business_name, bus.business_name);
    size = bus.size;
    numberOfEmployees = bus.numberOfEmployees;

    for (int i = 0; i < numberOfEmployees; i++) { // copies array of employees.
        employees[i] = bus.employees[i];
    }
}

Business& Business::operator=(const Business& bus) {
    if (this != &bus) {
        delete[] business_name;
        business_name = new char[100];
        strcpy(business_name, bus.business_name);
        size = bus.size;
        numberOfEmployees = bus.numberOfEmployees;

        for (int i = 0; i < numberOfEmployees; i++) {
            employees[i] = bus.employees[i];
        }
    }
    return *this;
}

Business::~Business() {
    delete[] business_name;
}

void Business::setBusinessName(const char * name) {
    delete[] business_name;
    business_name = new char[100];
    strcpy(business_name, name);
}

void Business::setSize(int s) {
    size = s;
}

const char * Business::getBusinessName() const{
    return business_name;
}

int Business::getSize() const{
    return size;
}

int Business::getNumOfEmployees() const{
    return numberOfEmployees;
}

void Business::addEmployee(const Employee& e) {
    if (numberOfEmployees < 20) {
        employees[numberOfEmployees] = e;
        numberOfEmployees++;
    } else {
        cout << "Cannot add more employees." << endl;
    }
}

void Business::printBusinessEmployees() const {
    cout << business_name << " | Size: " << size << " m2 | Employees: " << numberOfEmployees << endl;
    if (numberOfEmployees == 0) {
        cout << "No employees" << endl;
    } else {
        for (int i = 0; i < numberOfEmployees ; i++) {
            cout << " ";
            employees[i].printEmployee();
        }
    }
}

void Business::printBusiness() const {
    cout << business_name << " | Size: " << size << " m2 | Employees: " << numberOfEmployees << endl;
}


void Business::searchByName(const char * keyword) const {
    for (int i = 0; i < numberOfEmployees ; i++) {
        if (employees[i].checkName(keyword)) {
            cout << business_name << " | ";
            employees[i].printEmployee();
        }
    }
}

int Business::getType() const {
    return -1;
}





