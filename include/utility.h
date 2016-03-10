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
// void look(Map &map_obj);

/*
 * Utility functions
 */

/* Inserts line breaks to word wrap a string */
std::string word_wrap(std::string paragraph);

/* Splits a string on spaces and returns a vector of words */
std::vector<std::string> tokenize(std::string);

/* Converts a string to lowercase.  First returns a string, second performs
 * conversion in place. */
std::string str_lc(std::string str);

void str_lc_ref(std::string &str);

/* Compares two strings in a case-insensitive way.
 * Returns true if strings are identical. */
bool str_compare(std::string string_1, std::string string_2);
bool str_compare(std::string string_1, const char *string_2);
bool str_compare(const char *string_1, const char *string_2);

#endif /* _UTILITY_H */

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End:
