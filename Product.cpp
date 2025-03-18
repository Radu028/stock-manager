/**
 * This file contains the implementation of the stream output operator
 * for the Product class, which allows products to be printed to output streams
 * in a human-readable format.
 *
 * The output format is: "Product: [name], Price: [price]"
 */

#include "Product.h"

#include <iostream>

int Product::nextId = 1;

std::ostream& operator<<(std::ostream& os, const Product& product)
{
    os << "Product: " << product.name << ", Price: " << product.price;
    return os;
}