#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <cstring>

class Product
{
   private:
    int id;
    char* name;
    float price;
    int quantity;

    friend std::ostream& operator<<(std::ostream& os, const Product& product);

   public:
    // Constructor
    Product(const int id, const char* name, const float price, const int quantity)
    {
        this->id = id;
        this->name = new char[strlen(name) + 1];
        this->price = price;
        this->quantity = quantity;
    }

    // Copy Constructor
    Product(const Product& other)
    {
        this->id = other.id;
        this->name = new char[strlen(other.name) + 1];
        this->price = other.price;
        this->quantity = other.quantity;
    }
};

#endif