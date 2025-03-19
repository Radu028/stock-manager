/**
 * This class represents a stock/inventory system that:
 * - Maintains a collection of products and their quantities
 * - Allows adding new products to the stock
 * - Handles product removal with quantity validation
 * - Uses a map to store product-quantity pairs
 *
 * The class provides methods to:
 * - Add products to the stock
 * - Remove products from the stock (with quantity validation)
 * - Track product quantities
 *
 * The stock is implemented using std::map<Product, int> where:
 * - Product is the key (unique identifier)
 * - int represents the quantity of each product
 */

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "Product.h"

class Stock
{
   private:
    int id;
    std::string name;
    std::map<Product, int> products;

    inline static int nextId = 0;  // Inline static member initialization

    friend std::ostream& operator<<(std::ostream& os, const Stock& stock);

   public:
    explicit Stock(const std::string& name, const std::map<Product, int>& products)
        : id(nextId++), name(name), products(products)
    {
    }

    // Copy constructor and assignment operator
    Stock(const Stock&) = default;
    Stock& operator=(const Stock&) = default;

    // Move constructor and assignment operator
    Stock(Stock&&) noexcept = default;
    Stock& operator=(Stock&&) noexcept = default;

    void addProducts(const std::map<Product, int>& productsToAdd)
    {
        for (const auto& [product, quantity] : productsToAdd)
        {
            if (products.find(product) != products.end())
            {
                products[product] += quantity;
            }
            else
            {
                products[product] = quantity;
            }
        }
    }

    bool removeProducts(const std::map<Product, int>& productsToRemove)
    {
        // First check if we have enough of each product
        for (const auto& [product, quantity] : productsToRemove)
        {
            if (products.find(product) == products.end() || products[product] < quantity)
            {
                return false;  // Not enough of this product
            }
        }

        // If we have enough, remove the products
        for (const auto& [product, quantity] : productsToRemove)
        {
            products[product] -= quantity;

            // Remove product from map if quantity becomes zero
            if (products[product] == 0)
            {
                products.erase(product);
            }
        }
        return true;
    }

    const std::map<Product, int>& getProducts() const { return products; }
    std::string getName() const { return name; }
    int getId() const { return id; }
};

// Stream insertion operator for Stock
inline std::ostream& operator<<(std::ostream& os, const Stock& stock)
{
    os << "Stock: " << stock.name << std::endl;
    for (const auto& [product, quantity] : stock.products)
    {
        os << "  " << product << ", Quantity: " << quantity << std::endl;
    }
    return os;
}

#endif  // STOCK_H
