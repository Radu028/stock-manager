#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product
{
   private:
    int id;
    std::string name;
    float price;

    friend std::ostream& operator<<(std::ostream& os, const Product& product);

   public:
    // Constructor
    Product(const int id, const std::string name, const float price, const int quantity)
    {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    // Copy Constructor
    Product(const Product& other)
    {
        this->id = other.id;
        this->name = other.name;
        this->price = other.price;
    }

    Product& operator=(const Product& other)
    {
        if (this == &other)
        {
            return *this;
        }

        this->id = other.id;
        this->name = other.name;
        this->price = other.price;

        return *this;
    }

    // For using map. It needs a comparator
    bool operator<(const Product& other) const { return this->id < other.id; }

    void updatePrice(const float newPrice) { this->price = newPrice; }

    float getPrice() const { return this->price; }

    int getId() const { return this->id; }
};

#endif