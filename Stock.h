#include <iostream>
#include <map>
#include <string>

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

    void removeProducts(const std::vector<Product>& products)
    {
        for (const Product& removedProduct : products)
        {
            auto it = std::remove_if(this->products.begin(), this->products.end(),
                                     [&removedProduct](const Product& product)
                                     { return product.getId() == removedProduct.getId(); });

            this->products.erase(it, this->products.end());
        }
    }
};