/*
 * This class encapsulates the basic properties of a product:
 * - id: unique identifier for the product
 * - name: name of the product
 * - price: current price of the product
 *
 * The class provides:
 * - Constructors for creating new products
 * - Copy constructor and assignment operator for proper object copying
 * - Comparison operator for use in std::map
 * - Methods to update and retrieve product information
 *
 * The class is designed to be used as a key in std::map containers,
 * which is why it implements the less-than operator.
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <compare>  // For three-way comparison operator (spaceship)
#include <iostream>
#include <string>

class Product
{
   private:
    int id;
    std::string name;
    float price;

    inline static int nextId = 0;  // Inline static member initialization (C++17)

    friend std::ostream& operator<<(std::ostream& os, const Product& product);

   public:
    // Default Constructor
    Product() : id(nextId++), name(""), price(0.0f) {}

    // Constructor
    explicit Product(const std::string& name, const float price)
        : id(nextId++), name(name), price(price)
    {
    }

    // Copy Constructor
    Product(const Product& other) = default;  // Use compiler-generated copy constructor

    // Assignment operator
    Product& operator=(const Product& other) =
        default;  // Use compiler-generated assignment operator

    // Move constructor and assignment operator
    Product(Product&& other) noexcept = default;
    Product& operator=(Product&& other) noexcept = default;

    // Compare two products based on ID
    bool operator<(const Product& other) const { return id < other.id; }

    // Explicitly define equality operator
    bool operator==(const Product& other) const { return id == other.id; }

    // Getters with trailing return types
    auto getName() const -> std::string { return this->name; }
    auto getPrice() const -> float { return this->price; }
    auto getId() const -> int { return this->id; }

    // Setters
    void updatePrice(const float newPrice) { this->price = newPrice; }
};

// Stream insertion operator for Product
inline std::ostream& operator<<(std::ostream& os, const Product& product)
{
    os << "Product: " << product.name << ", Price: " << product.price;
    return os;
}

#endif  // PRODUCT_H