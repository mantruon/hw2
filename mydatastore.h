#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>

#include "datastore.h"
#include "util.h"

/* Instructions:
It is here that you will implement the core functionality of your program: searching, adding products and users, saving the database, etc.
(For search you can use the setIntersection and setUnion) functions in util.h. This class is likely where you should store products and users in some fashion.
*/
class myDataStore : public DataStore {
public:
	myDataStore();
	~myDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    void addToCart(User* u, Product* p);
    void viewCart(User* u);
    void buyCart(User* u);

	// make a set of vectors for easy find()
	std::set<User*> users_;
	std::vector<Product*> products_;
	// then make a map of users and a vector containing their products
	// want a vector since we know that duplicate items can exist >> not a set or map
	std::map<User*, std::vector<Product*>> carts_;
};

#endif