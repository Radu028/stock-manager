#include <iostream>
#include <vector>

#include "Order.h"
#include "Product.h"
#include "Stock.h"

int main()
{
    Product apple("Apple", 2.5);
    Product banana("Banana", 4);
    Product orange("Orange", 5.5);

    Stock deposit("Deposit", {{apple, 200}, {banana, 100}, {orange, 150}});
    Stock warehouse("Warehouse", {{apple, 100}, {banana, 50}, {orange, 75}});
    Stock shop("Shop", {{apple, 50}, {banana, 25}, {orange, 30}});

    std::vector<Order> orders = {
        Order(1, {{apple, 10}, {banana, 5}, {orange, 8}}, "2024-03-20", "Store 1"),
        Order(2, {{apple, 20}, {banana, 10}, {orange, 15}}, "2024-03-20", "Store 2"),
        Order(3, {{apple, 15}, {banana, 7}, {orange, 12}}, "2024-03-20", "Store 3")};

    std::vector<Stock> stocks = {deposit, warehouse, shop};

    std::cout << "Hello, World!" << std::endl;
    return 0;
}