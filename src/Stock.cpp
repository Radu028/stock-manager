#include "Stock.h"

#include <iostream>
#include <utility>

#include "Product.h"

int Stock::nextId = 1;

std::ostream& operator<<(std::ostream& os, const Stock& stock)
{
    os << "Stock: " << stock.name;
    for (std::map<Product, int>::const_iterator it = stock.products.begin();
         it != stock.products.end(); ++it)
    {
        const Product& product = it->first;
        const int quantity = it->second;

        os << std::endl
           << "  Product: " << product.getName() << ", Price: " << product.getPrice()
           << ", Quantity: " << quantity;
    }

    return os;
}