#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include <clothing.h>

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand)
	:Product(category, name, price, qty),
    size_(size),
	brand_(brand)
{
	
}