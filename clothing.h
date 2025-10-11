#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

class Clothing : public Product {
public:
	Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
	std::set<std::string> keywords();
	// display string has specific format in codio
	std::string displayString();
	// dump product info
	void dump(std::ostream& os);
	std::string getSize() const;
	std::string getBrand() const;
private:
	std::string size_;
	std::string brand_;
	std::set<std::string> keywords_;
};

#endif