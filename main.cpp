#include <iostream>
#include <map>
#include <vector>

#include "Order.h"
#include "Product.cpp"
#include "Product.h"
#include "Stock.cpp"
#include "Stock.h"

int main()
{
    Product apple("Apple", 2.5);
    Product banana("Banana", 4);
    Product orange("Orange", 5.5);

    std::cout << apple << std::endl;
    std::cout << banana << std::endl;
    std::cout << orange << std::endl;

    // Create a map for each stock
    std::map<Product, int> depositProducts;
    depositProducts[apple] = 200;
    depositProducts[banana] = 100;
    depositProducts[orange] = 150;

    std::map<Product, int> warehouseProducts;
    warehouseProducts[apple] = 100;
    warehouseProducts[banana] = 50;
    warehouseProducts[orange] = 75;

    std::map<Product, int> shopProducts;
    shopProducts[apple] = 50;
    shopProducts[banana] = 25;
    shopProducts[orange] = 30;

    // Create stocks
    Stock deposit("Deposit", depositProducts);
    Stock warehouse("Warehouse", warehouseProducts);
    Stock shop("Shop", shopProducts);

    // Create maps for orders
    std::map<Product, int> order1Products;
    order1Products[apple] = 10;
    order1Products[banana] = 5;
    order1Products[orange] = 8;

    std::map<Product, int> order2Products;
    order2Products[apple] = 20;
    order2Products[banana] = 10;
    order2Products[orange] = 15;

    std::map<Product, int> order3Products;
    order3Products[apple] = 15;
    order3Products[banana] = 7;
    order3Products[orange] = 12;

    // Create orders
    std::vector<Order> orders;
    orders.push_back(Order(1, order1Products, "2024-03-20", "Store 1"));
    orders.push_back(Order(2, order2Products, "2024-03-20", "Store 2"));
    orders.push_back(Order(3, order3Products, "2024-03-20", "Store 3"));

    std::vector<Stock> stocks;
    stocks.push_back(deposit);
    stocks.push_back(warehouse);
    stocks.push_back(shop);

    return 0;
}