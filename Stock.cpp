#include "Stock.h"

#include <iostream>

int Stock::nextId = 1;

std::ostream& operator<<(std::ostream& os, const Stock& stock) { os << "Stock: " << stock.name; }