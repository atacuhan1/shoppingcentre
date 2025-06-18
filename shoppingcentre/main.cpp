#include <iostream>
#include "Business.h"
#include "Employee.h"
#include "Restaurant.h"
#include "Shop.h"
#include "ShoppingCentre.h"
using namespace std;

int main() {
    cout << "Welcome to Kalkanli Shopping Centre Management System!\n" << endl;
    ShoppingCentre centre("Kalkanli Shopping Centre");
    int option = 0;

    cout << "Menu: \n"
        << "1. Add a new business to the shopping centre. \n"
        << "2. Add an employee to a business \n"
        << "3. Print all the businesses in the shopping centre with the number of employees in each business.\n"
        << "4. Print all the businesses in the shopping centre with the details of employees in each business. \n"
        << "5. Print the count of each type of shop in the shopping centre \n"
        << "6. Print the details of the shops whose type is a given type (1: Clothing, 2: Technology, 3: Accessories, 4: Beauty). \n"
        << "7. Print the suitable restaurants based on a given required number of seats. \n"
        << "8. Search for employees by name. \n"
        <<  "9. Print the largest business in terms of size in the shopping centre. \n"
        << "10. Exit\n";

    do {
        cout << "--------------------------------------------------\n"
        << "Please select an option: ";
        cin >> option;
        cout << "\n";

        switch (option) {
            case 1: {
                int type;
                char name[100];
                int size;
                int seats;
                cout << "Enter business type (0: Restaurant, 1: Clothing, 2: Technology, 3: Accessories, 4: Beauty):";
                cin >> type;
                cin.ignore(); // \n clears for next input

                cout << "Enter business name: ";
                cin.getline(name,100);

                cout << "Enter business size (m2): ";
                cin >> size;

                Business * b;

                if (type == 0) {
                    cout << "Enter number of seats: ";
                    cin >> seats;
                    b = new Restaurant(name,size,seats);
                } else if (type >= 1 && type <= 4) {
                    b = new Shop(name,size,shopType(type));
                } else {
                    cout << "Wrong type input !" << endl;
                }

                if (b) {
                    centre.addBusiness(b);
                    cout << "Business \"" << name << "\" added.\n" << endl;
                }
                break;
            }


            case 2: {
                char target[100],fname[100],lname[100];
                int ssn;
                cin.ignore();
                cout << "Enter target business name: ";
                cin.getline(target,100);
                cout << "Enter employee first name: ";
                cin.getline(fname,100);
                cout << "Enter employee last name: ";
                cin.getline(lname,100);
                cout << "Enter SSN: ";
                cin >> ssn;

                Employee* emp = new Employee(fname, lname);
                emp->setSSN(ssn);
                centre.addEmployeeToBusiness(target, emp);
                cin.ignore();
                break;
            }

            case 3: {
                centre.printBusinesses();
                break;
            }

            case 4: {
                centre.printBusinessesEmployees();
                break;
            }
            case 5: {
                centre.printShopsStatistics();
                break;
        }
            case 6: {
                int shopType;
                cout << "Enter shop type to print details (1: Clothing, 2: Technology, 3: Accessories, 4: Beauty): ";
                cin >> shopType;

                while (shopType <= 0 || shopType > 4) {
                    cout << "Invalid shop type selection !!\n";
                    cout << "Enter shop type to print details (1: Clothing, 2: Technology, 3: Accessories, 4: Beauty): ";
                    cin >> shopType;
                }

                centre.printShopsByType(shopType);
                break;
            }

            case 7: {
                int requiredSeats;
                cout << "Enter required number of seats: ";
                cin >> requiredSeats;
                centre.printSuitableRestaurants(requiredSeats);
                break;
            }


            case 8: {
                char keyword[100];
                cin.ignore();
                cout << "Enter search keyword for employee name: ";
                cin.getline(keyword, 100);
                centre.searchByEmployeeName(keyword);
                break;
            }


            case 9: {
                centre.printLargestBusiness();
                break;
            }

            case 10:
                cout << "BYE!!!\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (option != 10);

}