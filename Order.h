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

    void calculateTotalPrice()
    {
        float totalPrice = 0;
        for (const auto& item : this->order)
        {
            const Product& product = item.first;
            const int quantity = item.second;

            totalPrice += product.getPrice() * quantity;
        }

        this->totalPrice = totalPrice;
    }

   public:
    Order(const int id, const std::map<Product, int>& products, const std::string orderDate)
    {
        this->id = id;
        this->order = products;
        this->orderDate = orderDate;

        calculateTotalPrice();
    }

    Order(const Order& other)
    {
        this->id = other.id;
        this->order = other.order;
        this->orderDate = other.orderDate;
        this->totalPrice = other.totalPrice;
    }

    Order& operator=(const Order& other)
    {
        if (this == &other)
        {
            return *this;
        }

        this->id = other.id;
        this->order = other.order;
        this->orderDate = other.orderDate;
        this->totalPrice = other.totalPrice;

        return *this;
    }

    void addProduct(const std::map<Product, int>& products)
    {
        for (const auto& item : products)
        {
            const Product& product = item.first;
            int quantity = item.second;

            this->order[product] += quantity;
        }

        calculateTotalPrice();
    }

    void process(Stock& stock) {}
};