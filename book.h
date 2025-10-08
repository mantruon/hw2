#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include <product.h>

class Book : public Product {
public:
	Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN);
private:
	std::string author_;
	std::string ISBN_;
};

#endif