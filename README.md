# Inventory Management System

This is a simple inventory management system that tracks products, stocks, and orders. The system allows you to:

- Define products with names and prices
- Track product quantities in different stocks (Deposit, Warehouse, Shop)
- Create and process orders for products
- Monitor stock levels after order processing

## Project Structure

- `Product.h/cpp`: Defines the Product class with name, price, and unique ID
- `Stock.h/cpp`: Manages collections of products and their quantities
- `Order.h/cpp`: Handles customer orders and order processing
- `main.cpp`: Main program that reads data from file and processes it
- `data.txt`: Input file with products, stocks, and orders

## How to Use

1. Define your products, stocks, and orders in the `data.txt` file
2. Compile and run the program

### File Format

The `data.txt` file follows this format:

```
# Products
# Format: PRODUCT_NAME PRICE
PRODUCT Apple 2.5
PRODUCT Banana 4.0

# Stocks
# Format: STOCK STOCK_NAME PRODUCT_NAME QUANTITY
STOCK Deposit Apple 200
STOCK Warehouse Apple 100

# Orders
# Format: ORDER ORDER_DATE STORE_NAME PRODUCT_NAME QUANTITY
ORDER 2024-03-20 Store1 Apple 10
```

## Compiling

To compile the program:

```
g++ -std=c++11 main.cpp -o inventory_system
```

## Running

To run the program:

```
./inventory_system
```

## Features

- Object-oriented design with proper encapsulation
- File-based data input
- Automatic unique ID assignment for products, stocks, and orders
- Stock quantity validation during order processing
- Total price calculation for orders
- Console-based reporting of stock levels and order processing

## Example Output

The program will display:

1. List of all products
2. Current stock levels
3. All orders
4. Updated stock levels after processing orders
