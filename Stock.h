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

   public:
    Stock(const std::map<Product, int>& products) { this->products = products; }

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
                auto it = this->products.find(removedProduct);
                this->products.erase(it);
            }
        }

        return true;
    }
};