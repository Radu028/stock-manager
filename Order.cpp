#include "Order.h"

#include <iostream>

int Order::nextId = 1;

std::ostream& operator<<(std::ostream& os, const Order& order)
{
    os << "Order ID: " << order.id << ", Placed on: " << order.orderDate
       << ", Total price: " << order.totalPrice << ", Place: " << order.place << ", Order: ";

    for (std::map<Product, int>::const_iterator it = order.order.begin(); it != order.order.end();
         ++it)
    {
        const Product& product = it->first;
        const int quantity = it->second;

        os << "    Product: " << product.getName() << ", Price: ", product.getPrice();
    }
}