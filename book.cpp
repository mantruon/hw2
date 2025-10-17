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
	keywords_.insert(author_);
	keywords_.insert(ISBN_);
}

Book::~Book() {

}

set<string> Book::keywords() const {

	return keywords_;
}

string Book::displayString() const {
	string displayInfo;
	displayInfo += name_ + "\nAuthor: " + author_ + " ISBN: " + ISBN_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.\n";
	return displayInfo;
}

void Book::dump(ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << author_ << endl;
}


std::string Book::getAuthor() const{
	return author_;
}

std::string Book::getISBN() const{
	return ISBN_;
}