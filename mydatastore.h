#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "datastore.h"

class myDataStore {
public:

protected:
	// make a set of vectors for easy find()
	std::set<User> users_;
	// then make a map of users and a vector containing their products
	// want a vector since we know that duplicate items can exist >> not a set or map
	std::map<User, std::vector<Product>> carts;
	
};

#endif