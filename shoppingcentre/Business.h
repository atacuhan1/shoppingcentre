#ifndef BUSINESS_H
#define BUSINESS_H

#include "Employee.h"

class Business {
protected:
    char * business_name;
    int size;
    Employee employees[20];
    int numberOfEmployees;

public:
    Business();
    Business(const char * ,int);
    Business(const Business & bus);
    Business& operator=(const Business & bus);
    virtual ~Business();

    void setBusinessName(const char *); // Setter functions
    void setSize(int);

    const char * getBusinessName() const; // Getter functions
    int getSize() const;
    int getNumOfEmployees() const;

    virtual void addEmployee(const Employee & e);
    virtual void printBusiness() const;
    virtual void printBusinessEmployees() const;
    virtual int getType() const;

    void searchByName(const char * ) const;
    virtual bool checkSuitability(int) const { return false; } // to use checksuitability in restaurant.h for printsuitable in shoppingcentre.cpp
};



#endif //BUSINESS_H
