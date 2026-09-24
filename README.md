# Shopping Centre

Console management system in C++ for a METU NCC course. It models Kalkanlı Shopping Centre: a centre holds up to 50 businesses, and each business holds up to 20 employees.

`Business` is the base class. `Restaurant` adds a seat count. `Shop` adds a type: clothing, technology, accessories, or beauty.

## Menu

1. Add a restaurant or a shop (name and size in m²; restaurants also take a seat count)
2. Add an employee to a business by name (first name, last name, SSN)
3. List businesses with employee counts
4. List businesses with employee details
5. Count shops by type
6. Print shops of one type
7. Print restaurants with at least a given number of seats
8. Search employees by name
9. Print the largest business by floor area
10. Exit

## Build and run

Sources live in `shoppingcentre/`.

```bash
cd shoppingcentre
g++ *.cpp -o shoppingcentre
./shoppingcentre
```
