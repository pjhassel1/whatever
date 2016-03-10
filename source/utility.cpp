#include "../include/utility.h"

#include <algorithm>

#define CONSOLE_WIDTH 80

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

void
look(Map &map)
{
	auto contents = map.get_item_list();
	auto exits = map.get_current_room().get_exit_names();

	cout << endl;
	cout << map.get_current_room().get_name() << endl;
	cout << word_wrap(map.get_current_room().get_description()) << endl;

	if (! contents.empty()) {
		cout << "You can see:" << endl;
		for (auto i : contents)
			cout << "  " << i.first << endl;
	}

	if (! exits.empty()) {
		cout << "Visible exits:" << endl;
		for (auto e : exits)
			cout << "  " << e << endl;
	}
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

bool
str_compare(string s1, string s2)
{
	std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

	return s1.compare(s2);
}
