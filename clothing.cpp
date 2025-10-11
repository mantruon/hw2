#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "clothing.h"

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand)
	:Product(category, name, price, qty),
    size_(size),
	brand_(brand)
{
	
}

set<string> Clothing::keywords() {
	keywords_.insert(brand_);
	return keywords_;
}

string Clothing::displayString() {
	string displayInfo;
	displayInfo += name_ + "\nSize: " + size_ + " Brand:" + brand_ + "\n" + to_string(price_) + " " + to_string(qty_) + "left.\n";
	return displayInfo;
}

std::string Clothing::getSize() const{
	return size_;
}

std::string Clothing::getBrand() const{
	return brand_;
}