#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

class Movie : public Product{
public:
	Movie(const std::string category, const std::string name, double price, int qty, std::string geenre, std::string rating);
	std::set<std::string> keywords();
	// display string has specific format in codio
	std::string displayString();
	// dump product info
	void dump(std::ostream& os);
	std::string getGenre() const;
	std::string getRating() const;
private:
	std::string genre_;
	// rating is like PG or rated R not as in stars
	std::string rating_;		
	std::set<std::string> keywords_;
};

#endif