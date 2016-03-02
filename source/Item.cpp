/* items.cpp
 *
 * Classes and functions for storing and manipulating items
 */

#include <vector>
#include <string>
#include "../include/items.h"


using std::string;
using std::vector;

/**************
 * Item Class *
 **************/

Item::Item()
{
	name = "Uninitialized Item";
	description = "This is an uninitialized object.";
	encumberance = 0;
	type = TOOL;
}

Item::Item(const string &item_name, const string &item_description,
	   const string &item_fail_msg, int item_encumberance,
	   item_type itype) :
	name(item_name), description(item_description),
	fail_message(item_fail_msg), encumberance(item_encumberance),
	type(itype)
{
}

string
Item::use()
{
	return fail_message;
}

string
Item::use(Item direct_object)
{
	return fail_message;
}

/* Accessors */

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
set_name(const string &item_name)
{
	name = item_name;
}

void
set_description(const string &item_description)
{
	description = item_description;
}

void
set_fail_message(const string &item_fail_msg)
{
	fail_message = item_fail_msg;
}

void
set_encumberance(int item_encumberance)
{
	encumberance = item_encumberance;
}

void
set_item_type(item_type itype)
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
	clip_size = 0;
}

Weapon::Weapon(const string &wep_name, const string &wep_description,
	       const string &wep_fail_msg, int wep_encumberance,
	       weapon_type wep_type, int wep_damage, int wep_clip_size) :
	Item(weapon_name, weapon_description, weapon_fail_msg, encumberance,
	     WEAPON),
	wtype(wep_type), damage(wep_damage), clip_size(wep_clip_size)
{
}
