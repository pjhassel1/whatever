#include "../include/map.h"

Map::Map()
{

}

string&
Map::get_room_name()
{
	string b;

	return b;
}

string
&Map::get_room_description()
{
	string b;

	return b;
}

bool
Map::use_exit(std::string exit_name)
{
	return true;
}

bool
Map::get_item(std::string &item_name)
{
	return true;
}

bool
Map::drop_item(std::string &item_name)
{
	return true;
}

bool
Map::relocate_player(int room_num)
{
	return true;
}

Room
&Map::get_current_room()
{
	Room b;

	return b;
}

bool
Map::add_room(int room_num, std::string &room_name, std::string &description)
{
	return true;
}

void
Map::add_item_to_room(int room_num, Item &item)
{

}

void
Map::add_item_to_room(int room_num, Item &&item)
{

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
