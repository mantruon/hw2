#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

// use find() function and find what intersects
	typename std::set<T> interSet;
	typename std::set<T>::iterator it;
	// iterate through only one and use find()
	// don't need to do a second one since if it intersects after iterating through one,
	// it should be the same vice versa
	for (it = s1.begin(); it != s1.end(); it++) {
		if (s2.find(*it) != s2.end()) {
			interSet.insert(s2.find(*it));
		}
	}
	return interSet;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
// combine both sets
// iterate through both and add them to unionSet
	typename std::set<T> unionSet;
	typename std::set<T>::iterator it;
	for (it = s1.begin(); it != s1.end(); it++) {
		unionSet.insert(*it);
	}
	for (it = s2.begin(); it != s2.end(); it++) {
		unionSet.insert(*it);
	}
	return unionSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
