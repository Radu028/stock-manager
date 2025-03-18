// Explicatii

#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "Product.h"

class Order
{
   private:
    int id;
    std::map<Product, int> order;
    std::string orderDate;
    float totalPrice;
    std::string place;

    void calculateTotalPrice()
    {
        float totalPrice = 0;
        for (std::map<Product, int>::const_iterator it = this->order.begin();
             it != this->order.end(); ++it)
        {
            const Product& product = it->first;
            const int quantity = it->second;

            totalPrice += product.getPrice() * quantity;
        }

        this->totalPrice = totalPrice;
    }

   public:
    Order(const int id, const std::map<Product, int>& products, const std::string orderDate,
          const std::string place)
    {
        this->id = id;
        this->order = products;
        this->orderDate = orderDate;
        this->place = place;

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
        for (std::map<Product, int>::const_iterator it = products.begin(); it != this->order.end();
             ++it)
        {
            const Product& product = it->first;
            int quantity = it->second;

            this->order[product] += quantity;
        }

        calculateTotalPrice();
    }

    void process(Stock& stock)
    {
        if (stock.removeProducts(this->order))
        {
            std::cout << "The order has been procesed." << std::endl;
        }
        else
        {
            std::cout << "The order has not been procesed." << std::endl;
        }
    }
};