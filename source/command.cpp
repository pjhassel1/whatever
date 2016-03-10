#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../include/command.h"
#include "../include/utility.h"
#include "../include/room.h"
#include "../include/items.h"
#include "../include/config.h"

using std::string;
using std::unordered_map;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

void
run_repl(Map &map)
{
	string input_line;
	string command;
	vector<string> tokens;

	bool quit { false };

	while (! quit) {
		cout << "> ";
		getline(cin, input_line);

		if (cin.bad()) {
			cout << "An error occurred." << endl;
			return;
		} else if (cin.eof()) {
			/* Received EOF, probably ^D */
			return;
		} else if (cin.fail()) {
			cout << "Input failed, exiting." << endl;
		}

		tokens = tokenize(input_line);

		if (tokens.size() < 1) {
			continue;
		}

#ifdef DEBUG
		for (auto tok : tokens) {
			cout << tok << endl;
		}
#endif
		/* Get rid of go, we just search for directions */
		if (str_compare(tokens.front(), "go"))
			tokens.erase(tokens.begin());

		command = tokens.front();
		tokens.erase(tokens.begin());

		/* Get rid of articles */
		for (auto t = tokens.begin(); t != tokens.end(); ++t) {
			if (str_compare(*t, "the") ||
			    str_compare(*t, "a")   ||
			    str_compare(*t, "an")) {

				tokens.erase(t);
			}
		}

		/* Exit commands */
		if (str_compare(command, "quit") ||
		    str_compare(command, "exit") ||
		    str_compare(command, "bye")  ||
		    str_compare(command, "goodbye"))
			return;

		/* Help */
		if (str_compare(command, "help") ||
			str_compare(command, "?")) {
			print_help();
			continue;
		}

		/* Movement commands */

		if (str_compare(command, "n")) {
			command = "north";
		}

		if (str_compare(command, "s")) {
			command = "south";
		}

		if (str_compare(command, "e")) {
			command = "east";
		}

		if (str_compare(command, "w")) {
			command = "west";
		}

		if (str_compare(command, "u")) {
			command = "up";
		}

		if (str_compare(command, "d")) {
			command = "down";
		}

		for (auto e : map.get_current_room().get_exit_names()) {
			if (e == command) {
				move(map, command);
				continue;
			}
		}

		if (str_compare(command, "north") ||
		    str_compare(command, "south") ||
		    str_compare(command, "east")  ||
		    str_compare(command, "west")  ||
		    str_compare(command, "up")    ||
		    str_compare(command, "down")) {
			move(map, command);
			continue;
		}

		/* Easter egg, don't tell anyone! */
		if (str_compare(command, "hello")) {
			if (tokens.size() > 0 &&
			    str_compare(tokens[0], "sailor"))
				cout << "Nothing happens here." << endl;
			else
				cout << "Hello!" << endl;
			continue;
		}

		/* Regular commands */
		if (str_compare(command, "look") ||
		    str_compare(command, "l")) {
			look(map, tokens);
			continue;
		} else if (str_compare(command, "open")) {
			open(map, tokens[0]);
			continue;
		} else if (str_compare(command, "get")) {
			get(map, tokens[0]);
			continue;
		} else if (str_compare(command, "drop")) {
			drop(map, tokens[0]);
			continue;
		} else if (str_compare(command, "use")) {
			use(map, tokens);
			continue;
		} else if (str_compare(command, "inv") ||
			   str_compare(command, "inventory")) {
			inventory(map);
			continue;
		}

		cout << "I didn't understand that." << endl;
	}
}

void
look(Map &map, vector<string> args)
{
	/* If we look at the room */
	if (args.size() == 0) {
		map.get_current_room().look();
		return;
	}

	/* Get rid of "at" */
	if (str_compare(args[0], "at")) {
		args.erase(args.begin());
	}

	if (args.size() == 0) {
		cout << "Look at what?" << endl;
		return;
	}

	/* Look at an item in our inventory */
	for (auto i : map.get_item_list()) {
		if (str_compare(args[0], i.first)) {
			cout << map.get_item_ptr(i.second)->get_description()
			     << endl;
			return;
		}
	}

	/* Look at an item in the room */
	for (auto i : map.get_current_room().get_item_list()) {
		if (str_compare(args[0], i.first)) {
			cout << map.get_current_room().get_item_ptr(i.second)
				->get_description() << endl;
			return;
		}
	}

	/* Nothing found */
	cout << "You don't see that here." << endl;
}

void
move(Map &map, string direction)
{
	if (! map.use_exit(direction))
		cout << "You can't go that way." << endl;
}

void
open(Map &map, string container)
{
	/* Will be used later */
}

void
close(Map &map, string container)
{
	/* Will be used later */
}

void
get(Map &map, string item_name)
{
	/* Do we already have it? */
	if (map.has_item(item_name)) {
		cout << "You already have that!" << endl;
		return;
	}

	/* Is it in the room? */
	if (! map.get_current_room().has_item(item_name)) {
		cout << "You can't see that here." << endl;
		return;
	}

	/* Try to pick it up */
	if (map.get_item(item_name)) {
		cout << "Taken." << endl;
	} else {
		cout << "You can't pick that up." << endl;
	}
}

void
drop(Map &map, string item_name)
{
	if (map.drop_item(item_name)) {
		cout << "Dropped." << endl;
	} else {
		cout << "You don't have one of those!" << endl;
	}

}

void
use(Map &map, vector<string> args)
{
	if (args.size() == 0) {
		cout << "Do what with what?" << endl;
		return;
	}

	/* Room specific stuff for non-items goes here, i.e. wall switch */

	/* Everything else requires we have the item or that the item is in the
	 * room.  We take the item if it's in the room. */
	if (map.get_current_room().has_item(args[0])) {
		if (map.get_item(args[0]))
			cout << "(Taken)" << endl;
		else {
			cout << "You can't pick that up." << endl;
			return;
		}
	}

	/* Item is either in our inventory or not at this point. */
	if (! map.has_item(args[0])) {
		cout << "You don't have that." << endl;
		return;
	}

	/* Room specific item stuff goes here, i.e. card */

	/* Non-room specific item stuff goes here */

	/* Item fail message */
	map.get_item_ptr(map.get_item_num_by_name(args[0]))->use();
}

void
inventory(Map &map)
{
	unordered_map<string, int> item_list = map.get_item_list();

	if (item_list.size() == 0) {
		cout << "You are not carrying anything." << endl;
	} else {
		cout << "You are carrying:" << endl;
		for (auto i : item_list) {
			cout << "  " << i.first << endl;
		}
	}
}

void
print_help()
{
	cout << "           +----------+" << endl;
	cout << "Welcome to | WHATEVER |, the poorly named text adventure!"
	     << endl;
	cout << "           +----------+" << endl;
	cout << endl;
	cout << "You play this game by entering commands in the form" << endl;
	cout << "of one or more words." << endl;
	cout << endl;
	cout << "Example commands:" << endl;
	cout << "  north" << endl;
	cout << "  get cake" << endl;
	cout << "  drop knife" << endl;
	cout << "  use flyswatter" << endl;
	cout << "  open cupboard" << endl;
	cout << "  inventory" << endl;
	cout << endl;
	cout << "The goal is to escape!  Good luck!" << endl;
}
