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
	virtual ~myDataStore() { }

    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product* p) = 0;

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User* u) = 0;

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type) = 0;

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream& ofile) = 0;
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