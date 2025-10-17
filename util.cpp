#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
/* Complete the parseStringToWords() in util.cpp according to the specification given above for taking a string
of many words and splitting them into individual keywords (split at punctuation, with at least 2 character words)*/
std::set<std::string> parseStringToWords(std::string rawWords)
{

    // std::string::iterator it;
    std::set<std::string> keywords;
    std::string temp;
    std::string temptemp;
    // char tempChar;
    // want to iterate through string
    // std::cout << "Is this even working?\n";

    // want to split at punctuation
    // ' ' is for C strings and " " is for C++
    
    std::stringstream stringStream(rawWords);
    while (std::getline(stringStream, temp)) {
        size_t prev = 0;
        size_t pos;
        // found a similar way to parse string
        while ((pos = temp.find_first_of(" .,!@#$%^&*()-_+=:'", prev)) != std::string::npos) {
            if (pos > prev) {
                temptemp = convToLower(temp.substr(prev, pos-prev));
                if (temptemp.length() < 2) {
                    temptemp.clear();
                }
                keywords.insert(temptemp);
            }
            prev = pos + 1;
        }
        if (prev < temp.length()) {
            temptemp = convToLower(temp.substr(prev, std::string::npos));
            keywords.insert(temptemp);
        }
    }

    // for (it = rawWords.begin(); it != rawWords.end(); it++) {

        // std::cout << *it << std::endl;

        // if (*it != ' ' && *it != '\'') {
        //     tempChar = *it;
        //     temp += tempChar;
        // }
        
        // if (*it == ' ' || *it == '\'') {
        //     if (temp.length() < 2) {
        //             // want to clear string if keyword isn't sufficient length
        //             temp.clear();
        //     }

        //     // otherwise add the word to the set
        //     // want to double check and trim off excess whitespace
        //     temp = convToLower(temp);
        //     // std::cout << temp << std::endl;
        //     keywords.insert(temp);
        //     std::cout << temp << "\n";
        //     temp.clear();
        // }
    // }
    return keywords;
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
