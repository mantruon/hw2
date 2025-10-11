#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "movie.h"

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating)
	:Product(category, name, price, qty),
    genre_(genre),
	rating_(rating)
{
	
}

set<string> Movie::keywords(){
	keywords_.insert(genre_);
	return keywords_;
}

string Movie::displayString() {
	string displayInfo;
	displayInfo += name_ + "\nGenre: " + genre_ + " Rating:" + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + "left.\n";
	return displayInfo;
}

std::string Movie::getGenre() const{
	return genre_;
}

std::string Movie::getRating() const{
	return rating_;
}