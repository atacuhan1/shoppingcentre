#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstring>
using namespace std;

class Employee {

private:
    char* firstName;
    char* lastName;
    int SSN;

public:
    Employee();
    Employee(const char*,const char*);
    Employee(const Employee &emp); // copy const
    Employee& operator = (const Employee& other);
    ~Employee();

    void setSSN(int); // Setter funcs
    void setFirstname(const char*);
    void setLastname(const char*);

    const char * getFirstname() const; // Getter funcs
    const char * getLastname() const;

    void printEmployee() const;
    bool checkName(const char *) const;



};

#endif //EMPLOYEE_H
