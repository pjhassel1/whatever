#ifndef _ROOM_H
#define _ROOM_H

#include <unordered_map>
#include <vector>
#include <string>
#include "container.h"

class Room : public Container
{
public:
	Room();
	/* Room number _must_ be unique! */
	Room(int room_num, const std::string name,
	     const std::string description);

	Room(int room_num, const char *name,
	     const char *description);


	/* Returns the names of the exits */
	std::vector<std::string> get_exit_names();

	/* Returns the room number an exit leads to */
	int get_exit_room_number(std::string &exit_name);

	/* Adds an exit, returns false if exit cannot be added */
	bool add_exit(std::string &exit_name, int destination_room_num);

	/* Removes an exit, returns false if exit cannot be found */
	bool remove_exit(std::string &exit_name);

	/* Prints room name and description */
	void look();

	/* Accessors */
	int get_room_num();
	std::string get_name();
	std::string get_description();

	/* Mutators */
	void set_room_num(int room_num);
	void set_name(std::string &name);
	void set_description(std::string &description);
private:
	int room_number;
	std::string name;
	std::string description;
	std::unordered_map<std::string, int> exits;
};

#endif /* _ROOM_H */

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End:
