#ifndef _UTILITY_H
#define _UTILITY_H

#include <iostream>
#include <vector>
#include <string>
#include "map.h"

void look(Map &map);

std::string word_wrap(std::string paragraph);

std::vector<string> tokenize(std::string);

#endif /* _UTILITY_H */

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End:
