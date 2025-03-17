#include <iostream>
#include <map>
#include <string>

#include "Product.h"

class Order
{
   private:
    int id;
    std::map<Product, int> order;
    std::string orderDate;
    float totalPrice;

   public:
};