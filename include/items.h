/* items.h
 *
 * Classes and functions for storing and manipulating items
 */

#ifndef _ITEMS_H
#define _ITEMS_H

#include <string>

using std::string;

/* Types of items */
enum item_type
{
	WEAPON,
	TOOL,
	SHIRT,
	JACKET,
	PANTS,
	SOCKS,
	SHOES
};

enum weapon_type
{
	PIERCING,
	SLASHING,
	BLUDGEONING,
	PROJECTILE
};

class Item
{
public:
	Item();
	Item(string name, string description, int encumberance, item_type type);
	~Item();

	string use();
	string use(Item direct_object);

	void set_name(string name);
	void set_description(string description);
	void set_encumberance(string encumberance);
	void set_item_type(item_type type);

	string get_name();
	string get_description();
	int get_encumberance;
	item_type get_item_type();
protected:
	string name;
	string description;
	int encumberance;
	item_type type;
};

class Weapon : public Item
{
public:
	Weapon();
	Weapon(string name, string description, int encumberance,
	       item_type type, weapon_type wtype, int damage,
	       int clip_size);
private:
	weapon_type wtype;
	int damage;
	int clip_size;
};

#endif /* _ITEMS_H */
