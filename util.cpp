#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
/* Complete the parseStringToWords() in util.cpp according to the specification given above for taking a string
of many words and splitting them into individual keywords (split at punctuation, with at least 2 character words)*/
std::set<std::string> parseStringToWords(string rawWords)
{

    string::iterator it;
    set<string> keywords;
    string temp;
    // want to iterate through string
    for (it = rawWords.begin(); it != rawWords.end(); it++) {
        // want to split at punctuation
        if (*it == " " || *it == "'" || *it == ".") {
            if (temp.length() < 2) {
                // want to clear string if keyword isn't sufficient length
                temp.clear();
            }
        }
        else if (*it != " ") {
            
        }
    }

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
