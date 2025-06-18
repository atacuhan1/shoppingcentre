#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include "Business.h"
using namespace std;

enum shopType {
    None = -1,
    Clothing = 1,
    Technology  = 2,
    Accessories = 3,
    Beauty = 4
};



class Shop : public Business {
private:
    shopType type;
public:
    Shop();
    Shop(const char* name, int size, shopType type);
    Shop(const Shop& other);
    Shop& operator=(const Shop& other);
    ~Shop() override;

    shopType getShopType() const;
    void setShopType(shopType newType);

    void printBusiness() const override;
    void printBusinessEmployees() const override;
    int getType() const override;

};



#endif //SHOP_H
