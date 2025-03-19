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

#ifndef ORDER_H
#define ORDER_H

#include <format>  // C++20 formatting
#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "Product.h"
#include "Stock.h"

class Order
{
   private:
    int id;
    std::map<Product, int> order;
    std::string orderDate;
    float totalPrice;
    std::string place;

    inline static int nextId = 0;  // Inline static member initialization

    friend std::ostream& operator<<(std::ostream& os, const Order& order);

    void calculateTotalPrice()
    {
        totalPrice = 0;
        for (const auto& [product, quantity] : order)
        {
            totalPrice += product.getPrice() * quantity;
        }
    }

   public:
    // Constructor
    Order(const std::map<Product, int>& order, const std::string& orderDate,
          const std::string& place)
        : id(nextId++), order(order), orderDate(orderDate), place(place), totalPrice(0)
    {
        calculateTotalPrice();
    }

    // Copy constructor and assignment operator
    Order(const Order&) = default;
    Order& operator=(const Order&) = default;

    // Move constructor and assignment operator
    Order(Order&&) noexcept = default;
    Order& operator=(Order&&) noexcept = default;

    // Getters
    int getId() const { return id; }
    float getTotalPrice() const { return totalPrice; }
    std::string getOrderDate() const { return orderDate; }
    std::string getPlace() const { return place; }
    const std::map<Product, int>& getOrder() const { return order; }

    void addProduct(const std::map<Product, int>& products)
    {
        for (const auto& [product, quantity] : products)
        {
            order[product] += quantity;
        }
        calculateTotalPrice();
    }

    void process(Stock& stock)
    {
        if (stock.removeProducts(order))
        {
            std::cout << "The order has been procesed." << std::endl;
        }
        else
        {
            std::cout << "The order could not be processed. Not enough products in stock."
                      << std::endl;
        }
    }
};

// Stream insertion operator for Order
inline std::ostream& operator<<(std::ostream& os, const Order& order)
{
    os << "Order ID: " << order.id << ", Placed on: " << order.orderDate
       << ", Total price: " << order.totalPrice << ", Place: " << order.place
       << ", Order: " << std::endl;

    for (const auto& [product, quantity] : order.order)
    {
        os << "  " << product << ", Quantity: " << quantity << std::endl;
    }

    return os;
}

#endif  // ORDER_H