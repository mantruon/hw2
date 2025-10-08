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

set<string> keywords() {
	
}