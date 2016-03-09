#include "../include/utility.h"

#define CONSOLE_WIDTH 80

using std::string;
using std::vector;
using std::cout;
using std::cin;

vector<string>
tokenize(string command)
{
	size_t begin {0};
	size_t end {1};
	vector<string> retval;

	while (end < command.length()) {
		if (command.at(end) == ' ') {
			retval.push_back(command.substr(begin, end - begin));
			begin = end + 1;
			end = begin + 1;
		}
	}

	if (command.length() > 0) {
		retval.push_back(command.substr(begin, end - begin));
	}

	return retval;
}

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
