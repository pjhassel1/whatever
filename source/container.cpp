#include <utility>
#include <algorithm>
#include "../include/container.h"
#include "../include/utility.h"

using std::string;
using std::vector;
using std::unordered_map;

Container::Container() { }

unordered_map<string, int>
Container::get_item_list()
{
	unordered_map<string, int> retval;

	for (auto i : items) {
		retval.emplace(i.get_name(), i.get_item_num());
	}

	return retval;
}

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

int
Container::get_item_num_by_name(const string &item_name)
{
	vector<Item>::iterator it;

	for (it = items.begin(); it != items.end(); it++)
		if (it->is_item_name(item_name))
			return it->get_item_num();

	return -1;
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
Container::move_item(Container &to, const string item_name)
{
	int item_num = get_item_num_by_name(item_name);

	if (item_num == -1)
		return false;
	else
		return move_item(to, item_num);
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
Container::destroy_item(const string item_name)
{
	int item_num = get_item_num_by_name(item_name);

	if (item_num == -1)
		return false;
	else
		return destroy_item(item_num);
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

bool
Container::has_item(const string iname)
{
	string item_name = iname;
	str_lc_ref(item_name);

	int item_num = get_item_num_by_name(item_name);

	if (item_num == -1)
		return false;
	else
		return has_item(item_num);
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
