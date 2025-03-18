/**
 * This class manages customer orders with the following features:
 * - Tracks order details (ID, date, place)
 * - Maintains a list of products and their quantities
 * - Calculates total order price
 * - Handles order processing against available stock
 *
 * The class provides:
 * - Constructors for creating new orders
 * - Copy constructor and assignment operator
 * - Methods to add products to the order
 * - Order processing functionality
 * - Automatic total price calculation
 *
 * The order is implemented using std::map<Product, int> where:
 * - Product is the key (unique identifier)
 * - int represents the quantity ordered
 */

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