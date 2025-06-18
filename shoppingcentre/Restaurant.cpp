#include "Restaurant.h"

#include "Shop.h"

Restaurant::Restaurant() : Business() {
    numOfSeats = 0;
}

Restaurant::Restaurant(const char *name, int size, int seats) : Business(name,size) {
    numOfSeats = seats;
}

Restaurant::Restaurant(const Restaurant& restaurant)
    : Business(restaurant) {
    numOfSeats = restaurant.numOfSeats;
}

Restaurant& Restaurant::operator=(const Restaurant& restaurant) {
    if (this != &restaurant) {
        Business::operator=(restaurant);
        numOfSeats = restaurant.numOfSeats;
    }
    return *this;
}

int Restaurant::getnumOfSeats() const {
    return numOfSeats;
}

void Restaurant::setNumOfSeats(int seats) {
    numOfSeats = seats;
}

bool Restaurant::checkSuitability(int requiredSeats) const {
    return numOfSeats >= requiredSeats;
}

void Restaurant::printBusiness() const {
    cout << "Restaurant | " << business_name
         << " | Size: " << size << " m2"
         << " | Seats: " << numOfSeats
         << " | Employees: " << numberOfEmployees
         << endl;
}

void Restaurant::printBusinessEmployees() const {
    cout << business_name
         << " | Size: " << size << " m2"
         << " | Seats: " << numOfSeats
         << " | Employees:" << endl;

    if (numberOfEmployees == 0) {
        cout << "No Employees" << endl;
    } else {
        for (int i = 0; i < numberOfEmployees; i++) {
            cout << "  ";
            employees[i].printEmployee();
        }
    }
}

int Restaurant::getType() const {
    return 0;  // Restaurant type
}



