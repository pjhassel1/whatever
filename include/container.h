#ifndef _CONTAINER_H
#define _CONTAINER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "items.h"

/* Container class
 *
 * Holds any number of items.  This uses move semantics to avoid copying.
 *
 * Not to be confused with container classes.
 */
class Container
{
public:
	Container();

	/* Return an unordered map of item names and numbers */
	std::unordered_map<std::string, int> get_item_list();

	/* Add an item to the container */
	void add_item(Item& item);
	void add_item(Item&& item);

	/* Returns item number of given item name.
	 * Returns -1 if item is not in container. */
	int get_item_num_by_name(const std::string &item_name);

	/* Move an item from one container to another. *
	 * Returns false if the move doesn't happen    */
	bool move_item(Container &to, const int item_num);
	bool move_item(Container &to, const std::string item_name);

	/* Destroys an item */
	bool destroy_item(const int item_num);
	bool destroy_item(const std::string item_name);

	/* Returns true if item is in container.  Also searches aliases.
	 * String search is case insensitive. */
	bool has_item(const int item_num);
	bool has_item(const std::string item_name);

	/* Get a pointer to an item.             *
	 * Returns nullptr if item is not found. */
	Item *get_item_ptr(const int item_num);
private:
	std::vector<Item> items;
};

#endif /* _CONTAINER_H */

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End:
