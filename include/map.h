#ifndef _MAP_H
#define _MAP_H

#include <unordered_map>
#include <vector>
#include <string>
#include "container.h"
#include "items.h"
#include "room.h"

/* Map class
 *
 * This class represents a list of rooms.  It also keeps track of the player's
 * current position and holds the player's inventory.
 *
 * The player's position starts at room 1. */
class Map : public Container
{
public:
	Map();

	/*-----------------------*\
	| Methods for general use |
	\*-----------------------*/

	/* Gets the name of the current room */
	string get_room_name();

	/* Gets the description of the current room */
	string get_room_description();

	/* Gets a vector of exit names from the current room */
	std::vector<std::string>&& get_exit_names();

	/* Move through an exit and prints name and description of new room.
	 * Returns false if exit or destination does not exist. */
	bool use_exit(std::string &exit_name);

	/* Pick up an item from the room */
	bool get_item(std::string &item_name);

	/* Drop an item */
	bool drop_item(std::string &item_name);

	/*----------------------------------------*\
	| Methods for adding or manipulating rooms |
	\*----------------------------------------*/

	/* Moves the player.  The version taking a string will compare
	 * lowercased versions of the room name and the argument. */
	bool relocate_player(int room_num);

	/* Gets the current Room object */
	Room &get_current_room();

	/* Adds a room to the map.  Returns false if room cannot be added */
	bool add_room(int room_num, std::string &room_name,
		      std::string &description);

	/* Adds an item to a room */
	void add_item_to_room(int room_num, Item &item);
	void add_item_to_room(int room_num, Item &&item);

	/*----------------------*\
	| Accessors and Mutators |
	\*----------------------*/

	/* Accessors */
	int get_current_location();

	/* Mutators */
	void set_current_location(); /* Does not do sanity checks -
					use get_current_room */
private:
	int current_location;
	std::unordered_map<int, Room> rooms;
};

#endif /* _MAP_H */

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End:
