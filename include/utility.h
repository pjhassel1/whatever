#ifndef _UTILITY_H
#define _UTILITY_H

#include <iostream>
#include <vector>
#include <string>
#include "map.h"

/*
 * Game-centric functions
 */

/* Print name, description, exits, and items in current room */
void look(Map &map);

/*
 * Utility functions
 */

/* Inserts line breaks to word wrap a string */
std::string word_wrap(std::string paragraph);

/* Splits a string on spaces and returns a vector of words */
std::vector<std::string> tokenize(std::string);

/* Compares two strings in a case-insensitive way */
bool str_compare(std::string string_1, std::string string_2);

#endif /* _UTILITY_H */

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End:
