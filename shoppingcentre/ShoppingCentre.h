#ifndef SHOPPINGCENTRE_H
#define SHOPPINGCENTRE_H

#include <iostream>
#include <cstring>
#include "Restaurant.h"
#include "Shop.h"
#include "Business.h"
using namespace std;

class ShoppingCentre {
private:
    char * name;
    Business * businesses[50]{};
    int numOfBusinesses;
public:
    ShoppingCentre();
    ShoppingCentre(const char *);
    ShoppingCentre(const ShoppingCentre& s);
    ShoppingCentre& operator=(const ShoppingCentre& s);
    ~ShoppingCentre();

    void setName(const char* name);
    const char* getName() const;
    int getNumberOfBusinesses() const;

    void addBusiness(Business* b);
    void printBusinesses() const;
    void printBusinessesEmployees() const;
    void printShopsStatistics() const;
    void printShopsByType(int type) const;
    void printSuitableRestaurants(int minSeats) const;
    void searchByEmployeeName(const char* keyword) const;
    void printLargestBusiness() const;
    void addEmployeeToBusiness(const char* target, Employee* emp); // an additional function to find the business by the name for adding employee.
};

#endif //SHOPPINGCENTRE_H
