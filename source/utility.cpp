#include "../include/utility.h"

#define CONSOLE_WIDTH 80

using std::string;
using std::cout;
using std::cin;

string
word_wrap(string paragraph)
{
	auto it = paragraph.begin();
	auto last_newline_it = paragraph.begin();

	if (paragraph.length() < CONSOLE_WIDTH)
		return paragraph;

	while (paragraph.end() - it > CONSOLE_WIDTH) {
		last_newline_it = it;
		it += CONSOLE_WIDTH;

		while (*it != ' ' && it > last_newline_it)
			it--;

		/* If we couldn't find a space, go forward until the next
		 * space */
		if (it == last_newline_it) {
			it += CONSOLE_WIDTH;
			while (*it != ' ' && it != paragraph.end())
				it++;

			if (it == paragraph.end())
				/* EXIT POINT HERE */
				return paragraph;
		}

		*it = '\n';
	}

	return paragraph;
}
