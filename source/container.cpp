#include <utility>
#include "../include/container.h"

using std::string;
using std::vector;

Container::Container() { }

void
Container::add_item(Item &item)
{
	items.push_back(item);
}

void
Container::add_item(Item &&item)
{
	items.push_back(item);
}

bool
Container::move_item(Container &to, const int item_num)
{
	vector<Item>::iterator it;
	for (it = items.begin(); it != items.end(); it++) {
		if (it->get_item_num() == item_num) {
			to.add_item(std::move(*it));
			items.erase(it);
			return true;
		}
	}

	return false;
}

bool
Container::destroy_item(const int item_num)
{
	vector<Item>::iterator it;
	for (it = items.begin(); it != items.end(); it++) {
		if (it->get_item_num() == item_num) {
			items.erase(it);
			return true;
		}
	}

	return false;
}

bool
Container::has_item(const int item_num)
{
	vector<Item>::iterator it;
	for (it = items.begin(); it != items.end(); it++) {
		if (it->get_item_num() == item_num)
			return true;
	}

	return false;
}

Item*
Container::get_item_ptr(const int item_num)
{
	vector<Item>::iterator it;
	for (it = items.begin(); it != items.end(); it++) {
		if (it->get_item_num() == item_num)
			/* C++ is really stupid sometimes */
			return &*it;
	}


	return nullptr;
}
