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
	
}

string Clothing::displayString(const Clothing& itself) {
	string displayInfo;
	displayInfo += itself.getName();
	displayInfo += '\nSize: ';
	displayInfo += itself.getSize();
	displayInfo += ' Brand:';
	displayInfo += itself.getBrand() + '\n';
	displayInfo += to_string(itself.getPrice()) + ' ' + to_string(itself.getQty());
	displayInfo += 'left.\n';
	return displayInfo;
}

std::string Clothing::getSize() const{
	return size_;
}

std::string Clothing::getBrand() const{
	return brand_;
}