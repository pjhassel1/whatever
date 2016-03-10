/* items.cpp
 *
 * Classes and functions for storing and manipulating items
 */

#include <vector>
#include <string>
#include <iostream>
#include "../include/items.h"
#include "../include/utility.h"


using std::string;
using std::vector;

/**************
 * Item Class *
 **************/

int Item::num_items {0};

/* Default constructor */
Item::Item()
{
	name = "Uninitialized Item";
	description = "This is an uninitialized object.";
	fail_message = "You can't use that here.";
	encumberance = 0;
	type = TOOL;

	item_num = Item::num_items;
	Item::num_items++;
}

/* Regular constructor */
Item::Item(const string &item_name, item_type itype) :
	name(item_name), type(itype)
{
	description = "It looks kind of thingish.";
	fail_message = "You can't use that here.";
	encumberance = 1;

	item_num = Item::num_items;
	Item::num_items++;
}

/* Copy constructor */
// Item::Item(Item& rhs)
// {
// 	name = rhs.name;
// 	description = rhs.description;
// 	fail_message = rhs.fail_message;
// 	encumberance = rhs.encumberance;
// 	type = rhs.type;
// }

/* Move constructor */
// Item::Item(Item&& rhs)
// {
// 	name = rhs.name;
// 	description = rhs.description;
// 	fail_message = rhs.fail_message;
// 	encumberance = rhs.encumberance;
// 	type = rhs.type;
// }

string
Item::use()
{
	return fail_message;
}

int
Item::get_next_item_num()
{
	return Item::num_items;
}

void
Item::add_alias(const string &alias)
{
	aliases.push_back(alias);
}

bool
Item::is_item_name(const string &token)
{
	string item_name = str_lc(token);
	bool retval = false;

	for (auto s : aliases) {
		if (str_compare(s, item_name)) {
			retval = true;
			break;
		}
	}

	return retval;
}

void
Item::look()
{
	std::cout << word_wrap(description) << std::endl;
}

/* Accessors */

int
Item::get_item_num() const
{
	return item_num;
}

string
Item::get_name() const
{
	return name;
}

string
Item::get_description() const
{
	return description;
}


string
Item::get_fail_message() const
{
	return fail_message;
}
int
Item::get_encumberance() const
{
	return encumberance;
}

item_type
Item::get_item_type() const
{
	return type;
}

/* Mutators */

void
Item::set_name(const string &item_name)
{
	name = item_name;
}

void
Item::set_description(const string &item_description)
{
	description = item_description;
}

void
Item::set_fail_message(const string &item_fail_msg)
{
	fail_message = item_fail_msg;
}

void
Item::set_encumberance(const int item_encumberance)
{
	encumberance = item_encumberance;
}

void
Item::set_item_type(const item_type itype)
{
	type = itype;
}


/****************
 * Weapon Class *
 ****************/

Weapon::Weapon() : Item()
{
	type = WEAPON;
	wtype = PIERCING;
	damage = 1;
	ammo_remaining = 0;
}

Weapon::Weapon(const string &wep_name, weapon_type wep_type) :
	Item(wep_name, WEAPON), wtype(wep_type)
{
	damage = 1;
	ammo_remaining = 0;
}

// Weapon::Weapon(Weapon &rhs)
// {
// 	name = rhs.name;
// 	description = rhs.description;
// 	fail_message = rhs.fail_message;
// 	encumberance = rhs.encumberance;
// 	type = rhs.type;
// 	wtype = rhs.wtype;
// 	damage = rhs.damage;
// 	ammo_remaining = rhs.ammo_remaining;
// }

void
Weapon::load(int num_projectiles)
{
	ammo_remaining += num_projectiles;
}

/* Accessors */
weapon_type
Weapon::get_weapon_type() const
{
	return wtype;
}

int
Weapon::get_damage() const
{
	return damage;
}

int
Weapon::get_ammo_remaining() const
{
	return ammo_remaining;
}

/* Mutators */
void
Weapon::set_weapon_type(const weapon_type wep_type)
{
	wtype = wep_type;
}

void
Weapon::set_damage(const int wep_damage)
{
	damage = wep_damage;
}

void
Weapon::set_ammo_remaining(const int wep_ammo_remaining)
{
	ammo_remaining = wep_ammo_remaining;
}
