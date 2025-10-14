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
vector<Product*> myDataStore::search(vector<std::string>& terms, int type) {

}

/**
 * Reproduce the database file from the current Products and User values
 */
void myDataStore::dump(ostream& ofile) {
	
}