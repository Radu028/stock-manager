#include "Product.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Product& product)
{
    os << "Product: " << product.name << ", Price: " << product.price;
    return os;
}