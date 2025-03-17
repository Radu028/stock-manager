#include <iostream>
#include <map>
#include <string>

#include "Product.h"

class Order
{
   private:
    int id;
    std::map<Product, int> order;
    std::string orderDate;
    float totalPrice;

   public:
    Order(const int id, const std::map<Product, int>& products, const std::string orderDate)
    {
        this->id = id;
        this->order = products;
        this->orderDate = orderDate;

        float totalPrice = 0;
        for(const auto& item : products)
        {
            const Product& product = item.first;
            const int quantity = item.second;

            totalPrice += product.getPrice() * quantity;
        }

        this->totalPrice = totalPrice;
    }

    Order(const Order& other)
    {
        this->id = other.id;
        this->order = other.order;
        this->orderDate = other.orderDate;
        this->totalPrice = other.totalPrice;
    }
};