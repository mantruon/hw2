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

set<string> Movie::keywords() {
	
}

string Movie::displayString(const Movie& itself) {
	string displayInfo;
	displayInfo += itself.getName();
	displayInfo += '\nGenre: ';
	displayInfo += itself.getGenre();
	displayInfo += ' Rating:';
	displayInfo += itself.getRating() + '\n';
	displayInfo += to_string(itself.getPrice()) + ' ' + to_string(itself.getQty());
	displayInfo += 'left.\n';
	return displayInfo;
}

std::string Movie::getGenre() const{
	return genre_;
}

std::string Movie::getRating() const{
	return rating_;
}