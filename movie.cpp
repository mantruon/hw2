#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include <movie.h>

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating)
	:Product(category, name, price, qty),
    genre_(genre),
	rating_(rating)
{
	
}