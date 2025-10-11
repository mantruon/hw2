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
	~Book();
	// want to use parsing functions we wrote to return a set of keywords
	std::set<std::string> keywords() const;
	// display string has specific format in codio
	std::string displayString() const;
	// dump product info
	void dump(std::ostream& os) const;
	std::string getAuthor() const;
	std::string getISBN() const;
private:
	std::string author_;
	std::string ISBN_;
	std::set<std::string> keywords_;
};

#endif