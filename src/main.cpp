#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "../include/Order.h"
#include "../include/Product.h"
#include "../include/Stock.h"

int main()
{
    // Maps to store our products, stocks and orders
    std::map<std::string, Product> products;
    std::map<std::string, std::map<Product, int>> stockProducts;
    std::map<std::string, std::map<std::string, std::map<std::string, int>>>
        orders;  // date -> store -> product -> quantity

    // Open the data file
    std::ifstream dataFile("data.txt");

    if (!dataFile.is_open())
    {
        std::cerr << "Error: Could not open data.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(dataFile, line))
    {
        // Skip empty lines and comments
        if (line.empty() || (line.size() > 0 && line[0] == '#'))
        {
            continue;
        }

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "PRODUCT")
        {
            std::string name;
            float price;
            ss >> name >> price;

            // Create product and store in our map
            products.emplace(name, Product{name, price});
        }
        else if (type == "STOCK")
        {
            std::string stockName, productName;
            int quantity;
            ss >> stockName >> productName >> quantity;

            // Find the product in our products map
            if (auto it = products.find(productName); it != products.end())
            {
                stockProducts[stockName][it->second] = quantity;
            }
        }
        else if (type == "ORDER")
        {
            std::string date, store, productName;
            int quantity;
            ss >> date >> store >> productName >> quantity;

            // Store order details grouped by date and store
            orders[date][store][productName] = quantity;
        }
    }

    dataFile.close();

    // Create actual Stock objects from our data
    std::vector<Stock> stocks;
    stocks.reserve(stockProducts.size());

    for (const auto& [stockName, stockItems] : stockProducts)
    {
        stocks.emplace_back(stockName, stockItems);
    }

    // Display products
    std::cout << "We have the following products: " << std::endl;
    for (const auto& [_, product] : products)
    {
        std::cout << product << std::endl;
    }
    std::cout << std::endl;

    // Display stocks
    std::cout << "We have the following stocks: " << std::endl;
    for (const auto& stock : stocks)
    {
        std::cout << stock << std::endl;
    }
    std::cout << std::endl;

    // Create and process orders
    std::vector<Order> orderObjects;

    for (const auto& [date, storeMap] : orders)
    {
        for (const auto& [store, productMap] : storeMap)
        {
            std::map<Product, int> orderProducts;

            for (const auto& [productName, quantity] : productMap)
            {
                if (auto it = products.find(productName); it != products.end())
                {
                    orderProducts[it->second] = quantity;
                }
            }

            // Create the order object
            orderObjects.emplace_back(orderProducts, date, store);
        }
    }

    // Display orders
    std::cout << "And we have the following orders: " << std::endl;
    for (const auto& order : orderObjects)
    {
        std::cout << order << std::endl;
    }
    std::cout << std::endl;

    // Find the deposit stock for processing orders
    auto depositIt = std::find_if(stocks.begin(), stocks.end(),
                                  [](const Stock& stock) { return stock.getName() == "Deposit"; });

    if (depositIt != stocks.end())
    {
        std::cout << "After processing the orders, we have the following stocks: " << std::endl;

        // Process all orders against the deposit stock
        for (auto& order : orderObjects)
        {
            std::cout << "Processing order for " << order.getPlace() << " on "
                      << order.getOrderDate() << ":" << std::endl;
            order.process(*depositIt);
            std::cout << std::endl;
        }

        // Display updated stocks
        for (const auto& stock : stocks)
        {
            std::cout << stock << std::endl;
        }
    }
    else
    {
        std::cout << "Deposit stock not found, cannot process orders." << std::endl;
    }

    return 0;
}