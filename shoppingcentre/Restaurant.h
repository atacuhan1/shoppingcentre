#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include "Business.h"
using namespace std;

class Restaurant : public Business{
private:
    int numOfSeats;

public:
    Restaurant();
    Restaurant(const char* name, int size, int seats);
    Restaurant(const Restaurant& restaurant);
    Restaurant& operator=(const Restaurant& restaurant);

    int getnumOfSeats() const;
    void setNumOfSeats(int);

    bool checkSuitability(int)const override;
    void printBusiness()const override;
    void printBusinessEmployees()const override;
    int getType() const override;


};



#endif //RESTAURANT_H
