#include <string>
#include <set>
#include <vector>

#include "mydatastore.h"

using namespace std;

myDataStore::myDataStore () {

}

void myDataStore::addProduct(Product* p) {
	products_.push_back(p);
}

/**
 * Adds a user to the data store
 */
void myDataStore::addUser(User* u) {
	users_.insert(u);
	// do we need to add credit amount and user type
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
vector<Product*> myDataStore::search(vector<string>& terms, int type) {

	vector<Product*> searchProducts;
	vector<Product*>::iterator itProducts;
	vector<string>::iterator it;
	set<string> getKeywords;
	set<string> getProdKeywords;
	for (it = terms.begin(); it != terms.end(); it++) {
			getKeywords.insert(*it);		
		}
	if (type == 0) {
		// do AND search 
		// for the set of products, we want to go through all of them and look through their keywords
		// if all keywords match, we add the product to the vector<product>
		// turn terms into a set of keywords
		// use setIntersect with keywords from products
		// if setIntersect returns a set that is exactly the same as the keywords set
		// add that product
		
		set<string> compareIntersection;
		for (itProducts = products_.begin(); itProducts != products_.end(); itProducts++) {
			getProdKeywords = (**itProducts).keywords();
			compareIntersection = setIntersection(getKeywords, getProdKeywords);
			if (compareIntersection == getKeywords) {
				searchProducts.push_back(*itProducts);
			}
		}
		// i think AND search is complete
		
	}
	else if (type == 1) {
		// do OR search
		// only needs one of the keywords to work
		set<string> compareIntersection;
		for (itProducts = products_.begin(); itProducts!= products_.end(); itProducts++) {
			getProdKeywords = (**itProducts).keywords();
			// want to check if at least one intersects
			compareIntersection = setIntersection(getKeywords, getProdKeywords);
			if (compareIntersection.size() >= 1) {
				searchProducts.push_back(*itProducts);
			}
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
	vector<Product*>::iterator itProducts;
	for (itProducts = products_.begin(); itProducts != products_.end(); itProducts++) {
		(**itProducts).dump(ofile);
	}
	ofile << "</products>\n";

	// then dump list of users
	ofile << "<users>\n";
	set<User*>::iterator itUsers;
	for (itUsers = users_.begin(); itUsers != users_.end(); itUsers++) {
		// added const keyword to user.h and user.cpp to make function below work
		// not sure why the user object was const even after looking through user.h and user.cpp
		// casted away const keyword to use function
		(**itUsers).dump(ofile);
	}
	ofile << "</users>\n";

}

void myDataStore::addToCart(User* u, Product* p) {
	vector<Product*> tempCart;
	if (carts_.find(u) == carts_.end()) {
		tempCart.push_back(p);
		carts_.insert({u, tempCart});
	}
	else if (carts_.find(u) != carts_.end()) {
		carts_[u].push_back(p);
	}
}

void myDataStore::viewCart(User* u) {
	int itemNo = 1;
	vector<Product*> temp = carts_[u];
	for (int i = 0; i < (int) temp.size(); i++) {
		cout << "Item " << itemNo << endl;
		temp[i]->displayString();
		itemNo++;
	}
}

// want BUYCART
// find vector products
// check pricing and if user has enough money
// also check if item is in stock
// make sure to deduct money from user
// also deduct quantity from products using subtractQty()
// also remove product from cart as well
// if item is not in stock or user does not have enough money, leave it in cart and move onto next product
void myDataStore::buyCart(User* u) {
	double userBalance = u->getBalance();
	double productPrice;

	// for (int i = 0; i < carts_[u].size(); i++) {
	// 	// want to check if we have enough money and if the quantity is greater than one
	// 	productPrice = carts_[u][i]->getPrice();
	// 	if (userBalance >= carts_[u][i]->getPrice() && carts_[u][i]->getQty() >= 1) {
	// 		u->deductAmount(productPrice);
	// 		carts_[u][i]->subtractQty(1);
	// 		carts_[u].erase(carts_[u].begin() + i);
	// 		i--;

	// 	}
	// }

	vector<Product*>::iterator it = carts_[u].begin();
	while (it != carts_[u].end()) {
		productPrice = (*it)->getPrice();
		if (userBalance >= (*it)->getPrice() && (*it)->getQty() >= 1) {
			u->deductAmount(productPrice);
			(*it)->subtractQty(1);
			carts_[u].erase(it);
		}
		else {
			it++;
		}
	}

}