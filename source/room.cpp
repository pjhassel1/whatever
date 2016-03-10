#include <iostream>
#include "../include/room.h"

using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::unordered_map;
using std::cout;
using std::endl;

Room::Room()
{
	room_number = -1;
	name = "Undefined Room";
	description = "This place is vague.";
}

Room::Room(int room_num, const string room_name, const string room_description) :
	room_number(room_num), name(room_name), description(room_description)
{
}

Room::Room(int room_num, const char *room_name, const char *room_description)
{
	room_number = room_num;
	name = room_name;
	description = room_description;
}

vector<string>
Room::get_exit_names()
{
	vector<string> room_exits;
	for (auto m : exits) {
		room_exits.push_back(m.first);
	}

	return room_exits;
}

int
Room::get_exit_room_number(string &exit_name)
{
	int exit_num {-1};

	for (auto m : exits)
		if (m.first == exit_name)
			exit_num = m.second;

	return exit_num;
}

bool
Room::add_exit(string &exit_name, int destination)
{
	pair<string, int> room_entry (exit_name, destination);
	auto retvalue = exits.insert(room_entry);

	if (retvalue.second)
		return true;
	else
		return false;
}

bool
Room::remove_exit(string &exit_name)
{
	auto retvalue = exits.erase(exit_name);
	if (retvalue > 0)
		return true;
	else
		return false;
}

void
Room::look()
{
	cout << endl << name << endl;
	cout << description << endl;
}

/* Accessors */

int
Room::get_room_num()
{
	return room_number;
}

string
Room::get_name()
{
	return name;
}

string
Room::get_description()
{
	return description;
}

/* Mutators */

void
Room::set_room_num(int room_num)
{
	room_number = room_num;
}

void
Room::set_name(string &room_name)
{
	name = room_name;
}

void Room::set_description(string &room_description)
{
	description = room_description;
}
