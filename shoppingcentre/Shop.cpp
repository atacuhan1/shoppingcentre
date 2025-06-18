#include "Shop.h"
#include <iostream>
using namespace std;

Shop::Shop() : Business() {
    type = None;
}

Shop::Shop(const char* name, int size, shopType t)
    : Business(name, size) {
    type = t;
}

Shop::Shop(const Shop& other)
    : Business(other) {
    type = other.type;
}

Shop& Shop::operator=(const Shop& other) {
    if (this != &other) {
        Business::operator=(other);
        type = other.type;
    }
    return *this;
}

Shop::~Shop() {
    cout << "Shop destructor called" << endl;
}

shopType Shop::getShopType() const {
    return type;
}

void Shop::setShopType(shopType newType) {
    type = newType;
}

void Shop::printBusiness() const {
    switch (type) {
        case Clothing :
            cout << "Clothing"; break;
        case Technology :
            cout << "Technology"; break;
        case Accessories :
            cout << "Accessories"; break;
        case Beauty:
            cout << "Beauty"; break;
        default:
            cout << "None"; break;
    }

    cout << " | " << getBusinessName()
        << " | Size: " << getSize() << " m2 " << " | Employees: " << getNumOfEmployees() << endl;

}

void Shop::printBusinessEmployees() const {
    cout << getBusinessName()
         << " | Size: " << getSize() << " m2"
         << " | Type: ";

    switch (type) {
        case Clothing: cout << "Clothing"; break;
        case Technology: cout << "Technology"; break;
        case Accessories: cout << "Accessories"; break;
        case Beauty: cout << "Beauty"; break;
        default: cout << "None"; break;
    }

    cout << " | Employees:" << endl;

    if (getNumOfEmployees() == 0) {
        cout << "  No Employees" << endl;
    } else {
        for (int i = 0; i < getNumOfEmployees(); i++) {
            cout << "  ";
            employees[i].printEmployee();
        }
    }
}

int Shop::getType() const {
    return type;  // returns -1 to 4
}





