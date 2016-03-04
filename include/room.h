#ifndef _ROOM_H
#define _ROOM_H

#include <unordered_map>
#include <vector>
#include <string>

class Room
{
public:
	Room();
	Room(std::string &name, std::string &description);
	~Room();

	void set_name(std::string &name);
	void set_description(std::string &description);

	std::string get_name();
	std::string get_description();
	std::vector<std::string>&& get_exits();
private:
	std::string name;
	std::string description;
	std::unordered_map<std::string direction, Room *> exits;
	/* Put a container in here */
}

#endif /* _ROOM_H */
