#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Order.cpp"
#include "Order.h"
#include "Product.cpp"
#include "Product.h"
#include "Stock.cpp"
#include "Stock.h"

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
        if (line.empty() || line[0] == '#')
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
            Product product(name, price);
            products[name] = product;
        }
        else if (type == "STOCK")
        {
            std::string stockName, productName;
            int quantity;
            ss >> stockName >> productName >> quantity;

            // Find the product in our products map
            if (products.find(productName) != products.end())
            {
                stockProducts[stockName][products[productName]] = quantity;
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
    for (const auto& stockEntry : stockProducts)
    {
        Stock stock(stockEntry.first, stockEntry.second);
        stocks.push_back(stock);
    }

    // Display products
    std::cout << "We have the following products: " << std::endl;
    for (const auto& productEntry : products)
    {
        std::cout << productEntry.second << std::endl;
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
    for (const auto& dateEntry : orders)
    {
        std::string date = dateEntry.first;

        for (const auto& storeEntry : dateEntry.second)
        {
            std::string store = storeEntry.first;
            std::map<Product, int> orderProducts;

            for (const auto& productEntry : storeEntry.second)
            {
                std::string productName = productEntry.first;
                int quantity = productEntry.second;

                if (products.find(productName) != products.end())
                {
                    orderProducts[products[productName]] = quantity;
                }
            }

            // Create the order object
            Order order(orderProducts, date, store);
            orderObjects.push_back(order);
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
    Stock* depositStock = nullptr;
    for (auto& stock : stocks)
    {
        if (stock.getName() == "Deposit")
        {
            depositStock = &stock;
            break;
        }
    }

    if (depositStock != nullptr)
    {
        std::cout << "After processing the orders, we have the following stocks: " << std::endl;

        // Process all orders against the deposit stock
        for (auto& order : orderObjects)
        {
            std::cout << "Processing order for " << order.getPlace() << " on "
                      << order.getOrderDate() << ":" << std::endl;
            order.process(*depositStock);
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