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
	set<Product>::iterator itProducts;
	vector<string>::iterator it;
	set<string> getKeywords;
	if (type == 0) {
		// do AND search 
		// for the set of products, we want to go through all of them and look through their keywords
		// if all keywords match, we add the product to the vector<product>
		itProducts = products_.begin();
		for (it = terms.begin(); it != terms.end(); it++) {
			getKeywords = (*itProducts).keywords();

		}
		
	}
	else if (type == 1) {
		// do OR search
		// only needs one of the keywords to work
		itProducts = products_.begin();
		for (it = terms.begin(); it != terms.end(); it++) {
			getKeywords = (*itProducts).keywords();
			getKeywords.find(*it);
		}
	}

	return searchProducts;

}

/**
 * Reproduce the database file from the current Products and User values
 */
void myDataStore::dump(ostream& ofile) {
	
	ofile << "<products>\n";
	// dump list of products first
	set<Product>::iterator itProducts;
	for (itProducts = products_.begin(); itProducts != products_.end(); itProducts++) {
		(*itProducts).dump(ofile);
	}
	ofile << "</products>\n";

	// then dump list of users
	ofile << "<users>\n";
	set<User>::iterator itUsers;
	for (itUsers = users_.begin(); itUsers != users_.end(); itUsers++) {
		// added const keyword to user.h and user.cpp to make function below work
		// not sure why the user object was const even after looking through user.h and user.cpp
		// casted away const keyword to use function
		const_cast<User&>(*itUsers).dump(ofile);
	}
	ofile << "</users>\n";

}