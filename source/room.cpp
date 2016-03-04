#include "../include/room.h"

using std::string;
using std::vector;
using std::unordered_map;

Room::Room()
{
	name = "Undefined Room";
	description = "This place is vague.";
}

Room::Room(string &room_name, string &room_description) :
	name(room_name), description(room_description)
{
}

/* Accessors */

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

vector<string>&&
Room::get_exits()
{
	vector<string> room_exits;
	for (auto m&& : exits) {
		// room_exits.push_back()
	}
}

/* Mutators */

void
Room::set_name(string &room_name)
{
	name = room_name;
}

void Room::set_description(string &room_description)
{
	description = room_description;
}
