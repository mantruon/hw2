#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "datastore.h"

/* Instructions:
It is here that you will implement the core functionality of your program: searching, adding products and users, saving the database, etc.
(For search you can use the setIntersection and setUnion) functions in util.h. This class is likely where you should store products and users in some fashion.
*/
class myDataStore {
public:

protected:
	// make a set of vectors for easy find()
	std::set<User> users_;
	// then make a map of users and a vector containing their products
	// want a vector since we know that duplicate items can exist >> not a set or map
	std::map<User, std::vector<Product>> carts;
	double creditAmount_;
	int userType_;
};

#endif