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

#include <iostream>
#include <map>
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

    static int nextId;

   public:
    Stock(const std::string name, const std::map<Product, int>& products)
    {
        this->id = nextId++;
        this->name = name;
        this->products = products;
    }

    void addProducts(const std::map<Product, int> products)
    {
        for (std::map<Product, int>::const_iterator it = products.begin(); it != products.end();
             ++it)
        {
            const Product& product = it->first;
            int quantity = it->second;

            this->products[product] += quantity;
        }
    }

    bool removeProducts(const std::map<Product, int>& productsToRemove)
    {
        for (std::map<Product, int>::const_iterator it = productsToRemove.begin();
             it != productsToRemove.end(); ++it)
        {
            const Product& removedProduct = it->first;
            int quantityToRemove = it->second;

            std::map<Product, int>::const_iterator productIt = this->products.find(removedProduct);
            if (productIt != this->products.end())
            {
                int availableQuantity = productIt->second;

                if (availableQuantity < quantityToRemove)
                {
                    return false;
                }
            }
        }

        for (std::map<Product, int>::const_iterator it = productsToRemove.begin();
             it != productsToRemove.end(); ++it)
        {
            const Product& removedProduct = it->first;
            int quantityToRemove = it->second;

            if (this->products[removedProduct] > 0)
            {
                this->products[removedProduct] -= quantityToRemove;
            }
            else
            {
                std::map<Product, int>::iterator removedProductIt =
                    this->products.find(removedProduct);
                this->products.erase(removedProductIt);
            }
        }

        return true;
    }
};
