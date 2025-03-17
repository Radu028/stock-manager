#include <iostream>
#include <vector>

#include "Product.h"

class Stock
{
   private:
    std::vector<Product> products;

   public:
    Stock(const std::vector<Product> products) { this->products = products; }

    void addProducts(const std::vector<Product> products)
    {
        for (const Product& product : products)
        {
            this->products.push_back(product);
        }
    }

    void removeProducts(const std::vector<Product> products)
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