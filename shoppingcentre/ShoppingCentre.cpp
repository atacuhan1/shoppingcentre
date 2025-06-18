#include "ShoppingCentre.h"
#include <cstring>
#include <iostream>
using namespace std;

ShoppingCentre::ShoppingCentre() {
    name = new char [100];
    strcpy(name,"Undefined");
    numOfBusinesses = 0;
}

ShoppingCentre::ShoppingCentre(const char * centreName) {
    name = new char [100];
    strcpy(name,centreName);
    numOfBusinesses = 0;
}

ShoppingCentre::ShoppingCentre(const ShoppingCentre& s) {
    name = new char[100];
    strcpy(name, s.name);
    numOfBusinesses = s.numOfBusinesses;
    for (int i = 0; i < numOfBusinesses; i++) {
        businesses[i] = s.businesses[i];
    }
}

ShoppingCentre& ShoppingCentre::operator=(const ShoppingCentre& s) {
    if (this != &s) {
        delete[] name;
        name = new char[100];
        strcpy(name, s.name);
        numOfBusinesses = s.numOfBusinesses;
        for (int i = 0; i < numOfBusinesses; i++) {
            businesses[i] = s.businesses[i];
        }
    }
    return *this;
}

ShoppingCentre::~ShoppingCentre() {
    delete[] name;
    for (int i = 0 ; i < numOfBusinesses ; i++) {
        delete[] businesses[i]; // destructs businesses array
    }
}

void ShoppingCentre::setName(const char* newName) {
    delete[] name;
    name = new char[100];
    strcpy(name, newName);
}

const char * ShoppingCentre::getName() const {
    return name;
}

int ShoppingCentre::getNumberOfBusinesses() const{
    return numOfBusinesses;
}

void ShoppingCentre::addBusiness(Business* b) {
    if (numOfBusinesses >= 50) {
        cout << "Business limit reached!" << endl;
        return;
    }
    businesses[numOfBusinesses++] = b;
}

void ShoppingCentre::printBusinesses() const {
    for (int i = 0; i < numOfBusinesses; i++) {
        businesses[i]->printBusiness();
    }
}

void ShoppingCentre::printBusinessesEmployees() const {
    for (int i = 0; i < numOfBusinesses; i++) {
        businesses[i]->printBusinessEmployees();
    }
}

void ShoppingCentre::printShopsStatistics() const {
    int clothing = 0, tech = 0, accessories = 0, beauty = 0;
    for (int i = 0; i < numOfBusinesses; i++) {
        int t = businesses[i]->getType();

        if (t == 1)
            clothing++;
        else if (t == 2)
            tech++;
        else if (t == 3)
            accessories++;
        else if (t == 4)
            beauty++;
    }

    cout << "Clothing Shops: " << clothing << endl;
    cout << "Technology Shops: " << tech << endl;
    cout << "Accessories Shops: " << accessories << endl;
    cout << "Beauty Shops: " << beauty << endl;
}

void ShoppingCentre::printShopsByType(int type) const {
    for (int i = 0; i < numOfBusinesses; i++) {
        if (businesses[i]->getType() == type) {
            businesses[i]->printBusiness();
        }
    }
}

void ShoppingCentre::printSuitableRestaurants(int minSeats) const {
    for (int i = 0; i < numOfBusinesses; i++) {
        if (businesses[i]->getType() == 0 && businesses[i]->checkSuitability(minSeats)) {
            businesses[i]->printBusiness();
        }
        }
}


void ShoppingCentre::searchByEmployeeName(const char* keyword) const {
    for (int i = 0; i < numOfBusinesses; i++) {
        businesses[i]->searchByName(keyword);
    }
}

void ShoppingCentre::printLargestBusiness() const {
    if (numOfBusinesses == 0) {
        cout << "No businesses found." << endl;
        return;
    }

    int index = 0;
    for (int i = 1; i < numOfBusinesses; i++) {
        if (businesses[i]->getSize() > businesses[index]->getSize()) {
            index = i;
        }
    }

    businesses[index]->printBusiness();
}

void ShoppingCentre::addEmployeeToBusiness(const char* target, Employee * emp) {
    for (int i = 0; i < numOfBusinesses; i++) {
        if (strcmp(businesses[i]->getBusinessName(), target) == 0) {
            businesses[i]->addEmployee(*emp);
            cout << "Employee \"" << emp->getFirstname() << " " << emp->getLastname() << "\" added"<<endl;
            return;
        }
    }
    cout << "Business not found.\n";
    delete emp;
}










