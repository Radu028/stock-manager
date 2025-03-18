#include <iostream>
#include <vector>

#include "Order.h"
#include "Product.h"
#include "Stock.h"

int main()
{
    Product apple(1, "Apple", 2.5);
    Product banana(2, "Banana", 4);
    Product orange(3, "Orange", 5.5);

    std::map<Product, int> productsToAdd;
    productsToAdd[apple] = 400;
    productsToAdd[banana] = 200;
    productsToAdd[orange] = 150;

    Stock deposit(1, "Deposit", productsToAdd);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}