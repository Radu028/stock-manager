#include <iostream>
#include <map>
#include <string>
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
        for (const auto& item : products)
        {
            const Product& product = item.first;
            int quantity = item.second;

            this->products[product] += quantity;
        }
    }

    bool removeProducts(const std::map<Product, int>& productsToRemove)
    {
        for (const auto& item : productsToRemove)
        {
            const Product& removedProduct = item.first;
            int quantityToRemove = item.second;

            auto it = this->products.find(removedProduct);
            if (it != this->products.end())
            {
                int availableQuantity = it->second;

                if (availableQuantity < quantityToRemove)
                {
                    return false;
                }
            }
        }

        for (const auto& item : productsToRemove)
        {
            const Product& removedProduct = item.first;
            int quantityToRemove = item.second;

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