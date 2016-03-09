#include "../include/map.h"

using std::string;
using std::unordered_map;

Map::Map()
{
	current_location = 1;
}

string
Map::get_room_name()
{
	return get_current_room().get_name();
}

string
Map::get_room_description()
{
	return get_current_room().get_description();
}

bool
Map::use_exit(string &exit_name)
{
	int dest = get_current_room().get_exit_room_number(exit_name);

	if (dest == -1)
		return false;
	else {
		relocate_player(dest);
		get_current_room().look();
		return true;
	}
}

bool
Map::get_item(string &item_name)
{
	return get_current_room().move_item(*this, item_name);
}

bool
Map::drop_item(string &item_name)
{
	return this->move_item(get_current_room(), item_name);
}

bool
Map::relocate_player(int room_num)
{

	unordered_map<int, Room>::iterator it;

	for (it = rooms.begin(); it != rooms.end(); it++)
		if (it->second.get_room_num() == room_num) {
			current_location = room_num;
			return true;
		}

	return false;
}

Room
&Map::get_current_room()
{
	return rooms[current_location];
}

bool
Map::add_room(int room_num, char const *room_name, char const *room_description)
{
	Room rm = Room(room_num, room_name, room_description);
	rooms.insert(std::pair<int, Room>(room_num, rm));
	// rooms.emplace(room_num, room_num, room_name, room_description);

	return true;
}

/*
void
Map::add_item_to_room(int room_num, Item &item)
{

}
*/

void
Map::add_item_to_room(int room_num, Item &&item)
{
	rooms[room_num].add_item(item);
}

int
Map::get_current_location()
{
	return 0;
}

void
Map::set_current_location()
{

}
