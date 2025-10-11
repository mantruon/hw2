#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "book.h"

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string author, string ISBN)
	:Product(category, name, price, qty),
    author_(author),
	ISBN_(ISBN)
{
	
}

set<string> Book::keywords() {
	
}

string Book::displayString(const Book& itself) {
	string displayInfo;
	displayInfo += itself.getName();
	displayInfo += '\nAuthor: ';
	displayInfo += itself.getAuthor() + ' ';
	displayInfo += itself.getISBN() + '\n';
	displayInfo += to_string(itself.getPrice()) + ' ' + to_string(itself.getQty());
	displayInfo += 'left.\n';
	return displayInfo;
}

std::string Book::getAuthor() const{
	return author_;
}

std::string Book::getISBN() const{
	return ISBN_;
}