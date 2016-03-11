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
	string input_line;        /* Line read from user */
	string command;           /* Command from user */
	string subject;           /* Subject noun */
	string object;            /* Direct or propositional object */
	string preposition;       /* Preposition */

	vector<string> tokens;

	bool quit { false };

	while (! quit) {
		bool cont = false; /* used for continuing */

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

		/**********\
		|* Parser *|
		\**********/
		subject = "";
		object = "";
		preposition = "";

		/* Multi-word commands */
		if (tokens.size() > 0) {

			/* look at - just shorten to "look" */
			if (str_compare(command, "look") &&
			    str_compare(tokens[0], "at")) {
				tokens.erase(tokens.begin());
			}

			/* turn on */
			if (str_compare(command, "turn") &&
			    str_compare(tokens[0], "on")) {

				command = "turn on";
				tokens.erase(tokens.begin());
			}

			/* put in */
			if (str_compare(command, "put") &&
			    str_compare(tokens[0], "in")) {

				command = "put in";
				tokens.erase(tokens.begin());
			}
		}

		/* Find the subject */
		/* This is hacky.  Gotta find a better way. */
		if (tokens.size() > 1) {
			if ((str_compare(tokens[0], "red") ||
			     str_compare(tokens[0], "blue")) &&
			    str_compare(tokens[1], "card")) {

				subject.append(tokens[0]);
				subject.append(" ");
				subject.append(tokens[1]);

				tokens.erase(tokens.begin());
				tokens.erase(tokens.begin());

			} else if ((str_compare(tokens[0], "signature") ||
				    str_compare(tokens[0], "signet")) &&
				   str_compare(tokens[1], "ring")) {

				subject.append(tokens[0]);
				subject.append(" ");
				subject.append(tokens[1]);

				tokens.erase(tokens.begin());
				tokens.erase(tokens.begin());
			} else {
				subject = tokens[0];
				tokens.erase(tokens.begin());
			}
		} else if (tokens.size() == 1) {
			subject = tokens[0];
			tokens.erase(tokens.begin());
		}

		/* If the subject is an item, use the item name */
		if (map.has_item(subject)) {
			subject = map.get_item_ptr(
				map.get_item_num_by_name(subject))->get_name();
		}

		/* Find the preposition */
		if (tokens.size() > 1) {
			preposition = tokens[0];
			tokens.erase(tokens.begin());
		}

		/* Find the direct or prepositional object */
		if (tokens.size() > 0) {
			object = tokens[0];
			tokens.erase(tokens.begin());
		}

		/* Make sure we understand the preposition */
		if (preposition.length() > 0) {
			if (!(str_compare(preposition, "with") ||
			      str_compare(preposition, "in"))) {
				cout << "I don't get what you're trying to do."
				     << endl;
				continue;
			}
		}

#ifdef DEBUG

		cout << "Parser Debug {" << endl;
		cout << "  Command:     '" << command << "'" << endl;
		cout << "  Subject:     '" << subject << "'" << endl;
		cout << "  Preposition: '" << preposition << "'" << endl;
		cout << "  Object:      '" << object << "'" << endl;
		cout << "}" << endl;

#endif

		/**************************\
		|* Room specific commands *|
		\**************************/

		/* Put */
		if (str_compare(command, "put") ||
		    str_compare(command, "put in")) {
			if (subject.length() == 0) {
				cout << "Put what?" << endl;
				continue;
			}

			if (! map.has_item(subject)) {
				cout << "You don't have that." << endl;
				continue;
			}

			switch (map.get_current_location()) {
			case 2:
			case 3:
			case 4:
			case 6:
				cont = true;
				put(map, subject, preposition, object);
				break;
			}

			if (cont)
				continue;

			cout << "That doesn't sound like a good idea." << endl;
			continue;
		}


		/********************\
		|* General Commands *|
		\********************/

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
				cont = true;
				break;
			}
		}

		if (cont)
			continue;

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
			if (str_compare(subject, "sailor"))
				cout << "Nothing happens here." << endl;
			else
				cout << "Hello!" << endl;
			continue;
		}

		/* Regular commands */
		if (str_compare(command, "look") ||
		    str_compare(command, "l")) {
			look(map, subject);
			continue;
		} else if (str_compare(command, "open")) {
			open(map, subject);
			continue;
		} else if (str_compare(command, "get")) {
			get(map, subject);
			continue;
		} else if (str_compare(command, "drop")) {
			drop(map, subject);
			continue;
		} else if (str_compare(command, "use")) {
			use(map, subject, preposition, object);
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
look(Map &map)
{
	string empty = "";
	look(map, empty);
}

void
look(Map &map, string subject)
{
	/* If we look at the room */
	if (subject.length() == 0) {
		map.get_current_room().look();
		return;
	}

	/* Look at an item in our inventory */
	for (auto i : map.get_item_list()) {
		if (str_compare(subject, i.first)) {
			cout << map.get_item_ptr(i.second)->get_description()
			     << endl;
			return;
		}
	}

	/* Look at an item in the room */
	for (auto i : map.get_current_room().get_item_list()) {

		if (str_compare(subject, i.first)) {
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
	string empty = "";
	if (map.use_exit(direction)) {
#ifdef DEBUG
		cout << "Room #" << map.get_current_location() << " ";
#endif
		look(map, empty);
	} else
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
use(Map &map, string subject, string preposition, string object)
{
#ifdef DEBUG
	cout << "DEBUG: Enter use()" << endl;
#endif
	if (subject.length() == 0) {
		cout << "Do what with what?" << endl;
		return;
	}

	/* Room specific stuff for non-items goes here, i.e. wall switch */

	/* Everything else requires we have the item or that the item is in the
	 * room.  We take the item if it's in the room. */
	if (map.get_current_room().has_item(subject)) {
		if (map.get_item(subject))
			cout << "(Taken)" << endl;
		else {
			cout << "You can't pick that up." << endl;
			return;
		}
	}

	/* Item is either in our inventory or not at this point. */
	if (! map.has_item(subject)) {
		cout << "You don't have that." << endl;
		return;
	}

	/* Room specific item stuff goes here, i.e. card */
	if (str_compare(subject, "blue card")) {
#ifdef DEBUG
		cout << "DEBUG: Using blue card" << endl;
#endif
		if (preposition.length() == 0) {
			cout << "How do you want to use that?" << endl;
			return;
		} else if (str_compare(preposition, "in")) {
			if (str_compare(object, "slot")) {
				if (map.get_current_location() == 2) {
					map.relocate_player(4);
					look(map);
					return;
				} else if (map.get_current_location() == 3 ||
					   map.get_current_location() == 4 ||
					   map.get_current_location() == 6) {
					map.relocate_player(1);
					look(map);
					return;
				} else {
					cout << "I don't see a slot here."
					     << endl;
					return;
				}
			} else {
				cout << "I don't see how that would help."
				     << endl;
				return;
			}
		} else {
			cout << "I don't understand that." << endl;
			return;
		}
	}

	if (str_compare(subject, "red card")) {
		if (preposition.length() == 0) {
			cout << "How do you want to use that?" << endl;
			return;
		} else if (str_compare(preposition, "in")) {
			if (str_compare(object, "slot")) {
				if (map.get_current_location() == 3) {
					map.relocate_player(5);
					look(map);
					return;
				} else if (map.get_current_location() == 2 ||
					   map.get_current_location() == 4 ||
					   map.get_current_location() == 5) {
					map.relocate_player(1);
					look(map);
					return;
				} else {
					cout << "I don't see a slot here."
					     << endl;
					return;
				}
			} else {
				cout << "I don't see how that would help."
				     << endl;
				return;
			}
		} else {
			cout << "I don't understand that." << endl;
			return;
		}
	}

	/* Non-room specific item stuff goes here */

	/* Item fail message */
	map.get_item_ptr(map.get_item_num_by_name(subject))->use();
}

void
put(Map &map, string subject, string preposition, string object)
{
	if (str_compare(subject, "blue card") ||
	    str_compare(subject, "red card")) {
		use(map, subject, preposition, object);
		return;
	}

	cout << "I dont' understand" << endl;
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
