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
	std::unordered_map<string, int> get_item_list();

	/* Add an item to the container */
	void add_item(Item& item);
	void add_item(Item&& item);

	/* Move an item from one container to another. *
	 * Returns false if the move doesn't happen    */
	bool move_item(Container &to, const int item_num);

	/* Destroys an item */
	bool destroy_item(const int item_num);

	/* Returns -1 if item cannot be found */
	bool has_item(const int item_num);

	/* Get a pointer to an item.             *
	 * Returns nullptr if item is not found. */
	Item *get_item_ptr(const int item_num);
private:
	std::vector<Item> items;
};

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End: