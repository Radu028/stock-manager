#ifndef PRODUCT_H
#define PRODUCT_H

#include <cstring>
#include <iostream>

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

    void updatePrice(const float newPrice) { this->price = newPrice; }

    void addStock(const int quantity) { this->quantity += quantity; }

    void substractStock(const int quantity)
    {
        if (this->quantity < quantity)
        {
            std::cout << "Not enough stock to subtract." << std::endl;
            return;
        }

        this->quantity -= quantity;
    }

    bool isAvalible(const int quantity) { return this->quantity >= quantity; }

    float getPrice() const { return this->price; }
};

#endif