#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

class Book : public Product {
public:
	Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN);
	// want to use parsing functions we wrote to return a set of keywords
	std::set<std::string> keywords();
	// display string has specific format in codio
private:
	std::string author_;
	std::string ISBN_;
};

#endif