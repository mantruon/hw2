#include <string>
#include <set>
#include <vector>

#include "mydatastore.h"

using namespace std;

myDataStore::myDataStore () {

}

void myDataStore::addProduct(Product* p) {
	products_.insert(*p);
}

/**
 * Adds a user to the data store
 */
void myDataStore::addUser(User* u) {
	users_.insert(*u);
	// do we need to add credit amount and user type
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
vector<Product*> myDataStore::search(vector<string>& terms, int type) {

	vector<Product*> searchProducts;
	set<Product*>::iterator itProducts;
	vector<string>::iterator it;
	set<string> keywords;
	if (type == 0) {
		// do AND search 
		// for the set of products, we want to go through all of them and look through their keywords
		// if we find a matching keyword, we add the product to the vector<product>
		itProducts = products_.begin();
		for (it = terms.begin(); it != terms.end(); it++) {
			keywords = *itProducts.keywords();
			
		}
		
	}
	else if (type == 1) {
		// do OR search
		for (it = terms.begin(); it != terms.end(); it++) {
			
		}
	}

	return searchProducts;

}

/**
 * Reproduce the database file from the current Products and User values
 */
void myDataStore::dump(ostream& ofile) {
	
	// dump list of products first
	set<Product>::iterator itProducts;
	for (itProducts = products_.begin(); itProducts != products_.end(); itProducts++) {
		(*itProducts).dump(ofile);
	}

	// then dump list of users
	set<User>::iterator itUsers;
	for (itUsers = users_.begin(); itUsers != users_.end(); itUsers++) {

	}

}